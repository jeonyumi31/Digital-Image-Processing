//5장 = 히스토그램 처리

#include <opencv2/opencv.hpp>
#include <iostream>

using namespace cv;
using namespace std;

//histogram algorithm of OpenCV
int main() {
  Mat src = imread("c:/dogpin.jpg", IMREAD_GRAYSCALE);  //그레이스케일 히스토그램 
  imshow("Input Image", src);
  
  int histogram[256] = { 0 };
  
  for (int y = 0; y < src.rows; y++)
    for (int x = 0; x < src.cols; x++)
      histogram[(int)src.at<uchar>(y, x)]++;
  
  for (int count : histogram)
    cout << count << ","; //히스토그램 계산값(화소값들의 분포)을 출력
  
  waitKey(0);
  return 0;
}
