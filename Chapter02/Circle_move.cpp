#include <opencv2/opencv.hpp>
#include <iostream>

using namespace cv;
using namespace std;

int main() {
	Mat img;
	img= imread("c:/sea.jpg", IMREAD_COLOR);
	
	//예외처리
	if (img.empty()) { 	
		cout << "not read image" << endl; 
	}

	imshow("img", img); //300x300 size Image 출력
	int x = 300;
	int y = 300;

	while (1) {
		int key = waitKey(100);
		if (key == 'q') break;
		else if (key == 'a')
			x -= 10;
		else if (key == 'w')
			y -= 10;
		else if (key == 'd')
			x += 10;
		else if (key == 's')
			y += 10;

		circle(img, Point(x, y), 200, Scalar(0, 255, 0), 5);  //원을 그리고 키보드의 q, w, d, s에 따라 원의 움직임 확인
		imshow("sea_circlemove", img);
	}
	return 0;
}
