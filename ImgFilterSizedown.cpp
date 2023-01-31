# OPENCV
opencv 코드
int main(int argc, char* argv[])
{

	Mat lena = imread("C:\\JUNHA\\openCV\\lena.jpg", cv::IMREAD_GRAYSCALE);
	if (lena.empty())
	{
		std::cout << "그림없음" << std::endl;
		return -1;
	}
#include <opencv2/opencv.hpp>
#include "opencv2/imgproc/imgproc.hpp"
#include "opencv2/highgui/highgui.hpp"
#include <iostream>


using namespace cv;
using namespace std;

	

	Mat filter(2, 2, CV_32FC1, Scalar(1.0));
	filter = filter / 4.0;
	Mat lena_resized;
	resize(lena, lena_resized, cv::Size(256, 256), 0, 0, INTER_NEAREST);

	
	Mat result(128, 128, CV_8U);
	for (int i = 0; i < 128; i++)
	{
		for (int j = 0; j < 128; j++)
		{
			Mat window = lena_resized(Rect(j * 2, i * 2, 2, 2));
			float sum = 0;
			for (int m = 0; m < 2; m++)
			{
				for (int n = 0; n < 2; n++)
				{
					uchar data = window.at<uchar>(m, n);
					data = filter.at<float>(m, n);
					sum += window.at<uchar>(m, n) * filter.at<float>(m, n);
				}
			}
			result.at<uchar>(i, j) = sum;
		}
	}


	cv::imshow("Result", result);
	imshow("lena", lena_resized);
	cv::waitKey();
	return 0;
}
