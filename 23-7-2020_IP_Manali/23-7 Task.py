import cv2

img= cv2.imread(r"D:\imgs\DAY1\text.jpg", cv2.IMREAD_COLOR) #reading given image
img1= cv2.cvtColor(img,cv2.COLOR_RGB2HSV) #converting to HSV using cvtColor function
img2= cv2.cvtColor(img,cv2.COLOR_RGB2GRAY) #converting to gray using cvtColor function

#displaying original, hsv and grayscale img
cv2.imshow("original",img)
cv2.imshow("HSV",img1)
cv2.imshow("Gray",img2)


img3=cv2.resize(img,(450,450)) #resizing original img
cv2.imshow("original_resize",img3) #displaying resized img
h1,w1,c1= img.shape #gives error for grayscale image
print("Original Img Shape: ", h1 , w1, c1) #height ,width,colors
print("Original Img Size: ", img.size)
h2,w2,c2=img3.shape
print("Resized Img Shape: ", h2, w2, c2)
print("Resized Img Size: ",img3.size)


#thresholding
ret,thresh=cv2.threshold(img2,150,255,cv2.THRESH_BINARY)
cv2.imshow("Threshold Binary",thresh)
ret,thresh1=cv2.threshold(img2,150,255,cv2.THRESH_BINARY_INV)
cv2.imshow("Threshold Binary Inverted",thresh1)

imgR=cv2.resize(img2,(400,400))
#adaptive threshold
adaptive_thresh= cv2.adaptiveThreshold(imgR,255,cv2.ADAPTIVE_THRESH_MEAN_C,cv2.THRESH_BINARY,7,5)
cv2.imshow("Adaptive-Mean(Thresh binary)", adaptive_thresh)
adaptive_thresh1= cv2.adaptiveThreshold(imgR,255,cv2.ADAPTIVE_THRESH_MEAN_C,cv2.THRESH_BINARY_INV,7,5)
cv2.imshow("Adaptive-Mean(Thresh Binary Inv)", adaptive_thresh1)

adaptive_thresh2= cv2.adaptiveThreshold(imgR,255,cv2.ADAPTIVE_THRESH_GAUSSIAN_C,cv2.THRESH_BINARY,7,5)
cv2.imshow("Adaptive-Guassian(Thresh Binary)", adaptive_thresh2)
adaptive_thresh3= cv2.adaptiveThreshold(imgR,255,cv2.ADAPTIVE_THRESH_GAUSSIAN_C,cv2.THRESH_BINARY_INV,7,5)
cv2.imshow("Adaptive-Guassian(Thresh Binary Inv)", adaptive_thresh3)

#saving images
cv2.imwrite("original.jpg",img)

cv2.imwrite("HSV.jpg",img1)
cv2.imwrite("Gray.jpg",img2)

cv2.imwrite("original_resize.jpg",img3)

cv2.imwrite("Threshold Binary.jpg",thresh)
cv2.imwrite("Threshold Binary Inverted.jpg",thresh1)

cv2.imwrite("Adaptive-Mean(Thresh binary).jpg", adaptive_thresh)
cv2.imwrite("Adaptive-Mean(Thresh Binary Inv).jpg", adaptive_thresh1)
cv2.imwrite("Adaptive-Guassian(Thresh Binary).jpg", adaptive_thresh2)
cv2.imwrite("Adaptive-Guassian(Thresh Binary Inv).jpg", adaptive_thresh3)


cv2.waitKey(5000) #pass  time in milliseconds
cv2.waitKey(0) #till any key is pressed
cv2.destroyAllWindows()