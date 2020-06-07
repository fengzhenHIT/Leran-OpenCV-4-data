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

	vector<Mat> Lap;

	for (int i = Guass.size()-1; i > 0 ; i--)
	{
		Mat lap, upGuass;

		if (i == Guass.size() - 1)
		{
			Mat down;
			pyrDown(Guass[i], down);
			pyrUp(down, upGuass);
			lap = Guass[i] - upGuass;
			Lap.push_back(lap);
		}

		pyrUp(Guass[i], upGuass);
		lap = Guass[i - 1] - upGuass;
		Lap.push_back(lap);
	}

	for (int i = 0; i < Guass.size(); i++)
	{
		string name = to_string(i);
		Mat guass, lap;
		guass = Guass[i];
		lap = Lap[Guass.size() - 1 - i];
		imshow("G" + name, Guass[i]);
		imshow("L" + name, Lap[Guass.size() - 1 - i]);
	}


	waitKey(0);
	return 0;
}
