#include "opencv2/highgui/highgui.hpp"
#include <iostream>

using namespace std;
using namespace cv;

int main()
{
	Mat image = imread("baboon.jpg"), processed;

	if (!image.data) { 
		cout << "No data";

	}
	namedWindow("Original"); 
	imshow("Original", image); 
	waitKey(0);
	image.copyTo(processed);

	// obtain iterator at initial position
	Mat_<Vec3b>::iterator it = processed.begin<Vec3b>();
	// obtain end position
	Mat_<Vec3b>::iterator itend = processed.end<Vec3b>();
	int div = 128;
	// loop over all pixels
	for ( ; it!= itend; ++it) {
		// process each pixel ---------------------
		(*it)[0]= (*it)[0]/div*div + div/2;
		(*it)[1]= (*it)[1]/div*div + div/2;
		(*it)[2]= (*it)[2]/div*div + div/2;
		// end of pixel processing ----------------
	}


	//we can also use this method

	/*
	int nl= processed.rows; 
	int nc= processed.cols * processed.channels();
	for (int j=0; j<nl; j++) 
	{
	// get the address of row j
	uchar* data=processed.ptr<uchar>(j);
	for (int i=0; i<nc; i++) {
	// process each pixel ---------------------
	data[i]= data[i]/((64*64) + 32);
	}
	}
	*/
	namedWindow("Processed"); 
	imshow("Processed", processed);
	waitKey(0);
}
