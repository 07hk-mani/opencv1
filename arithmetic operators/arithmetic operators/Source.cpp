#include"opencv2/highgui/highgui.hpp"
#include"opencv2/core/core.hpp"

#include<iostream>

using namespace cv;
using namespace std;

int main()
{
	Mat img=imread("apple.png"), result;
	if(!img.data)
	{
		cout<<"no data1"<<endl;
	}


	Mat img2;
flip(img,img2,0);

result.create(img.rows,img.cols,img.type());
result=img;
       cv::addWeighted(img,0.7,img2,0.9,0.,result);
    namedWindow("img");
	imshow("img", result);
	waitKey(0);

	return 1;
}