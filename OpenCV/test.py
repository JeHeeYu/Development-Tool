import cv2 as cv
from matplotlib.pyplot import gray
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
    # 입력 영상을 그레이스케일 영상으로 변환
    input_image = grayscale_converter(image)
    
    # 그레이스케일로 변환된 영상에 가우시안 필터링 추가
    image_blur = cv.GaussianBlur(input_image, (5, 5), 0)
    
    # cv.Canny 함수는 캐니 에지 검출을 적용할 수 있는 함수
    # cv.Canny 함수는 넓은 범위의 에지를 검출하는데 널리 사용되는 함수
    canny_image = cv.Canny(image_blur, 50, 150)
    return canny_image

cap = camera_read()


while(True):
    ret, cam = cap.read()
    canny_cam = canny_edge_detection(cam)
    
    result_cam = cv.HoughLinesP(canny_cam, 1, np.pi/180, 50, None, 50, 10)
    
    if result_cam is not None:
        for i in range(0, len(result_cam)):
            l = result_cam[i][0]
            cv.line(canny_cam, (l[0], l[1]), (l[2], l[3]), (0, 0, 255), 3, cv.LINE_AA)
    
    if(ret):
        # GrayScale 변환 전 Camera On
        #camera_on('camera', cam)
        camera_on('graycam', canny_cam)
        camera_on('houtghcam', result_cam)
        
        if cv.waitKey(1) & 0xFF == 27:
            break
        
#cap.released()
cv.destroyAllWindows()
