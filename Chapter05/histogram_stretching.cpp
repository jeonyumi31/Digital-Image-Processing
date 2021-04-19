//5장 - 히스토그램 처리

#include <opencv2/opencv.hpp>
#include <iostream>

using namespace cv;
using namespace std;


int stretch(int x, int r1, int s1, int r2, int s2)
{
	float result;
	if (0 <= x && x <= r1) {
		result = s1 / r1 * x;
	}
	else if (r1 < x && x <= r2) {
		result = ((s2 - s1) / (r2 - r1)) * (x - r1) + s1;
	}
	else if (r2 < x && x <= 255) {
		result = ((255 - s2) / (255 - r2)) * (x - r2) + s2;
	}
	return (int)result;
}

int main()
{
	Mat image = imread("c:/sea.png");
	Mat new_image = image.clone();

	int r1, r2, s1, s2;
	cout << "input r1 : "; cin >> r1;
	cout << "input r2 : "; cin >> r2;
	cout << "input s1 : "; cin >> s1;
	cout << "input s2 : "; cin >> s2;

	for (int y = 0; y < image.rows; y++) {
		for (int x = 0; x < image.cols; x++) {
			for (int c = 0; c < 3; c++) {
				int output = stretch(image.at<Vec3b>(y, x)[c], r1, s1, r2, s2); //스트레칭은 입력화소값과 출력화소값을 변화
				new_image.at<Vec3b>(y, x)[c] = saturate_cast<uchar>(output);
			}
		}
	}
	imshow("input Image", image);
	imshow("output Imgae", new_image);
	waitKey();
	return 0;
}
