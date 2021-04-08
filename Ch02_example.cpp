//#include <opencv2/opencv.hpp>
//#include <iostream>

//using namespace cv;
//using namespace std;

//int main() {
//	mat image;
//	image = imread("c:/sea.jpg", imread_color);
//
//	if (image.empty()) {
//		cout << "not read image" << endl;
//	}
//	
//	imshow("sea_image", image);
//	waitkey(0);
//
//	return 0;
//}


//int main() {
//	mat src = imread("c:/sea.jpg", imread_color);
//	if (src.empty()) { cout << "not read image" << endl; }
//	imshow("sea_src", src);
//
//	mat gray, edge, output;
//	cvtcolor(src, gray, cv_bgr2gray);
//
//	imshow("sea_gray", gray);
//	imwrite("c:/sea_gray.jpg", gray);
//	waitkey(0);
//
//	return 0;
//}


//int main() {
//	mat image = mat(400, 600, cv_8uc3, scalar(0, 0, 0));
//
//	line(image, point(100, 100), point(300, 300), scalar(0, 0, 255), 7);
//	rectangle(image, point(250, 30), point(450, 200), scalar(0, 255, 0), 5);
//	circle(image, point(100, 300), 60, scalar(255, 0, 0), 3);
//	ellipse(image, point(300, 350), point(100, 60), 45, 130, 270, scalar(255, 255, 255), 5);
//	
//	imshow("image_black", image);
//	waitkey(0);
//
//	return 0;
//}


//void onmouse(int event, int x, int y, int flags, void* param) {
//	if (event == event_lbuttondown) {
//		mat& img = *(mat*)(param);
//		circle(img, point(x, y), 200, scalar(0, 255, 0), 10);
//		puttext(img, "i found a turtle!", point(x, y + 200), font_hershey_plain, 2.0, 255, 2);
//		imshow("sea_circle", img);
//	}
//
//	else if (event == event_rbuttondown) {}
//	else if (event == event_mbuttondown) {}
//	else if (event == event_mousemove) {
//	}
//}
//
//int main() {
//	mat src = imread("c:/sea.jpg", imread_color);
//	if (src.empty()) { cout << "no read image" << endl; }
//
//	imshow("sea_circleshow", src);
//	waitkey(0);
//	return 0;
//}


//int main() {
//	mat img;
//	img= imread("c:/sea.jpg", imread_color);
//	if (img.empty()) { cout << "not read image" << endl; }
//
//	imshow("img", img);
//	int x = 300;
//	int y = 300;
//
//	while (1) {
//		int key = waitkey(100);
//		if (key == 'q') break;
//		else if (key == 'a')
//			x -= 10;
//		else if (key == 'w')
//			y -= 10;
//		else if (key == 'd')
//			x += 10;
//		else if (key == 's')
//			y += 10;
//
//		circle(img, point(x, y), 200, scalar(0, 255, 0), 5);
//		imshow("sea_circlemove", img);
//	}
//	return 0;
//}


//int main() {
//
//	mat src = imread("c:/sea.jpg", imread_color);
//	if (src.empty()) { cout << "not read image" << endl; }
//
//	imshow("sea_bright", src);
//
//	while (1) {
//		int key = waitkeyex();
//		cout << key << " ";
//		if (key == 'q') break;
//		else if (key == 'a') {
//			src -= 50;
//		}
//		else if (key == 'b') {
//			src += 50;
//		}
//		imshow("sea_bright_2", src);
//	}
//	return 0;
//}


//mat img;
//int drawing = false;
//
//void drawcircle(int event, int x, int y, int, void* param) {
//	if (event == cv_event_lbuttondown)
//		drawing = true;
//	else if (event == cv_event_mousemove) {
//		if (drawing == true)
//			circle(img, point(x, y), 3, scalar(0, 0, 255), 10);
//	}
//	else if (event == cv_event_lbuttonup)
//		drawing = false;
//	
//	imshow("sea_brushing", img);
//}
//
//int main() {
//	img = imread("c:/sea.jpg");
//	if (img.empty()) { cout << "no read image" << endl;  return -1; }
//
//	imshow("sea_image", img);
//
//	setmousecallback("image", drawcircle);
//	waitkey(0);
//	imwrite("c:/sea_brush.jpg", img);
//	return 0;
//}


//mat img;
//int red, green, blue;
//int drawing = false;
//
//void on_trackbar(int, void*) {}
//
//void drawcircle(int event, int x, int y, int, void* param) {
//	if (event == cv_event_lbuttondown)
//		drawing = true;
//	else if (event == cv_event_mousemove) {
//		if (drawing == true)
//			circle(img, point(x, y), 3, scalar(blue, green, red), 10);
//	}
//	else if (event == cv_event_lbuttonup)
//		drawing = false;
//
//	imshow("sea_trackbar", img);
//}
//
//int main() {
//	img = imread("c:/sea.jpg");
//	if (img.empty()) { cout << "no read image" << endl; return -1; }
//
//	namedwindow("img", 1);
//	imshow("img", img);
//	puttext(img, "2016156032 jeonyumi", point(200, 300), font_hershey_plain, 1.3, 100, 2);
//
//	setmousecallback("img", drawcircle);
//	createtrackbar("r", "img", &red, 255, on_trackbar);
//	createtrackbar("g", "img", &green, 255, on_trackbar);
//	createtrackbar("b", "img", &blue, 255, on_trackbar);
// 
//	waitkey(0);
//	return 0;
//}