#include <opencv2/opencv.hpp>
#include <iostream>

using namespace std;
using namespace cv;

void callBack(int value, void*);
Mat img;
int main()
{
	img = imread("C:/opencv/learnOpenCV/lena.png");

	namedWindow("img");

	imshow("img", img);

	int value = 100;

	createTrackbar("百分比", "img", &value, 600, callBack, 0);

	waitKey(0);
	return 0;
}

void callBack(int value, void*)
{
	float a = value / 100.0;

	Mat img2;

	img2 = img *a;

	imshow("img", img2);
}