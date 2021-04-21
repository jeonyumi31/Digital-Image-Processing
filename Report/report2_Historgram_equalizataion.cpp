//Software Engineering
//영상처리 - 5주차 과제
//과제명 : 이미지 평활화 및 히스토그램 각각 그리기


#include <opencv2/opencv.hpp>
#include <iostream>

using namespace std;
using namespace cv;

void drawHist(int histogram[]) {
	int hist_w = 550;
	int hist_h = 338;
	int bin_w = cvRound((double)hist_w / 256);

	Mat histImage(hist_h, hist_w, CV_8UC3, Scalar(255, 255, 255));

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
			Scalar(0, 0, 255));
	}

	imshow("Histogram_original", histImage);  //원본 영상의 히스토그램 추출
}


void drawHist2(int histogram2[]) {
	int hist_w = 550;
	int hist_h = 338;
	int bin_w = cvRound((double)hist_w / 256);

	Mat histImage(hist_h, hist_w, CV_8UC3, Scalar(255, 255, 255));

	int max = histogram2[0];
	for (int i = 1; i < 256; i++) {
		if (max < histogram2[i])
			max = histogram2[i];
	}

	for (int i = 0; i < 255; i++) {
		histogram2[i] = floor(((double)histogram2[i] / max) * histImage.rows);
	}

	for (int i = 0; i < 255; i++) {
		line(histImage, Point(bin_w * (i), hist_h),
			Point(bin_w * (i), hist_h - histogram2[i]),
			Scalar(0, 0, 255));
	}

	imshow("Histogram_equalization", histImage);  //원본 영상을 평활화한 이미지의 히스토그램 추출
}


int main()
{
	Mat src = imread("c:/air.jpg", IMREAD_GRAYSCALE);
	if (src.empty()) {
		return -1;
	}

	Mat dst;
	equalizeHist(src, dst); //원본 영상 평활화

	imshow("Image", src);
	imshow("Equalized", dst);

	int histogram[256] = { 0 }; //원본 영상
	int histogram2[256] = { 0 };  //평활화 영상

	for (int y = 0; y < src.rows; y++)
		for (int x = 0; x < src.cols; x++)
			histogram[(int)src.at<uchar>(y, x)]++;

	for (int y = 0; y < dst.rows; y++)
		for (int x = 0; x < dst.cols; x++)
			histogram2[(int)dst.at<uchar>(y, x)]++;

  //히스토그램 그리는 함수 호출
	drawHist(histogram);  
	drawHist2(histogram2);  
  
	waitKey(0);
	return 0;
}
