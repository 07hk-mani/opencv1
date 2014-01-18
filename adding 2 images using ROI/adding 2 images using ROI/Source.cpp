#include"opencv2/highgui/highgui.hpp"
#include<iostream>

using namespace cv;
using namespace std;

int main()
{
	Mat img=imread("apple.png");
	if(!img.data)
	{
		cout<<"no data1"<<endl;
	}
	Mat img2=imread("logo.png");
	if(!img2.data)
	{
		cout<<"no data2"<<endl;
	}

cv::Mat imageROI;
imageROI= img(cv::Rect(150,200,img2.cols,img2.rows));
// load the mask (must be gray-level)
cv::Mat mask= cv::imread("logo.bmp",0);
// copy to ROI with mask
img2.copyTo(imageROI,mask);

cv::addWeighted(imageROI,1.0,img2,1.0,0.,imageROI);


    namedWindow("image1");
	imshow("image1", img);
	waitKey(0);

	



	return 1;
}




