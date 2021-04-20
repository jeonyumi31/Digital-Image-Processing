//6장 - 공간필터링

#include <opencv2/opencv.hpp>
#include <iostream>

using namespace std;
using namespace cv;

Mat src, src_gray;
Mat dst, detected_edges;
int edgeThresh = 1;
int lowThreshold;
int const max_lowThreshold = 100;
int kernel_size = 3;

static void CannyThreshold(int, void*)  //캐니 엣지 연산
{
	int ratio = 3;

	blur(src, detected_edges, Size(3, 3));
	Canny(detected_edges, detected_edges, lowThreshold, lowThreshold * ratio, kernel_size);  //캐니 엣지 연산
	dst = Scalar::all(0);
	src.copyTo(dst, detected_edges);
	imshow("image", src);
	imshow("Canny", dst);
}

int main()
{
	src = imread("c:/coalla.png", IMREAD_GRAYSCALE);
	if (src.empty()) {
		return -1;
	}

	dst.create(src.size(), src.type());
	namedWindow("Canny", CV_WINDOW_AUTOSIZE);
  //트랙바를 만들어 임계값을 조정해 캐니 엣지 연산 적용
	createTrackbar("Min Threshold : ", "Canny", &lowThreshold, max_lowThreshold, CannyThreshold);

	CannyThreshold(0, 0);
	waitKey(0);
	return 0;
}
