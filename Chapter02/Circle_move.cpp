#include <opencv2/opencv.hpp>
#include <iostream>

using namespace cv;
using namespace std;

int main() {
	mat img;
	img= imread("c:/sea.jpg", imread_color);
	if (img.empty()) { cout << "not read image" << endl; }

	imshow("img", img); //300x300 사이즈로 이미지 출력
	int x = 300;
	int y = 300;

	while (1) {
		int key = waitkey(100);
		if (key == 'q') break;
		else if (key == 'a')
			x -= 10;
		else if (key == 'w')
			y -= 10;
		else if (key == 'd')
			x += 10;
		else if (key == 's')
			y += 10;

		circle(img, point(x, y), 200, scalar(0, 255, 0), 5);  //원을 그리고 키보드의 q, w, d, s에 따라 움직임 확인
		imshow("sea_circlemove", img);
	}
	return 0;
}
