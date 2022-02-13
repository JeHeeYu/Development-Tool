import cv2
import numpy as np

image_path = 'image/test.jpg'

def image_read():
    # imread 함수는 입력 영상을 불러오는 함수로, Mat 행렬 형식으로 불러옴
    # 파이썬에서 imread 로 읽어들인 image의 리턴값은 numpy.ndarray 의 타입으로 리턴함
    return cv2.imread(image_path)

def image_show(image_name, image):
    # imshow 함수는 영상을 창으로 띄워주는 함수
    # 첫 번째 인자 : 입력 영상 경로
    # 두 번째 인자 : 영상에 띄울 영상
    cv2.imshow(image_name, image)
    
    # waitKey 함수는 imshow 함수로 띄운 창을 종료 조건을 설정할 수 있는 함수
    # 27을 줄 경우 ESC, 0을 줄 경우 모든 키 입력 등 int 형식으로 값 대입
    cv2.waitKey(0)
    return

def grayscale_converter(image):
    # cv2.cvtColor 함수는 입력 영상의 영상 색상을 변환해주는 함수
    # 첫 번째 인자 : 입력 영상
    # 두 번째 인자 : 변환 모드
    # grayscale_conver 함수는 컬러 입력 영상을 단일 색상 그레이스케일 영상으로 변경
    return cv2.cvtColor(image, cv2.COLOR_RGB2GRAY)

def gaussian_blur(image, kerner_size):
    # cv2.GaussianBlur는 가우시안 필터링을 적용하는 함수
    # 첫 번째 인자 : 입력 영상
    # 두 번째 인자 : x, y 방향으로의 커널 편차
    # 세 번째 인자 : 가장자리 픽셀 확장 방식
    return cv2.GaussianBlur(image, (kerner_size, kerner_size), 0)

def canny_edge_detection(image):
    input_image = grayscale_converter(image)
    image_blur = cv2.GaussianBlur(input_image, (5, 5), 0)
    canny_image = cv2.Canny(image_blur, 50, 150)
    return canny_image

def line_detection(image, lines):
    # lines_image 변수에 image 갯수의 배열 생성
    lines_image = np.zeros_like(image)
    if lines is not None :
        for i in range(len(lines)):
            for x1,y1,x2,y2 in lines[i]:
                cv2.line(lines_image,(x1,y1),(x2,y2),(255,0,0), 10 )
    return lines_image


def roi_detection(image):
    # np.zero_like 함수는 매개변수로 받은 크기의 배열을 배열을 생성하며, 0으로 초기화 되어 있음
    # image_mask 변수에 image 갯수의 배열 생성
    image_mask = np.zeros_like(image)
    
    # image.shape[0]은 입력 영상의 y축, shape[1]은 x축, shape[2]는 채널로, 이미지의 색상 정보를 의미함
    # image.shape[2] 는 1 = Grayscale, 3 = RGB을 나타내며, 일반적으로 RGB의 순서이지만, OpenCV 에서는 BGR 순서임
    # image.shape 시 일반적인 x-y 순서가 아닌 행렬에서의 y-x 순서로 사용함
    # image_height 변수에 입력 영상 y 크기 대입, image_width 변수에 입력 영상 x 크기 대입
    image_height = image.shape[0]
    image_width = image.shape[1]

    # 각 4개의 좌표를 담는 배열로, ROI 도형 좌표
    points = np.array([[(50, image_height), (290, 150), (400, 150), (image_width-100, image_height)]])
    
    # cv2.fillPoly 함수는 다각형을 그릴 때 사용하는 함수로, 도형 내부가 채워져 있는 도형을 만듦
    # 첫 번째 인자 : 입력 영상 파일로, image_mask가 0으로 할당된 배열이므로, 검은 화면 영상이 나타남
    # 두 번째 인자 : 도형을 그릴 x, y 좌표로, 차선 내부만 ROI로 잡을 위치로 사용
    # 세 번째 인자 : 도형의 선 색상으로, 내부 ROI 영역만 흰색(255)으로 표시
    # 이 함수는 차선 내부만 ROI로 설정하는 의미
    cv2.fillPoly(image_mask, points, 255)
    
    # return image_mask
    
    line_image = cv2.bitwise_and(image, image_mask)
    return line_image

def draw_line(image, lines, color=[255, 0, 0], thickness=10):
    for i in lines:
        for x1, y1, x2, y2 in i:
            cv2.line(image, (x1, y1), (x2, y2), color, thickness)

def hough_line(image, rho, theta, threshold, min_line_length, max_line_gap):
    line = cv2.HoughLinesP(image, rho, theta, threshold, minLineLength = min_line_length, maxLineGap = max_line_gap)
    
    image_height = image.shape[0]
    image_width = image.shape[1]
    
    line_image = np.zeros((image_height, image_width, 3))
    draw_line(line_image, line)
    
    return line_image

image = image_read()
copy_image = image.copy()

canny_edge_image = canny_edge_detection(image)

roi_detection_image = roi_detection(canny_edge_image)

line_image = hough_line(roi_detection_image, 2, np.pi/180, 90, 120, 150)

result_image = cv2.addWeighted(copy_image, 0.001, line_image, 0.8, 0.1, dtype=cv2.CV_32F)

#image_show('dst', roi_detection_image)
#image_show('dst2', line_image)
image_show('dst3', result_image)

