//1차 과제
//트랙바 생성 및 원그리기 과제

Mat img;
int red, green, blue;
int drawing = false;

void on_trackbar(int, void*) {}

void drawcircle(int event, int x, int y, int, void* param) {   
	if (event == CV_EVENT_LBUTTONDOWN)
		drawing = true;
	else if (event == CV_EVENT_MOUSEMOVE) {
		if (drawing == true)
			circle(img, Point(x, y), 3, Scalar(blue, green, red), 10);
	}
	else if (event == CV_EVENT_LBUTTONUP)	//L버튼 클릭시 종료
		drawing = false;

	imshow("sea_trackbar", img);
}

int main() {
	img = imread("c:/sea.png");
  
  	//예외처리
	if (img.empty()) { 
 	   cout << "no read image" << endl; 
  	   return -1; 
	} 
	
	namedWindow("img", 1);
	imshow("img", img);
	putText(img, "number_name", Point(200, 300), FONT_HERSHEY_PLAIN, 1.3, 100, 2);

	setMouseCallback("img", drawcircle);
	createTrackbar("r", "img", &red, 255, on_trackbar);
	createTrackbar("g", "img", &green, 255, on_trackbar);
	createTrackbar("b", "img", &blue, 255, on_trackbar);
 
	waitKey(0);
	return 0;
}
