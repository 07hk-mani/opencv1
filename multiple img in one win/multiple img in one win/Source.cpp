#include"opencv2/highgui/highgui.hpp"
#include<iostream>

using namespace cv;
using namespace std;

int main()
{
	Mat img ,flipped1,flipped2,flipped3;
	img=imread("logo.png");
	if(!img.data)
	{
		cout<<"no data"<<endl;
	}
	
	flip(img,flipped1,-1);
	
	flip(img,flipped2,4);
	
	flip(img,flipped3,0);
	
	namedWindow("out"); 

    Size sz1 =img.size();
	int cx=sz1.width;
	int cy=sz1.height;
	int a=2*cx;
	int b=2*cy;
	
	Mat res(sz1.height+sz1.height, sz1.width+sz1.width, CV_8UC3);

//Create a ROI per quadrant
Mat q0=res(cv::Rect(0, 0, cx, cy));   // Top-Left  
img.copyTo(q0);
Mat q1=res(cv::Rect(cx, 0, cx, cy));  // Top-Right
flipped1.copyTo(q1);
Mat q2=res(cv::Rect(0, cy, cx, cy));  // Bottom-Left
flipped2.copyTo(q2);
Mat q3=res(cv::Rect(cx, cy, cx, cy)); // Bottom-Right
flipped3.copyTo(q3);
 imshow("out", res);
waitKey(0);
return 1;
}