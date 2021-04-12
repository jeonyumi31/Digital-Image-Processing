#include <opencv2/opencv.hpp>
#include <iostream>

using namespace cv;
using namespace std;


int main() {

	Mat src = imread("c:/sea.jpg", IMREAD_COLOR);
  
	//예외처리
	if (src.empty()) { 
		cout << "not read image" << endl; 
	}  
	
	imshow("sea_bright", src);

	while (1) { //이미지 컬러의 밝기 조절 수행
		int key = waitKeyEx();
		cout << key << " ";
		
		if (key == 'q') break;
		
		else if (key == 'a') {
			src -= 50;
		}
		
		else if (key == 'b') {
			src += 50;
		}
		
		imshow("sea_bright_2", src);
	}
	return 0;
}
