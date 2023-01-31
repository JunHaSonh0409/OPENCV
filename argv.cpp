#include <opencv2/opencv.hpp>
#include "opencv2/imgproc/imgproc.hpp"
#include "opencv2/highgui/highgui.hpp"
#include <iostream>


using namespace cv;
using namespace std;
int main(int argc,char* argv[])
{
	Mat img1 = imread(argv[2], IMREAD_COLOR);
	Mat img2 = imread(argv[3], IMREAD_COLOR);
	
	if (img1.empty() || img2.empty())
	{
		cout << "이미지 읽을수 없음";
		return -1;
	}
	resize(img2, img2, Size(img1.cols, img1.rows));
	vector<Mat> mat = { img1,img2 };
	Mat imgr;
	if(strcmp(argv[1], "-v") == 0)
		vconcat(mat, imgr);;
	if(strcmp(argv[1],"-h")==0)
	    hconcat(mat, imgr);
	imwrite("C:\\temp\\1111.jpg", imgr);
	imshow("fuck", imgr);
	waitKey(0);
	return 0;
}
