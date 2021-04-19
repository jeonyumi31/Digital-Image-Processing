//5장 - 히스토그램 처리

#include <opencv2/opencv.hpp>
#include <iostream>

using namespace cv;
using namespace std;

void drawHist(int histogram[]) {
	int hist_w = 512;
	int hist_h = 400;
	int bin_w = cvRound((double)hist_w / 256);

	Mat histImage(hist_h, hist_w, CV_8UC3, Scalar(255, 255, 255));  
	//히스토그램이 그려지는 영상을 RGB컬러로 지정(CV_8UC3는 RGB로 표현되는 데이터를 의미)

	int max = histogram[0];
	for (int i = 1; i < 256; i++) {
		if (max < histogram[i])
			max = histogram[i];
	}

	for (int i = 0; i < 255; i++) {
		histogram[i] = floor(((double)histogram[i] / max) * histImage.rows);
	}

	for (int i = 0; i < 255; i++) {
		line(histImage, Point(bin_w * (i), hist_h),
			Point(bin_w * (i), hist_h - histogram[i]),
			Scalar(0, 0, 255));	//붉은색 막대로 그리기
	}
	
	imshow("Histogram", histImage);
}


int main() {
	Mat src = imread("c:/sea.png", IMREAD_GRAYSCALE);	//그레이스케일 영상으로 그리기
	imshow("Input Image", src);
	int histogram[256] = { 0 };

	for (int y = 0; y < src.rows; y++)
		for (int x = 0; x < src.cols; x++)
			histogram[(int)src.at<uchar>(y, x)]++;

	drawHist(histogram);
	waitKey(0);
	return 0;
}

