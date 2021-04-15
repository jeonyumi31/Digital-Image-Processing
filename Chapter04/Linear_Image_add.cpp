//4장 - 화소처리
//선형 영상 합성

#include <opencv2/opencv.hpp>
#include <iostream>

using namespace cv;
using namespace std;


int main() {

	double alpha = 0.5; double beta; double input;
	Mat src1, src2, dst;

	cout << "Enter alpha value[0.0-1.0] : "; 
	cin >> input;

  //합성할 두 이미지 읽기
	src1 = imread("C:/dogpin.jpg"); 
	src2 = imread("C:/desert.jpg");

	if (src1.empty()) { cout << "do not read image1" << endl; return -1; }
	if (src2.empty()) { cout << "do not read image2" << endl; return -1; }

	beta = (1.0 - alpha);

	addWeighted(src1, alpha, src2, beta, 0.0, dst); 
           //(첫 번째 입력 영상, 첫 번째 영상의 가중치, 두 번째 입력 영상, 두 번째 영상의 가중치, 화소 합계에 더해지는 값, 출력)

	imshow("Original image1", src1);
	imshow("Original image2", src2);
	imshow("Linear Add", dst);

	waitKey(0);
	return 0;
}
