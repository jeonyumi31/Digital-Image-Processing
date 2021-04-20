//6장 - 공간필터링

#include <opencv2/opencv.hpp>
#include <iostream>

using namespace std;
using namespace cv;

int main()
{
	Mat src = imread("C:/coalla.png", 1); //IMREAD_COLOR = "1"
	Mat dst;
	imshow("src", src);

	for (int i = 1; i < 61; i = i + 2) {
		GaussianBlur(src, dst, Size(i, i), 0, 0); //가우시안블러로 블러 구현
		imshow("Gaussian filter", dst);
		waitKey(1000);	//시간이 지남에 따라 천천히 가우시안블러 적용
	}
	return 0;
}
