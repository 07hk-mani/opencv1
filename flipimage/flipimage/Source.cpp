#include"opencv2/highgui/highgui.hpp"
#include<iostream>

using namespace cv;
using namespace std;

int main()
{
	Mat img ,flipped1,flipped2,flipped3;
	img=imread("apple.png");
	if(!img.data)
	{
		cout<<"no data"<<endl;
	}

	//flipping the images

	flip(img,flipped1,-1);
	flip(img,flipped2,4);
	flip(img,flipped3,0);

	//disply images in different windows one by one

	namedWindow("Flipped1"); 
    imshow("Flipped1", img);
	waitKey(0);
	namedWindow("Flipped2"); 
	imshow("Flipped2", flipped1);
	waitKey(0);
	namedWindow("Flipped3"); 
    imshow("Flipped3", flipped2);
	waitKey(0);
	imshow("Flipped4", flipped3);
    namedWindow("Flipped4"); 
    waitKey(0);
	return 1;
}


