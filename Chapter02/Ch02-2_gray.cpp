#include <opencv2/opencv.hpp>
#include <iostream>

using namespace cv;
using namespace std;

int main() {
  
  mat src = imread("c:/sea.jpg", imread_color);
  if (src.empty()) { cout << "not read image" << endl; }
  imshow("sea_src", src);
  
  mat gray, edge, output;
  
  cvtcolor(src, gray, cv_bgr2gray);
  imshow("sea_gray", gray);
  imwrite("c:/sea_gray.jpg", gray);
  
  waitkey(0);
  return 0;

}
