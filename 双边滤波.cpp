#include<opencv2/core/core.hpp>
#include<opencv2/highgui/highgui.hpp>  
#include<opencv2/imgproc/imgproc.hpp>
#include<opencv2/opencv.hpp>
using namespace cv;
using namespace std;
int main()
{
	Mat dst;
	Mat input_img = imread("pic.jpg");
	namedWindow("Ori");
	imshow("Ori", input_img);
	if (!input_img.data)
	{
		cerr << "Error: image read problem!" << endl;
		return -1;
	}
	int KERNEL_SIZE = 31;
	for (int i = 1; i < KERNEL_SIZE; i = i + 2)
	{
		bilateralFilter(input_img, dst, i, i * 2, i / 2);
	}
	namedWindow("Bil");
	imshow("Bil", dst);
	waitKey(0);
	return 0;
}

