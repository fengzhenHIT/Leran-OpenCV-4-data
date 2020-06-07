#include <opencv2\opencv.hpp>
#include <iostream>

using namespace std;
using namespace cv;

int main()
{
	Mat gray = imread("lena.png", IMREAD_GRAYSCALE);

	Mat smallImg, bigImg0, bigImg1, bigImg2;
	resize(gray, smallImg, Size(15, 15), 0, 0, INTER_AREA);  //先将图像缩小
	resize(smallImg, bigImg0, Size(30, 30), 0, 0, INTER_NEAREST);  //最近邻差值
	resize(smallImg, bigImg1, Size(30, 30), 0, 0, INTER_LINEAR);  //双线性差值
	resize(smallImg, bigImg2, Size(30, 30), 0, 0, INTER_CUBIC);  //双三次差值


	Mat img_x, img_y, img_xy;
	flip(gray, img_x, 0);  //沿x轴对称
	flip(gray, img_y, 1);  //沿y轴对称
	flip(gray, img_xy, -1);  //先x轴对称，再y轴对称

	Mat img00 = imread("lena00.png");
	Mat img01 = imread("lena01.png");
	Mat img10 = imread("lena10.png");
	Mat img11 = imread("lena11.png");

	//显示4个子图像


	//图像连接
	Mat img, img0, img1;
	//图像横向连接
	hconcat(img00, img01, img0);
	hconcat(img10, img11, img1);
	//横向连接结果再进行竖向连接
	vconcat(img0, img1, img);

	//显示连接图像的结果

	waitKey(0);
	return 0;
}