#include <opencv2\opencv.hpp>
#include <iostream>

using namespace cv;
using namespace std;

int main()
{
	Mat img = imread("C:/opencv/learnOpenCV/lena.png");

	vector<Mat> Guass;
	int level = 3;

	Guass.push_back(img);

	for (int i = 0; i < level; i++)
	{
		Mat guass;
		pyrDown(Guass[i], guass);
		Guass.push_back(guass);
	}

	for (int i = 0; i < level; i++)
	{
		string name = to_string(i);
		imshow(name, Guass[i]);
	}

	waitKey(0);
	return 0;
}
