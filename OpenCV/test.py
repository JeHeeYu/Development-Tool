import cv2 as cv
import numpy as np
import time
import socket
import sys

def camera_read(camera_path):
    cap = cv.VideoCapture(camera_path)
    if (cap == None):
        print("Video Read Failed!")
    else:
        print("Video Start!")
    return cap

def grayscale_converter(frame):
    return cv.cvtColor(frame, cv.COLOR_RGB2GRAY)

def color_convter(frame):
    return cv.cvtColor(frame, cv.COLOR_GRAY2BGR)

def hsv_converter(frame):
    input_frame = cv.GaussianBlur(frame, (5, 5), 0)
    return cv.cvtColor(input_frame, cv.COLOR_BGR2HSV)

def camera_on(dst, src):
    return cv.imshow(dst, src)

def canny_edge_detection(image):
    input_image = grayscale_converter(image)
    image_blur = cv.GaussianBlur(input_image, (5, 5), 0)
    canny_image = cv.Canny(image_blur, 50, 150)
    return canny_image

def yellow_mask(frame):
    hsv = hsv_converter(frame)
    lower = (0, 5, 50) 
    upper = (179, 50, 255)
    frame_mask = cv.inRange(hsv, lower, upper)
    result = cv.bitwise_and(frame, frame, mask = frame_mask)
    return result

def get_mask(img):
    img_gray = cv.cvtColor(img, cv.COLOR_BGR2GRAY)
    return cv.adaptiveThreshold(img_gray, 255, cv.ADAPTIVE_THRESH_GAUSSIAN_C, cv.THRESH_BINARY_INV, 3, 4)

def white_mask(frame):
    hsv = hsv_converter(frame)
    lower = (40, 0, 200) 
    upper = (180, 255, 255)
    frame_mask = cv.inRange(hsv, lower, upper)
    result = cv.bitwise_and(frame, frame, mask = frame_mask)
    return result

def roi_detection(image):
    image_mask = np.zeros_like(image)
    image_height = image.shape[0]
    image_width = image.shape[1]
    
    '''
    x_2(11)     y_2(1)
    
    y_1(7)    x_1(5)
    
    '''
    
    y_1 = image.shape[0] #960 480
    x_1 = image.shape[1] #540
    
    y_2 = y_1 - y_1 # 0
    x_2 = x_1 - x_1 # 0
    
    x_roi = (x_1 // 2) + 100
    y_roi = (y_1 // 2) + 50
    
    #points = np.array([[(x_2 + (x_roi), y_1), (x_2 + (x_roi), y_2 + (y_roi)), (x_1 - (x_roi), (y_2 + y_roi)), (x_1 - (x_roi), y_1)]])
    #points = np.array([[(100, image_height), (390, 350), (600, 350), (image_width-30, image_height)]])
    points = np.array([[(0, image_height), (120, 300), (520, 300), (640, image_height)]])
    cv.fillPoly(image_mask, points, 255)
    
    line_image = cv.bitwise_and(image, image_mask)
    return line_image

def draw_line(image, lines, color):
        for i in range(0, len(lines)):
            l = lines[i][0]
            cv.line(image, (l[0], l[1]), (l[2], l[3]), color, 3, cv.LINE_8)

def hough_line(frame):
    rho = 1
    theta = np.pi / 180
    threshold = 20
    minLineLength = 10
    maxLineGap = 20
    lines = cv.HoughLinesP(frame, rho, theta, threshold, minLineLength, maxLineGap)
    
    #cvt = cv.cvtColor(image, cv.COLOR_GRAY2BGR)
    #result_image = np.copy(cvt)
    #if lines is not None:   
        #draw_line(result_image, lines, color)
    
    return lines
def steer_angle(lanes):
    right_line = np.empty((0, 5), int)
    left_line = np.empty((0, 5), int)
    if lanes is not None:
        line_arr2 = np.empty((len(lanes), 5), int)

        for i in range(0, len(lanes)):
            temp = 0
            l = lanes[i][0]
            line_arr2[i] = np.append(lanes[i], np.array((np.arctan2(l[1] - l[3], l[0] - l[2]) * 180) / np.pi))

            if line_arr2[i][1] > line_arr2[i][3]:
                temp = line_arr2[i][0], line_arr2[i][1]
                line_arr2[i][0], line_arr2[i][1] = line_arr2[i][2], line_arr2[i][3]
                line_arr2[i][2], line_arr2[i][3] = temp

                
            if line_arr2[i][0] < 320 and (abs(line_arr2[i][4]) < 170 and abs(line_arr2[i][4]) > 95):
                left_line = np.append(left_line, line_arr2[i])
            elif line_arr2[i][0] > 320 and (abs(line_arr2[i][4]) < 170 and abs(line_arr2[i][4]) > 95):
                right_line = np.append(right_line, line_arr2[i])

    left_line = left_line.reshape(int(len(left_line) / 5), 5)
    right_line = right_line.reshape(int(len(right_line) / 5), 5)

    return left_line, right_line

def draw_lanes(frame, left_line, right_line):
    copy_image = np.copy(frame)

    try:
        left_line = left_line[left_line[:, 0].argsort()[-1]]
        left_degree = left_line[4]
        cv.line(copy_image, (left_line[0], left_line[1]), (left_line[2], left_line[3]), (255, 0, 0), 10, cv.LINE_AA)
    except:
        left_degree = 0
    try:
        right_line = right_line[right_line[:, 0].argsort()[0]]
        right_degree = right_line[4]
        cv.line(copy_image, (right_line[0], right_line[1]), (right_line[2], right_line[3]), (255, 0, 0), 10, cv.LINE_AA)
    except:
        right_degree = 0    

    result_image = cv.addWeighted(frame, 1, copy_image, 1, 0)

    return result_image, left_degree, right_degree

def detection_lanes(frame):
    frame_yellow = yellow_mask(frame)
    canny = canny_edge_detection(frame_yellow)
    roi_image = roi_detection(canny)
    ccan = cv.cvtColor(roi_image, cv.COLOR_GRAY2BGR)
    
    lines = hough_line(roi_image)
    left_line, right_line = steer_angle(lines)

    image, left, right = draw_lanes(frame, left_line, right_line)

    return image, left, right

#cap = cv.VideoCapture('video2.avi')
cap = camera_read('video2.avi')
#cap = cv.VideoCapture(0)
while cap.isOpened():
    ret, frame = cap.read()
    if ret:
        frame = cv.resize(frame, (640, 360))
        cv.imshow('ImageWindow', detection_lanes(frame)[0])
        l, r = detection_lanes(frame)[1], detection_lanes(frame)[2]
        

        if abs(l) <= 155 or abs(r) <= 155:
            if l ==0 or r == 0:
                if l < 0 or r < 0:
                    print('left')
                elif l > 0 or r > 0:
                    print('right')
            elif abs(l-15) > abs(r):  # 우회전 해야하는상황
                print('right')
            elif abs(r+15) > abs(l):  # 좌회전 해야하는상황
                print('left')
            else:                                   # 직진

                print('go')
        else:
            if l > 155 or r > 155:
                print('hard right')
            elif l < -155 or r < -155:
                print('hard left')

        key = cv.waitKey(1)
        if key & 0xFF == ord('q'):
            break
#cap.released()
cv.destroyAllWindows()
