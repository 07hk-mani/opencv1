#include "opencv2/highgui/highgui.hpp"
#include <iostream>

using namespace std;
using namespace cv;
int main()
{

Mat image = imread("dog.jpg"), noisyImage;
if (!image.data) { 
		cout << "No data";
	
	}
namedWindow("Original"); 
imshow("Original", image); 
waitKey(0);

image.copyTo(noisyImage);

for (int k=0; k<500; k++)
{
		
		int i = rand()%noisyImage.cols;
		int j = rand()%noisyImage.rows;
		if (noisyImage.channels() == 1) { // gray-level image
			noisyImage.at<uchar>(j,i)= 255; 
		} else if (noisyImage.channels() == 3)
		{ // color image
			noisyImage.at<Vec3b>(j,i)[0]= 255; 
			noisyImage.at<Vec3b>(j,i)[1]= 255; 
			noisyImage.at<Vec3b>(j,i)[2]= 255; 
		}
	}

for (int k=0; k<500; k++)
{
		
		int i = rand()%noisyImage.cols;
		int j = rand()%noisyImage.rows;
		if (noisyImage.channels() == 1) { // gray-level image
			noisyImage.at<uchar>(j,i)= 0; 
		} else if (noisyImage.channels() == 3)
		{ // color image
			noisyImage.at<Vec3b>(j,i)[0]= 0; 
			noisyImage.at<Vec3b>(j,i)[1]= 0; 
			noisyImage.at<Vec3b>(j,i)[2]= 0; 
		}
	}


	namedWindow("Noisy"); 
	imshow("Noisy", noisyImage);
	waitKey(0);
}