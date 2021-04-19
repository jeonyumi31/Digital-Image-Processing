//5장 - 히스토그램 처리

#include <opencv2/opencv.hpp>
#include <iostream>

using namespace cv;
using namespace std;


int main() {
	Mat src, dst;

	src = imread("c:/dogpin.jpg", IMREAD_GRAYSCALE);
	imshow("Image", src);
  
	if (!src.data) {
		return -1;
	}

	Mat threshold_image;
	//threshold(src, threshold_image, 100, 255, THRESH_BINARY); //히스토그램을 이용해 전경과 배경 분리
	threshold(src, threshold_image, 0, 255, THRESH_BINARY | CV_THRESH_OTSU);  //자동으로 임계값을 결정하여 이진화하는 방법
  
	imshow("Thresholded", threshold_image);
	waitKey(0);
	return 0;
}
