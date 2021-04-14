#include <opencv2/opencv.hpp>
#include <iostream>

using namespace cv;
using namespace std;

int main() {

	double alpha = 1.0;
	int beta = 0;
	Mat image = imread("C:/dolpin.jpg");
	Mat oimage, oimage2;

	cout << "Enter alpha value: [1.0-3.0]: "; cin >> alpha;
	cout << "Enter beta value: [0-100]: "; cin >> beta;

	image.convertTo(oimage, -1, alpha, beta); //영상밝기 증가 메소드 convertTo()

	imshow("Original Image", image);
	imshow("New Image", oimage);

	waitKey();
	return 0;
}
