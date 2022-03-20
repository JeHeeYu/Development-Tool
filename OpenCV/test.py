import cv2 as cv
import sys
import numpy as np
import math

camera_path = "/home/jhy/workstation/object_detection/video/video.avi"
yellow_color = (0, 255, 255)
white_color = (255, 255, 255)

def camera_read(camera_path):
    cap = cv.VideoCapture(camera_path)
    if (cap == None):
        print("Video Read Failed!")
    else:
        print("Video Start!")
    return cap

def grayscale_converter(frame):
    return cv.cvtColor(frame, cv.COLOR_RGB2GRAY)

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
    lower = (30-10, 30, 30) 
    upper = (30+10, 255, 255)
    frame_mask = cv.inRange(hsv, lower, upper)
    result = cv.bitwise_and(frame, frame, mask = frame_mask)
    return result

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

    points = np.array([[(100, image_height), (390, 350), (600, 350), (image_width-30, image_height)]])
    cv.fillPoly(image_mask, points, 255)
    
    line_image = cv.bitwise_and(image, image_mask)
    return line_image

def draw_line(image, lines, color):
        for i in range(0, len(lines)):
            l = lines[i][0]
            cv.line(image, (l[0], l[1]), (l[2], l[3]), color, 3, cv.LINE_8)

def hough_line(image, color, rho, theta, threshold, min_line_length, max_line_gap):
    lines = cv.HoughLinesP(image, rho, theta, threshold, minLineLength = min_line_length, maxLineGap = max_line_gap)
    cvt = cv.cvtColor(image, cv.COLOR_GRAY2BGR)
    result_image = np.copy(cvt)
    if lines is not None:   
        draw_line(result_image, lines, color)
    
    return result_image

def drive_start(camera_path):
    cap = camera_read(camera_path)

    while(True):
        ret, cam = cap.read()
        
        
        frame_yellow = yellow_mask(cam)
        canny_yellow = canny_edge_detection(frame_yellow)
        roi_yellow = roi_detection(canny_yellow)
        line_yellow = hough_line(roi_yellow, yellow_color, 2, np.pi / 180, 90, 120, 1250)
        
        frame_white = white_mask(cam)   
        canny_white = canny_edge_detection(frame_white)
        roi_white = roi_detection(canny_white)
        line_white = hough_line(roi_white, white_color, 2, np.pi / 180, 90, 120, 1250)
        
        result_image = cv.addWeighted(line_yellow, 0.1, line_white, 0.8, 0.1, dtype=cv.CV_32F)
        
        if(ret):
            camera_on('cam', cam)
            
            camera_on('Yellow Line', result_image)
            
            print(result_image)
            
            if cv.waitKey(1) & 0xFF == 27:
                break
        
    cap.released()
    cv.destroyAllWindows()
            
drive_start(camera_path)
