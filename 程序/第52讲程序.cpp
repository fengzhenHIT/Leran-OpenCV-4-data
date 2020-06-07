#include <opencv2/opencv.hpp>
#include<iostream>

using namespace cv;
using namespace std;

int main()
{
	Mat img = imread("lena.png");
	if (!img.data)
	{
		cout << "读取图像错误，请确认图像文件是否正确" << endl;
		return -1;
	}

	Mat gray;
	cvtColor(img, gray, COLOR_BGR2GRAY);
	// Detector parameters

	//提取角点
	int maxCorners = 100;  //检测角点数目
	double quality_level = 0.01;  //质量等级，或者说阈值与最佳角点的比例关系
	double minDistance = 0.04;  //两个角点之间的最小欧式距离
	vector<Point2f> corners;
	goodFeaturesToTrack(gray, corners, maxCorners, quality_level, minDistance, Mat(), 3, false);

	//绘制角点
	vector<KeyPoint> keyPoints;  //存放角点的KeyPoint类，用于后期绘制角点时用

	for (int i = 0; i < corners.size(); i++)
	{
		//将角点存放在KeyPoint类中
		KeyPoint keyPoint;
		keyPoint.pt = corners[i];
		keyPoints.push_back(keyPoint);
	}

	//用drawKeypoints()函数绘制角点坐标
	drawKeypoints(img, keyPoints, img);
	imshow("角点结果", img);
	waitKey(0);
	return 0;
}
