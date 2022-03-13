import cv2 as cv
import sys
import numpy as np
import math

def camera_read():
    cap = cv.VideoCapture(0)
    return cap

def grayscale_converter(frame):
    return cv.cvtColor(frame, cv.COLOR_RGB2GRAY)

def camera_on(dst, src):
    return cv.imshow(dst, src)

def canny_edge_detection(image):
    input_image = grayscale_converter(image)
    image_blur = cv.GaussianBlur(input_image, (5, 5), 0)
    canny_image = cv.Canny(image_blur, 50, 150)
    return canny_image

def roi_detection(image):
    image_mask = np.zeros_like(image)
    image_height = image.shape[0]
    image_width = image.shape[1]

    points = np.array([[(50, image_height), (290, 150), (400, 150), (image_width-100, image_height)]])
    cv.fillPoly(image_mask, points, 255)
    
    line_image = cv.bitwise_and(image, image_mask)
    return line_image

def draw_line(image, lines, color=[255, 0, 0], thickness=10):
        for i in range(0, len(lines)):
            l = lines[i][0]
            cv.line(image, (l[0], l[1]), (l[2], l[3]), (0, 0, 255), 3, cv.LINE_AA)

def hough_line(image, rho, theta, threshold, min_line_length, max_line_gap):
    lines = cv.HoughLinesP(image, rho, theta, threshold, minLineLength = min_line_length, maxLineGap = max_line_gap)
    cvt = cv.cvtColor(image, cv.COLOR_GRAY2BGR)
    result_image = np.copy(cvt)
    if lines is not None:   
        draw_line(result_image, lines)
    
    return result_image

def drive_start():
    cap = camera_read()

    while(True):
        ret, cam = cap.read()
        canny_cam = canny_edge_detection(cam)
        roi = roi_detection(canny_cam)
        
        hough = hough_line(roi, 1, np.pi / 180, 50, 50, 10)
        result_cam = cv.addWeighted(cam, 0.001, hough, 0.8, 0.1, dtype=cv.CV_32F)
        
        if(ret):
            camera_on('Canny Camera', hough)
            camera_on('Result Camera', result_cam)
            
            if cv.waitKey(1) & 0xFF == 27:
                break
        
    cap.released()
    cv.destroyAllWindows()
            
drive_start()
