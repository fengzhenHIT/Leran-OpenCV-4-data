#include <opencv2/opencv.hpp>
#include <iostream>

using namespace cv;
using namespace std;

int main()
{
	Mat img = imread("C:/opencv/learnOpenCV/lena.png");
	Mat white = imread("C:/opencv/learnOpenCV/mark_white.png");
	Mat black = imread("C:/opencv/learnOpenCV/mark_black.png");

	Mat Min, Max;
	min(img, white, Min);
	max(img, black, Max);

	Mat gray, gray_white;
	cvtColor(img, gray, COLOR_BGR2GRAY);
	cvtColor(white, gray_white, COLOR_BGR2GRAY);

	double minVal, maxVal;
	Point minLoc, maxLoc;

	minMaxLoc(gray, &minVal, &maxVal, &minLoc, &maxLoc, gray_white);



	return 0;
}