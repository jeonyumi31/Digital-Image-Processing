//4장 - 화소처리

//감마보정
#include <opencv2/opencv.hpp>
#include <iostream>

using namespace cv;
using namespace std;


int main() {
	
	Mat src1, src2, dst;
	double gamma = 0.5;

	src1 = imread("C:/dogpin.jpg");
	if (src1.empty()) { cout << "no read image" << endl; return -1; }

	Mat table(1, 256, CV_8U); //미리 계산된 테이블을 통해 출력값 변경
	
	uchar* p = table.ptr();
	for (int i = 0; i < 256; ++i) {
		p[i] = saturate_cast<uchar>(pow(i / 255.0, gamma) * 255.0);	//오버플로우 방지
	}

	LUT(src1, table, dst);	//Look Up Table 
	imshow("src1", src1);
	imshow("src2", dst);
	waitKey(0);
	return 0;
}
