#include <opencv2\opencv.hpp>
#include <iostream>
#include <vector>

using namespace cv;
using namespace std;

int main()
{
	system("color F0");  //更改输出界面颜色
	Vec4f lines;  //存放你拟合的直线
	vector<Point2f> point;  //待检测是否存在直线的所有点
	const static float Points[20][2] = {
		{ 0.0f,   0.0f },{ 10.0f,  11.0f },{ 21.0f,  20.0f },{ 30.0f,  30.0f },
		{ 40.0f,  42.0f },{ 50.0f,  50.0f },{ 60.0f,  60.0f },{ 70.0f,  70.0f },
		{ 80.0f,  80.0f },{ 90.0f,  92.0f },{ 100.0f, 100.0f },{ 110.0f, 110.0f },
		{ 120.0f, 120.0f },{ 136.0f, 130.0f },{ 138.0f, 140.0f },{ 150.0f, 150.0f },
		{ 160.0f, 163.0f },{ 175.0f, 170.0f },{ 181.0f, 180.0f },{ 200.0f, 190.0f }
	};
	//将所有点存放在vector中，用于输入函数中
	for (int i = 0; i < 20; i++)
	{
		point.push_back(Point2f(Points[i][0], Points[i][1]));
	}
	//参数设置
	double param = 0;  //距离模型中的数值参数C
	double reps = 0.01;  //坐标原点与直线之间的距离精度
	double aeps = 0.01;  //角度精度
	fitLine(point, lines, DIST_L1, 0, 0.01, 0.01);
	double k = lines[1] / lines[0];  //直线斜率
	cout << "直线斜率：" << k << endl;
	cout << "直线上一点坐标x：" << lines[2] << ", y:" << lines[3] << endl;
	cout << "直线解析式：y=" << k << "(x-" << lines[2] << ")+" << lines[3] << endl;


	waitKey(0);



	Mat img(500, 500, CV_8UC3, Scalar::all(0));
	RNG& rng = theRNG();  //生成随机点

	while (true)
	{
		int i, count = rng.uniform(1, 101);
		vector<Point> points;
		//生成随机点
		for (i = 0; i < count; i++)
		{
			Point pt;
			pt.x = rng.uniform(img.cols / 4, img.cols * 3 / 4);
			pt.y = rng.uniform(img.rows / 4, img.rows * 3 / 4);
			points.push_back(pt);
		}

		//寻找包围点集的三角形 
		vector<Point2f> triangle;
		double area = minEnclosingTriangle(points, triangle);

		//寻找包围点集的圆形
		Point2f center;
		float radius = 0;
		minEnclosingCircle(points, center, radius);

		//创建两个图片用于输出结果
		img = Scalar::all(0);
		Mat img2;
		img.copyTo(img2);

		//在图像中绘制坐标点
		for (i = 0; i < count; i++)
		{
			circle(img, points[i], 3, Scalar(255, 255, 255), FILLED, LINE_AA);
			circle(img2, points[i], 3, Scalar(255, 255, 255), FILLED, LINE_AA);
		}

		//绘制三角形
		for (i = 0; i < 3; i++)
		{
			if (i == 2)
			{
				line(img, triangle[i], triangle[0], Scalar(255, 255, 255), 1, 16);
				break;
			}
			line(img, triangle[i], triangle[i + 1], Scalar(255, 255, 255), 1, 16);
		}

		//绘制圆形
		circle(img2, center, cvRound(radius), Scalar(255, 255, 255), 1, LINE_AA);

		//输出结果
		imshow("triangle", img);
		imshow("circle", img2);

		//按q键或者ESC键退出程序
		char key = (char)waitKey();
		if (key == 27 || key == 'q' || key == 'Q')
		{
			break;
		}
	}
	return 0;
}