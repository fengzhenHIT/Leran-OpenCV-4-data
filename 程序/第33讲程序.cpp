#include <opencv2\opencv.hpp>
#include <iostream>

using namespace cv;
using namespace std;

int main()
{
	//读取图像，黑白图像边缘检测结果较为明显
	Mat img = imread("equalLena.png", IMREAD_ANYCOLOR);
	if (img.empty())
	{
		cout << "请确认图像文件名称是否正确" << endl;
		return -1;
	}
	Mat resultX, resultY, resultXY;

	//X方向一阶边缘
	Sobel(img, resultX, CV_16S, 1, 0, 1);
	convertScaleAbs(resultX, resultX);

	//Y方向一阶边缘
	Sobel(img, resultY, CV_16S, 0, 1, 3);
	convertScaleAbs(resultY, resultY);

	//整幅图像的一阶边缘
	resultXY = resultX + resultY;

	//显示图像
	imshow("resultX", resultX);
	imshow("resultY", resultY);
	imshow("resultXY", resultXY);

	cout << "接下来进行Scharr边缘的检测" << endl;
	waitKey(0);

	//X方向一阶边缘
	Scharr(img, resultX, CV_16S, 1, 0);
	convertScaleAbs(resultX, resultX);

	//Y方向一阶边缘
	Scharr(img, resultY, CV_16S, 0, 1);
	convertScaleAbs(resultY, resultY);

	//整幅图像的一阶边缘
	resultXY = resultX + resultY;

	//显示图像
	imshow("resultX", resultX);
	imshow("resultY", resultY);
	imshow("resultXY", resultXY);

	cout << "接下来生成边缘检测器" << endl;
	waitKey(0);


	Mat sobel_x1, sobel_y1; //存放分离的Sobel算子
	Mat scharr_x, scharr_y;  //存放分离的Scharr算子
	Mat sobelX1, scharrX;  //存放最终算子

						   //一阶X方向Sobel算子
	getDerivKernels(sobel_x1, sobel_y1, 1, 0, 3);
	sobel_x1 = sobel_x1.reshape(CV_8U, 1);
	sobelX1 = sobel_y1*sobel_x1;  //计算滤波器

								  //X方向Scharr算子
	getDerivKernels(scharr_x, scharr_y, 1, 0, FILTER_SCHARR);
	scharr_x = scharr_x.reshape(CV_8U, 1);
	scharrX = scharr_y*scharr_x;  //计算滤波器

								  //输出结果
	cout << "X方向一阶Sobel算子:" << endl << sobelX1 << endl;

	cout << "X方向Scharr算子:" << endl << scharrX << endl;

	waitKey(0);
	return 0;
}


