#include<opencv2/core/core.hpp>
#include<opencv2/highgui/highgui.hpp>  
#include<opencv2/imgproc/imgproc.hpp>


using namespace cv;
int main()
{
	Mat src, dst_gauss_1,dst_gauss,dst_mean_1,dst_mean;
	src = imread("pic.jpg");
	blur(src, dst_mean_1, Size(11,11));
	blur(dst_mean_1, dst_mean, Size(11, 11));
	GaussianBlur(src, dst_gauss_1, Size(5, 5), 0, 0);
	GaussianBlur(dst_gauss_1, dst_gauss, Size(5, 5), 0, 0);


	namedWindow("org img", CV_WINDOW_NORMAL);
	namedWindow("mean img", CV_WINDOW_NORMAL);
	namedWindow("gauss img", CV_WINDOW_NORMAL);
	imshow("org img", src);
	imshow("gauss img", dst_gauss);
	imshow("mean img", dst_mean);

		
		waitKey();

}