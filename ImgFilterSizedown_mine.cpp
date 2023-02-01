#include <opencv2/opencv.hpp>
#include "opencv2/imgproc/imgproc.hpp"
#include "opencv2/highgui/highgui.hpp"
#include <iostream>


using namespace cv;
using namespace std;

int main()
{
	Mat img = imread("C:\\JUNHA\\openCV\\jungen.jpg", IMREAD_GRAYSCALE);
	if (img.empty())
	{
		cout<<"사진 오류 ";
		return -1;
	}
	resize(img, img, Size(512, 512));
	const double ft[2][2] = { 1,1,1,1 };
	Mat result(256, 256, CV_8UC1);
	for (int r = 0; r < result.rows; r++)
	{   
		for (int c = 0; c < result.cols; c++)
		{
			uchar& value = result.at<uchar>(r, c);
			value = (img.at<uchar>(2*r, 2*c)*ft[0][0]+ img.at<uchar>(2*r, 2*c+1) * ft[0][1]+
				img.at<uchar>(2*r+1, 2*c) * ft[1][0]+ img.at<uchar>(2*r+1, 2*c+1) * ft[1][1])/4;
		}
	}
	imshow("org", img);
	imshow("r", result);
	waitKey(0);

}
