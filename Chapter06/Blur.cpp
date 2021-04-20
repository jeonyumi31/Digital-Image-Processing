//6장 - 공간필터링
//블러 함수(평균값 필터링) 사용 예제

#include <opencv2/opencv.hpp>
#include <iostream>

using namespace std;
using namespace cv;

int main()
{
	Mat src = imread("C:/coalla.png");
	Mat dst;

	blur(src, dst, Size(11, 11)); 
	imshow("source", src);
	imshow("result", dst);
	waitKey(0);
	return 0;
}
