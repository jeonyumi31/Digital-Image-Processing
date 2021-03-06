//6장 - 공간필터링

#include <opencv2/opencv.hpp>
#include <iostream>

using namespace std;
using namespace cv;

int main()
{
	Mat src;
	Mat grad;
	int scale = 1;
	int delta = 0;
	src = imread("c:/coalla.png", IMREAD_GRAYSCALE);
  
	if (src.empty()) {
		return -1;
	}

	Mat grad_x, grad_y;
	Mat abs_grad_x, abs_grad_y;

  //1차 미분을 통한 엣지 검출
	Sobel(src, grad_x, CV_16S, 1, 0, 3, scale, delta, BORDER_DEFAULT);
	Sobel(src, grad_y, CV_16S, 0, 1, 3, scale, delta, BORDER_DEFAULT);

	convertScaleAbs(grad_x, abs_grad_x);  //절댓값 및 정수화 시키는 작업 수행하는 메소드
	convertScaleAbs(grad_y, abs_grad_y);
	addWeighted(abs_grad_x, 0.5, abs_grad_y, 0.5, 0, grad);
	imshow("image", src);
	imshow("Sobel", grad);
	waitKey(0);
	return 0;
}
