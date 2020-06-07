#include <opencv2/opencv.hpp>
#include <iostream>

using namespace cv;
using namespace std;

int main()
{
	Mat img;
	img = imread("C:/opencv/lena.png",IMREAD_COLOR);

	Mat gray = imread("C:/opencv/lena.png", IMREAD_GRAYSCALE);

	namedWindow("img", WINDOW_AUTOSIZE);

	namedWindow("gray", WINDOW_NORMAL);

	imshow("img", img);
	imshow("gray", gray);
	//vector<int> compression_params;
	//compression_params.push_back(IMWRITE_PNG_COMPRESSION);
	//compression_params.push_back(9);

	imwrite("C:/opencv/newlena.jpg", img);


	waitKey(0);



	return 0;
}