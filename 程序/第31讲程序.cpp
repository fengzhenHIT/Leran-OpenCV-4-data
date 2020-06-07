#include <opencv2\opencv.hpp>
#include <iostream>

using namespace cv;
using namespace std;

int main()
{
	Mat img = imread("lena_salt.png", IMREAD_ANYCOLOR);
	Mat gray = imread("equalLena_salt.png", IMREAD_ANYCOLOR);
	Mat gray_g = imread("equalLena_gauss.png", IMREAD_ANYCOLOR);

	Mat imgResult3, imgResult9, grayResult3, grayResult9, gray_gResult3, gray_gResult9;

	medianBlur(img, imgResult3, 3);
	medianBlur(gray, grayResult3, 3);
	medianBlur(gray_g, gray_gResult3, 3);

	medianBlur(img, imgResult9, 9);
	medianBlur(gray, grayResult9, 9);
	medianBlur(gray_g, gray_gResult9, 9);

	imshow("imgResult3", imgResult3);
	imshow("grayResult3", grayResult3);
	imshow("gray_gResult3", gray_gResult3);

	imshow("imgResult9", imgResult9);
	imshow("grayResult9", grayResult9);
	imshow("gray_gResult9", gray_gResult9);

	waitKey(0);

	return 0;
}
