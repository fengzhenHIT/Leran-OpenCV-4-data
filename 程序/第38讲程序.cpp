#include <opencv2\opencv.hpp>
#include <iostream>

using namespace cv;
using namespace std;

int main()
{
	//生成用于膨胀的原图像
	Mat src = (Mat_<uchar>(6, 6) << 0, 0, 0, 0, 255, 0,
		0, 255, 255, 255, 255, 255,
		0, 255, 255, 255, 255, 0,
		0, 255, 255, 255, 255, 0,
		0, 255, 255, 255, 255, 0,
		0, 0, 0, 0, 0, 0);
	Mat struct1, struct2;
	struct1 = getStructuringElement(0, Size(3, 3));  //矩形结构元素
	struct2 = getStructuringElement(1, Size(3, 3));  //十字结构元素

	Mat erodeSrc;  //存放膨胀后的图像
	dilate(src, erodeSrc, struct2);
	namedWindow("src", WINDOW_GUI_NORMAL);
	namedWindow("dilateSrc", WINDOW_GUI_NORMAL);
	imshow("src", src);
	imshow("dilateSrc", erodeSrc);

	cout << "文字膨胀" << endl;
	waitKey(0);

	Mat LearnCV_black = imread("LearnCV_black.png", IMREAD_ANYCOLOR);

	Mat dilate_black1, dilate_black2;
	//黑背景图像膨胀
	dilate(LearnCV_black, dilate_black1, struct1);
	dilate(LearnCV_black, dilate_black2, struct2);
	imshow("LearnCV_black", LearnCV_black);
	imshow("dilate_black1", dilate_black1);
	imshow("dilate_black2", dilate_black2);

	waitKey(0);
	return 0;
}
