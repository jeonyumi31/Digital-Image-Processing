//4장 - 화소처리
//논리적 영상 합성


#include<opencv/opencv2>
#include<iostream>

using name space std;
using name space 

int main() {

	Mat img, rect;

	img = imread("c:/dogpin.jpg");
  
	if (img.empty()) { 
    cout << "do not read image1" << endl;
    return -1;
  }
  
	rect = Mat::zeros(img.size(), img.type());

	rectangle(rect, Rect(100, 100, img.cols - 200, img.rows - 200), Scalar(255, 255, 255), -1); //사각형 프레임 생성하여 이미지와 합성

	Mat dst = img.clone();
  
	imshow("img", img);
	imshow("rect", rect);

	bitwise_and(img, rect, dst);  //논리곱 합수
	imshow("and image", dst);
  
	waitKey(0);
	return 0;
}
