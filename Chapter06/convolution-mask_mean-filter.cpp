//6장 - 공간필터링
//컨볼루션 마스크를 이용한 평균값 필터링


#include <opencv2/opencv.hpp>
#include <iostream>

using namespace std;
using namespace cv;

int main()
{
	Mat image = imread("C:/coalla.png", IMREAD_GRAYSCALE);  //그레이스케일 영상

	float weights[] = { //가중치
		1 / 9.0F, 1 / 9.0F, 1 / 9.0F,
		1 / 9.0F, 1 / 9.0F, 1 / 9.0F,
		1 / 9.0F, 1 / 9.0F, 1 / 9.0F,
	};

	Mat mask(3, 3, CV_32F, weights);
	Mat blur;
	filter2D(image, blur, -1, mask);  //가장자리 화소처리 함수
	blur.convertTo(blur, CV_8U);  //컨볼루션 마스크를 통해 블러링

	imshow("original", image);
	imshow("blur", blur);
	waitKey(0);
	return 0;
}
