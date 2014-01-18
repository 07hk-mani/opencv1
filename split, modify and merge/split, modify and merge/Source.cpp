#include"opencv2/highgui/highgui.hpp"
#include<iostream>

using namespace cv;
using namespace std;

int main()
{
	Mat img=imread("apple.png"),result;
	if(!img.data)
	{
		cout<<"no data"<<endl;
	}
int a=img.size().height;
	int b=img.size().width;
	cout<<"dimensions"<<a<<"X"<<b<<endl;


    namedWindow("image1");
	imshow("image1", img);
	waitKey(0);

	//split ,modify and merge

	std::vector<cv::Mat>planes;
	cv::split(img,planes);
	planes[0]=planes[1];
		
		cv::merge(planes,result);
		namedWindow("image1");
	imshow("image1", result);
	waitKey(0);




	return 1;
}



