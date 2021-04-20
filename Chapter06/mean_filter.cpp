//6장 - 공간필터링
//평균값 필터링 예제 코드


#include <opencv2/opencv.hpp>
#include <iostream>

using namespace std;
using namespace cv;

int main()
{
	Mat src = imread("C:/coalla.png", IMREAD_GRAYSCALE);  //그레이스케일 영상

	Mat dst(src.size(), CV_8U, Scalar(0));
  
	if (src.empty()) {
		return -1;
	}

	for (int y = 1; y < src.rows - 1; y++) {
		for (int x = 1; x < src.cols - 1; x++) {
			int sum = 0;
			sum += src.at<uchar>(y - 1, x - 1);
			sum += src.at<uchar>(y, x - 1);
			sum += src.at<uchar>(y + 1, x - 1);
			sum += src.at<uchar>(y - 1, x);
			sum += src.at<uchar>(y, x);
			sum += src.at<uchar>(y + 1, x);
			sum += src.at<uchar>(y - 1, x + 1);
			sum += src.at<uchar>(y, x + 1);
			sum += src.at<uchar>(y + 1, x + 1);
			dst.at<uchar>(y, x) = sum / 9;
		}
	}

	imshow("original", src);
	imshow("filtering", dst);
	waitKey(0);
	return 0;
}
