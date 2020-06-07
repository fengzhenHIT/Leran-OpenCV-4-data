#include <opencv2/opencv.hpp>
#include <iostream>

using namespace cv;
using namespace std;

int main()
{
	system("color F0");
		
	Mat a = (cv::Mat_<int>(3, 3) << 1, 2, 3, 4, 5, 6, 7, 8, 9);
	Mat b = (cv::Mat_<int>(3, 3) << 1, 2, 3, 7, 8, 9, 4, 5, 6);
	Mat c = (cv::Mat_<double>(3, 3) << 1.0, 2.1, 3.2, 4.0, 5.1, 6.2, 2, 2, 2);
	Mat d = (cv::Mat_<double>(3, 3) << 1.0, 2.1, 3.2, 4.0, 5.1, 6.2, 2, 2, 2);

	
	cout << "两个矩阵的和=" << endl<< a + b << endl;
	cout << "两个矩阵的差=" << endl << c - d << endl;
	cout << "矩阵数乘=" << endl << 2 * a << endl;
	cout << "矩阵数除=" << endl << d / 2.0 << endl;
	cout << "矩阵减数=" << endl << a - 1 << endl;
	
	cout << "两矩阵相乘=" << endl << c*d << endl;
	cout << "矩阵内积=" << endl << a.dot(b) << endl;
	cout << "矩阵对应位相乘=" << endl << a.mul(b) << endl;

	cout << "两个矩阵最小值=" << endl << min(a, b) << endl;
	


	return 0;
}