#include <opencv2/opencv.hpp>
#include <iostream>

using namespace cv;
using namespace std;


int main() {
	Mat img1 = imread("c:/dogpin.jpg", IMREAD_GRAYSCALE);
	imshow("Original image", img1);

	Mat table(1, 256, CV_8U);

	uchar* p = table.ptr();
	for (int i = 0; i < 256; ++i) {
		p[i] = (i / 100) * 100;
	}

	Mat img2;
	LUT(img1, table, img2);

	imshow("New Image", img2);
	waitKey(0);

	return 0;
}
