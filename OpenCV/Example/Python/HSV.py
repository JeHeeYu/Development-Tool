import cv2 as cv
import numpy as np

src = cv.imread("image/hsv.jpg")

height = src[0]
width = src[1]

hsv = cv.cvtColor(src, cv.COLOR_BGR2HSV)

blue_lower = (120-10, 30, 30)
blue_upper = (120+10, 255, 255)

white_lower = (0, 0, 0)
white_upper = (0, 0, 255)

yellow_lower = (30 - 10, 35, 35)
yellow_upper = (30 + 10, 255, 255)

blue_mask = cv.inRange(hsv, blue_lower, blue_upper)
white_mask = cv.inRange(hsv, white_lower, white_upper)
yellow_mask = cv.inRange(hsv, yellow_lower, yellow_upper)

blue = cv.bitwise_and(src, src, mask = blue_mask)
yellow = cv.bitwise_and(src, src, mask = yellow_mask)
white = cv.bitwise_and(src, src, mask = white_mask)

cv.imshow("src", src)
cv.imshow("blue_mask", blue_mask)
cv.imshow("blue", blue)
cv.imshow("yellow_mask", yellow_mask)
cv.imshow("yellow", yellow)
cv.imshow("white_mask", white_mask)
cv.imshow("white", white)
cv.waitKey(0)
