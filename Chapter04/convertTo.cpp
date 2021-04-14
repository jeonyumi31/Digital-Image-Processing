//4장 - 화소처리
//밝기 및 콘트라스트(대비) 조정

#include <opencv2/opencv.hpp>
#include <iostream>

using namespace cv;
using namespace std;

int main() {

	double alpha = 1.0;
	int beta = 0;
	Mat image = imread("C:/dolpin.jpg");
	Mat oimage, oimage2;

	cout << "Enter alpha value: [1.0-3.0]: "; cin >> alpha;	//밝기값이 어떻게 퍼지는지 결정하는 알파값
	cout << "Enter beta value: [0-100]: "; cin >> beta;	//화소에 더해지는 베타값

	image.convertTo(oimage, -1, alpha, beta); //영상밝기 증가 메소드 convertTo()
		     				  //convertTo(출력행렬, 출력행렬유형, 화소값에 곱해지는 수, 화소값에 더해지는 수)

	imshow("Original Image", image);
	imshow("New Image", oimage);

	waitKey();
	return 0;
}
