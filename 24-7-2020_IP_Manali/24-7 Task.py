import cv2
import numpy as np

original=cv2.imread(r"rose_flower.jpg")
original=cv2.resize(original,(450,500))
cv2.imshow("original",original)

hsv=cv2.cvtColor(original,cv2.COLOR_RGB2HSV)
bgrl=np.array([90,0,120],np.uint8)
bgrh=np.array([215,255,255],np.uint8)

#masking
mask = cv2.inRange(original, bgrl, bgrh)
mask1= cv2.inRange(hsv,bgrl,bgrh)
cv2.imshow("masked-original", mask)
cv2.imshow("masked-hsv",mask1)

#blurring
kernel = np.array(([0, 0 ,0], [0, 1, 0], [0, 0, 1]), np.uint8)
blurred = cv2.filter2D(original,-1,kernel)
cv2.imshow("blurred",blurred)

avg=cv2.blur(original,(7,5))
cv2.imshow("Averaging",avg)

median=cv2.medianBlur(original,7)
cv2.imshow("Median Blur",median)

guass=cv2.GaussianBlur(original,(7,7),0)
cv2.imshow("Guassian Blur",guass)

bilateral=cv2.bilateralFilter(original,7,90,90)
cv2.imshow("Bilateral Filter",bilateral)

#saving outputs
cv2.imwrite("Masked-original.jpg",mask)
cv2.imwrite("Masked-hsv.jpg",mask1)
cv2.imwrite("Blurred-Original.jpg",blurred)
cv2.imwrite("Averaging.jpg",avg)
cv2.imwrite("Guassian Blur.jpg",guass)
cv2.imwrite("Median Blur.jpg",median)
cv2.imwrite("Bilateral Filter.jpg",bilateral)

#making shapes
img=cv2.imread(r"Guassian Blur.jpg")
img=cv2.resize(img,(350,400))
pts=np.array([[0,200],[225,200],[138,230],[87,230],[0,200]],np.int32)
pts = pts.reshape((-1,1,2))
img=cv2.fillPoly(img,[pts],(239,222,231))
img=cv2.circle(img,(113,315),85,(239,222,231),-1)
font=cv2.FONT_HERSHEY_COMPLEX_SMALL
cv2.putText(img,"Rose",(230,360),font,2,(0,0,0),2,cv2.LINE_AA)
cv2.imshow("shape",img)
cv2.imwrite("shape.jpg",img)

cv2.waitKey(0)
cv2.destroyAllWindows()