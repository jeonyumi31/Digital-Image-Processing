//6장 - 공간필터링

#include <opencv2/opencv.hpp>
#include <iostream>

using namespace std;
using namespace cv;


int main() {

	Mat src = imread("c:/coalla.png", IMREAD_COLOR);
  
	if (src.empty()) return 1;

	Mat dst;
	float weights[9] = { -1, -1, -1, -1, 9, -1, -1, -1, -1 };

	Mat mask = Mat(3, 3, CV_32F, weights);  //마스크 생성

	filter2D(src, dst, -1, mask, Point(-1, -1), 0, BORDER_DEFAULT); //OpenCV 샤프닝 메소드
	imshow("src", src);
	imshow("sharpening", dst);

	waitKey(0);
	return 0;
}
