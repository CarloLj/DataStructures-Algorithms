import cv2
import numpy as np


gaussVal = 3
kernelVal = 7
image= cv2.imread(r'FaceID_Python/CoinPractice/coins_test2.jpg')
#Turn to grey scale
gray = cv2.cvtColor(image, cv2.COLOR_BGR2GRAY)
#Blur to make the image easier to read
gauss = cv2.GaussianBlur(gray,(gaussVal,gaussVal), 0)
canny = cv2.Canny(gauss, 20, 100)

kernel = np.ones((kernelVal, kernelVal), np.uint8)
#Close holes to complete borders
close = cv2.morphologyEx(canny, cv2.MORPH_CLOSE, kernel )
#Gets the countours of the image
contours, order = cv2.findContours(close, cv2.RETR_EXTERNAL, cv2.CHAIN_APPROX_SIMPLE)

print(f"Found coins: {len(contours)}")
cv2.drawContours(image, contours, -1, (251,60,50),2)

cv2.imshow("Result", image)
cv2.imshow("gray", gray)
cv2.imshow("gauss", gauss)
cv2.imshow("canny", canny)
cv2.imshow("close", close)
cv2.waitKey(0)