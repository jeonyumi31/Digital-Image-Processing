#include <opencv2/opencv.hpp> //opencv 라이브러리 가져오기
#include <iostream> //입출력 스트림

using namespace cv;
using namespace std;

int main() {
	mat image;
	image = imread("c:/sea.jpg", imread_color); //컬러영상으로 이미지 불러오기

	if (image.empty()) {
		cout << "not read image" << endl; //불러온 이미지 영상이 null값인 경우 출력
	}
	
	imshow("sea_image", image); //불러온 이미지 출력
	waitkey(0);

	return 0;
}
