#include <opencv2/opencv.hpp>
#include <iostream>

using namespace cv;
using namespace std;

int main()
{
	Mat a = (Mat_<uchar>(1, 2) << 0, 5);
	Mat b = (Mat_<uchar>(1, 2) << 0, 6);

	Mat Xor, Or, Not, And;

	bitwise_not(a, Not);

	cout <<"a Not" << Not << endl;

	bitwise_and(a, b, And);
	bitwise_or(a, b, Or);
	bitwise_xor(a, b, Xor);

	cout <<  And << endl;
	cout <<  Or << endl;
	cout <<  Xor << endl;

	Mat img = imread("C:/opencv/learnOpenCV/lena.png");
	Mat mark = imread("C:/opencv/learnOpenCV/mark_white.png");

	Mat result;
	bitwise_and(img, mark, result);

	Mat img_inv;
	//bitwise_not(img, img_inv);

	cvtColor(mark, mark, COLOR_BGR2GRAY);

	bitwise_not(img, img_inv,mark);

	Mat mark_black = imread("C:/opencv/learnOpenCV/mark_black.png");

	min(img, mark_black, img);

	img = img + img_inv;

	return 0;
}
