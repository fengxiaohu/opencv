//头文件载入
#include<iostream>
#include<opencv2/imgproc/imgproc.hpp>
#include<opencv2/highgui/highgui.hpp>
//命名空间声明部分
using namespace cv;
using namespace std;
//全局函数部分
Mat img;
int thresval = 160;//createTrackbarh函数给定第三个函数的初值
static void on_trackbar(int, void*)
{
	Mat bw = thresval < 128 ? (img<thresval) : (img>thresval);
		vector<vector<Point>>contours;
		vector<Vec4i>hierachy;
		findContours (bw, contours, hierachy, CV_RETR_CCOMP, CV_CHAIN_APPROX_SIMPLE);
		//findContours函数定义，用来寻找一个图像的轮廓
		//CV_EXPORTS_W void findContours( InputOutputArray image, OutputArrayOfArrays contours,OutputArray hierarchy, int mode,int method, Point offset = Point());
		//! retrieves contours and the hierarchical information from black-n-white image.
		//CV_EXPORTS_W void findContours(InputOutputArray image, OutputArrayOfArrays contours,
			//OutputArray hierarchy, int mode,
			//int method, Point offset = Point());
	Mat dst = Mat::zeros(img.size(), CV_8UC3);//初始化dst
		if (!contours.empty() && !hierachy.empty())//遍历图像
		{
			int idx;
			for (idx = 0; idx >= 0;idx=hierachy[idx][0])
			{
				Scalar color((rand()& 255), (rand() & 255), (rand() & 255));
					drawContours(dst, contours, idx, color, CV_FILLED, 8, hierachy);
			}
		}
		imshow("Connected Components", dst);

}

int main()
{
	system("color 5F");
	img = imread("pic.jpg", 0);//load image
	if (!img.data)
	{
		printf("Error to load");
		return -1;
	}
	namedWindow("Image", 1);
	imshow("Image", img);//显示 image
	namedWindow("Connected Components",1);
	createTrackbar("Threshold","Connected Components", &thresval, 255, on_trackbar);//调用滑动条函数，调节轮廓显示
	
	on_trackbar(thresval, 0);
	waitKey();
	return 0;
}