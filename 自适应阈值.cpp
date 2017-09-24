//compare thresholding with adaptive thresholding
#include<cv.h>
#include<highgui.h>
#include<math.h>
using namespace cv;
IplImage *Igray = 0, *It = 0, *Iat;
int main(int argc, char *argv[])
{
	if (argc!= 7)
	{
		return -1;
	}
	//command line
	double threshold = (double)atof(argv[1]);//输入字符串转换为整数
	int threshold_type = atoi(argv[2]) ?
	CV_THRESH_BINARY : CV_THRESH_BINARY_INV;
	int adaptive_method = atoi(argv[3]);
	CV_ADAPTIVE_THRESH_MEAN_C:CV_ADAPTIVE_THRESH_GAUSSIAN_C;
	int block_size = atoi(argv[4]);
	double offset = (double)atof(argv[5]);
	//read gray image
	if ((Igray = cvLoadImage(argv[6, CV_LOAD_IMAGE_GRAYSCALE])) == 0)
	{
		return (-1);
	}
	//create the output image
	It = cvCreateImage(Size(Igray->width, Igray->height), IPL_DEPTH_8U, 1);
	Iat = cvCreateImage(Size(Igray->width, Igray->height), IPL_DEPTH_8U, 1);
	//threshold
	cvThreshold(Igray, It, threshold, 255, threshold_type);
	cvAdaptiveThreshold(Igray, It, 255, adaptive_method, threshold_type, block_size, offset);
	cvNamedWindow("Raw", 1);
	cvNamedWindow("Threshold", 1);
	cvNamedWindow("Adaptive threshold", 1);
	//display the image
	cvShowImage("Raw", Igray);
	cvShowImage("Threshold", It);
	cvShowImage("Adaptive threshold", Iat);
	waitKey();
	//release memory
	cvReleaseImage(&Igray);
	cvReleaseImage(&Iat);
	cvReleaseImage(&It);
	return(0);
}





