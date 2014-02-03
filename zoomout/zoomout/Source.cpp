#include"opencv2/highgui/highgui.hpp"
#include"opencv2/imgproc/imgproc.hpp"
#include<iostream>
#include <math.h>


using namespace cv;
using namespace std;

int main()
{
	Mat img ,zoomout,zoomin;


	img=imread("baboon.jpg");
	if(!img.data)
	{
		cout<<"no data"<<endl;
	}
	namedWindow("image1",CV_WINDOW_AUTOSIZE);
	imshow("image1", img);


	zoomout = img;
	zoomin=img;

	pyrDown(img,zoomout,Size(img.rows/2,img.cols/2)); //Gaussian pyramid: Used to downsample images

	namedWindow("image2");
	imshow("image2", zoomout);

	pyrUp( img, zoomin, Size( img.cols*2, img.rows*2 ));//lapacian pyramid: Used to upsample image
	namedWindow("image3");
	imshow("image3", zoomin);
	waitKey(0);
	return 1;
}