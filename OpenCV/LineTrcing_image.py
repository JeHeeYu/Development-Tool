import cv2

image_path = 'image/test.jpg'

# function
def image_read():
    return cv2.imread(image_path, cv2.IMREAD_GRAYSCALE)

def image_show(image_name, image):
    cv2.imshow(image_name, image)
    cv2.waitKey(0)
    return

def grayscaleConverter(img):
    return cv2.cvtColor(img, cv2.COLOR_RGB2GRAY)

def canny_edge_detection(img):
    return



# image = cv2.imread('image/test.jpg', cv2.IMREAD_GRAYSCALE)
image = image_read()
image_show('dst', image)

#cv2.imshow('dst', image)
#cv2.waitKey(0)
