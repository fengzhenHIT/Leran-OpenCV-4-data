#include <opencv2/opencv.hpp>
#include <iostream>

using namespace cv;
using namespace std;

int main()
{
	Mat img = imread("C:/opencv/lena.png");
	Mat img32;
	img.convertTo(img32, CV_32F, 1 / 255.0, 0);
	Mat gray0, gray1;
	cvtColor(img, gray0, COLOR_BGR2GRAY);
	cvtColor(img, gray1, COLOR_RGB2GRAY);


	Mat imgs[3];
	split(img, imgs);

	Mat img0, img1, img2;

	img0 = imgs[0];
	img1 = imgs[1];
	img2 = imgs[2];

	Mat img_H;
	merge(imgs, 3, img_H);


	Mat zero = Mat::zeros(Size(img.cols, img.rows), CV_8UC1);

	vector<Mat> imgsV;
	imgsV.push_back(img0);
	imgsV.push_back(zero);
	imgsV.push_back(zero);

	
	/*imgsV.push_back(zero);
	imgsV.push_back(zero);
	imgsV.push_back(img2);*/

	Mat imgsVH;
	merge(imgsV, imgsVH);


	return 0;
}