//5장 - 히스토그램 처리


#include <opencv2/opencv.hpp>
#include <iostream>

using namespace cv;
using namespace std;


int main(int argc, char** argv)
{
	Mat src = imread("c:/sea.png", IMREAD_COLOR);
	if (src.empty()) {
		return -1;
	}

	vector<Mat> bgr_planes;
	split(src, bgr_planes); //입력영상을 색상별로 분리
	int histSize = 256;
	float range[] = { 0, 256 };
	const float* histRange = { range };
	bool uniform = true, accumulate = false;
	Mat b_hist, g_hist, r_hist;

  //openCV의 히스토그램 계산함수
	calcHist(&bgr_planes[0], 1, 0, Mat(), b_hist, 1, &histSize, &histRange, uniform, accumulate); 
	calcHist(&bgr_planes[1], 1, 0, Mat(), g_hist, 1, &histSize, &histRange, uniform, accumulate);
	calcHist(&bgr_planes[2], 1, 0, Mat(), r_hist, 1, &histSize, &histRange, uniform, accumulate);


	int hist_w = 512, hist_h = 400;
	int bin_w = cvRound((double)hist_w / histSize);
	Mat histImage(hist_h, hist_w, CV_8UC3, Scalar(0, 0, 0));  

  //값들의 정규화 과정
	normalize(b_hist, b_hist, 0, histImage.rows, NORM_MINMAX, -1, Mat());
	normalize(g_hist, g_hist, 0, histImage.rows, NORM_MINMAX, -1, Mat());
	normalize(r_hist, r_hist, 0, histImage.rows, NORM_MINMAX, -1, Mat());

  
	for (int i = 0; i < 255; i++) {
		line(histImage, Point(bin_w * (i), hist_h),
			Point(bin_w * (i), hist_h - b_hist.at<float>(i)),
			Scalar(255, 0, 0));
		line(histImage, Point(bin_w * (i), hist_h),
			Point(bin_w * (i), hist_h - g_hist.at<float>(i)),
			Scalar(0, 255, 0));
		line(histImage, Point(bin_w * (i), hist_h),
			Point(bin_w * (i), hist_h - r_hist.at<float>(i)),
			Scalar(0, 0, 255));
	}

	imshow("input Image", src);
	imshow("color histogram", histImage);
	waitKey();
	return 0;
}
