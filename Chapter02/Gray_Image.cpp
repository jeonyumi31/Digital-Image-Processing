#include <opencv2/opencv.hpp>
#include <iostream>

using namespace cv;
using namespace std;

int main() {
  
  Mat src = imread("c:/sea.jpg", IMREAD_COLOR);
  
  if (src.empty()) { 
    cout << "not read image" << endl; 
  }  //예외처리
  
  imshow("sea_src", src);
  
  Mat gray, edge, output;
  
  cvtColor(src, gray, CV_BGR2GRAY); //gray톤으로 이미지 변경
  imshow("sea_gray", gray);
  imwrite("c:/sea_gray.jpg", gray);
  
  waitKey(0);
  return 0;

}
