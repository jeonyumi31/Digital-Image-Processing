//5장 - 히스토그램 처리

#include <opencv2/opencv.hpp>
#include <iostream>

using namespace cv;
using namespace std;


int main()
{
	Mat src = imread("c:/sea.png", IMREAD_GRAYSCALE);
	if (src.empty()) {
		return -1;
	}

	Mat dst;
	equalizeHist(src, dst); //화소값의 분포를 균일하게 만드는 openCV 함수

	imshow("Image", src);
	imshow("Equalized", dst);
	waitKey(0);
	return 0;
}
