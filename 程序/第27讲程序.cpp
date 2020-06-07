#include <opencv2\opencv.hpp>
#include <iostream>

using namespace cv;
using namespace std;

int main()
{
	Mat img = imread("lena.png");
	Mat temp = imread("lena_face.png");

	Mat result;

	matchTemplate(img, temp, result, TM_CCOEFF_NORMED);
	double maxVal, minVal;

	Point maxLoc, minLoc;

	minMaxLoc(result, &minVal, &maxVal, &minLoc, &maxLoc);

	rectangle(img, Point(maxLoc.x, maxLoc.y), Point(maxLoc.x + temp.cols, maxLoc.y + temp.rows), Scalar(0, 0, 255), 2);

	imshow("原图像", img);
	imshow("模板", temp);
	imshow("result", result);

	waitKey(0);

	return 0;
}