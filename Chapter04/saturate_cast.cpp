#include <opencv2/opencv.hpp>
#include <iostream>

using namespace cv;
using namespace std;


int contrastEnh(int input, int x1, int y1, int x2, int y2) {
	
	double output;
	if (0 <= input && input <= x1) {
		output = (y1/x1)*input;
	}
	else if (x1 < input && input <= x2) {
		output = ((y2-y1)/(x2-x1))*(input-x1) + y1;
	}
	else if (x2 < input && input <= 255) {
		output = ((255-y2)/(255-x2))*(input-x2) + y2;
	}
	return (int)output;
}


int main() {
	
	Mat image = imread("c:/dogpin.jpg");
	Mat oimage = image.clone();

	int x1, y1, x2, y2;
	cout << "Enter x1 value : "; cin >> x1;	
	cout << "Enter y1 value : "; cin >> y1;
	cout << "Enter x2 value : "; cin >> x2;
	cout << "Enter y2 value : "; cin >> y2;

	for (int r = 0; r < image.rows; r++) {
		for (int c = 0; c < image.cols; c++) {
			for (int ch = 0; ch < 3; ch++) {
				int output = contrastEnh(image.at<Vec3b>(r,c)[ch], x1, y1, x2, y2);
				oimage.at<Vec3b>(r,c)[ch] = saturate_cast<uchar>(output);	  //최대&최소값을 제한하여 밝기를 조절하는 메소드
			}
		}
	}

	imshow("original image", image);
	imshow("New image", oimage);
	waitKey();
	return 0;
}
