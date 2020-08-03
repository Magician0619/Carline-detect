/*
#include<opencv2/core.hpp>
#include<opencv2/highgui.hpp>
#include<opencv2/imgproc.hpp>
using namespace cv;
#include<iostream>
#include<string>
using namespace std;
//输入图像
Mat img;
//归一化图像
Mat bgr;
//HLS图像
Mat hls;
//色相
int hmin = 0;
int hmin_Max = 360;
int hmax = 360;
int hmax_Max = 360;
//亮度
int lmin = 106;
int lmin_Max = 255;
int lmax = 250;
int lmax_Max = 255;
//饱和度
int smin = 0;
int smin_Max = 255;
int smax = 255;
int smax_Max = 255;
//显示原图的窗口
string windowName = "src";
//颜色区间
string dstName = "dst";
Mat dst;//输出图像
void callBack(int, void*)
{
	//输出图像
	dst = Mat::zeros(bgr.size(), CV_32FC3);
	//掩码
	Mat mask;
	inRange(hls, Scalar(hmin, lmin / float(lmin_Max), smin / float(smin_Max)), Scalar(hmax, lmax / float(lmax_Max), smax / float(smax_Max)), mask);
	for (int r = 0; r < bgr.rows; r++)
	{
		for (int c = 0; c < bgr.cols; c++)
		{
			if (mask.at<uchar>(r, c) == 255)
			{
				dst.at<Vec3f>(r, c) = bgr.at<Vec3f>(r, c);
			}
		}
	}
	//输出图像
	imshow(dstName, dst);
	//保存输出图像
	//数据类型转换
	dst.convertTo(dst, CV_8UC3, 255, 0);
	imwrite("C:\\Users\\Lenovo\\Desktop\\img\\dst.jpg", dst);
}
int main(int argc, char* argv[])
{
	//输入图像
	img = imread("C:\\Users\\Lenovo\\Desktop\\img\\37.jpg", IMREAD_COLOR);
	if (!img.data || img.channels() != 3)
		return -1;
	imshow(windowName, img);
	//输入图像灰度值的归一化
	img.convertTo(bgr, CV_32FC3, 1.0 / 255, 0);
	//颜色空间转换
	cvtColor(bgr, hls, COLOR_BGR2HSV);
	//输出图像
	namedWindow(dstName, WINDOW_GUI_EXPANDED);
	//色相
	createTrackbar("hmin", dstName, &hmin, hmin_Max, callBack);
	createTrackbar("hmax", dstName, &hmax, hmax_Max, callBack);
	//亮度
	createTrackbar("lmin", dstName, &lmin, lmin_Max, callBack);
	createTrackbar("lmax", dstName, &lmax, lmax_Max, callBack);
	//饱和度
	createTrackbar("smin", dstName, &smin, smin_Max, callBack);
	createTrackbar("smax", dstName, &smax, smax_Max, callBack);
	callBack(0, 0);
	waitKey(0);
	return 0;
}


# include<opencv2/core.hpp>
#include<opencv2/highgui.hpp>
#include<opencv2/imgproc.hpp>
#include <opencv2/imgproc/types_c.h>
using namespace cv;
#include<iostream>
#include<string>
using namespace std;
//输入图像
Mat img;
//灰度值归一化
Mat bgr;
//HSV图像
Mat hsv;
//色相
int hmin = 0;
int hmin_Max = 360;
int hmax = 180;
int hmax_Max = 180;
//饱和度
int smin = 0;
int smin_Max = 255;
int smax = 255;
int smax_Max = 255;
//亮度
int vmin = 106;
int vmin_Max = 255;
int vmax = 255;
int vmax_Max = 255;
//显示原图的窗口
string windowName = "src";
//输出图像的显示窗口
string dstName = "dst";
//输出图像
Mat dst;
//回调函数
void callBack(int, void*)
{
	//输出图像分配内存
	dst = Mat::zeros(img.size(), img.type());
	//掩码
	Mat mask;
	inRange(hsv, Scalar(hmin, smin, vmin), Scalar(hmax, smax, vmax), mask);
	//掩模到原图的转换
	for (int r = 0; r < bgr.rows; r++)
	{
		for (int c = 0; c < bgr.cols; c++)
		{
			if (mask.at<uchar>(r, c) == 255)
			{
				dst.at<Vec3b>(r, c) = bgr.at<Vec3b>(r, c);
			}
		}
	}
	//输出图像
	imshow(dstName, dst);
	//保存图像
	//dst.convertTo(dst, CV_8UC3, 255.0, 0);
	imwrite("C:\\Users\\Lenovo\\Desktop\\img\\result.jpg", dst);
}
int main(int argc, char** argv)
{
	//输入图像
	img = imread("C:\\Users\\Lenovo\\Desktop\\img\\110.jpg");
	if (!img.data || img.channels() != 3)
		return -1;
	imshow(windowName, img);
	bgr = img.clone();
	//颜色空间转换
	cvtColor(bgr, hsv, CV_BGR2HSV);
	cout << hsv << endl;
	//定义输出图像的显示窗口
	namedWindow(dstName, WINDOW_GUI_EXPANDED);
	//调节色相 H
	createTrackbar("hmin", dstName, &hmin, hmin_Max, callBack);
	createTrackbar("hmax", dstName, &hmax, hmax_Max, callBack);
	//调节饱和度 S
	createTrackbar("smin", dstName, &smin, smin_Max, callBack);
	createTrackbar("smax", dstName, &smax, smax_Max, callBack);
	//调节亮度 V
	createTrackbar("vmin", dstName, &vmin, vmin_Max, callBack);
	createTrackbar("vmax", dstName, &vmax, vmax_Max, callBack);
	callBack(0, 0);
	waitKey(0);
	return 0;
}

*/

#include "opencv2/imgproc.hpp"
#include "opencv2/imgcodecs.hpp"
#include "opencv2/highgui.hpp"
#include <stdlib.h>
#include <stdio.h>
#include <string>
using namespace cv;
static void help()
{
	printf("\nShow off image morphology: erosion, dialation, open and close\n"
		"Call:\n   morphology2 [image]\n"
		"This program also shows use of rect, ellipse and cross kernels\n\n");
	printf("Hot keys: \n"
		"\tESC - quit the program\n"
		"\tr - use rectangle structuring element\n"
		"\te - use elliptic structuring element\n"
		"\tc - use cross-shaped structuring element\n"
		"\tSPACE - loop through all the options\n");
}
Mat src, dst;
int element_shape = MORPH_RECT;
//the address of variable which receives trackbar position update
int max_iters = 10;
int open_close_pos = 0;
int erode_dilate_pos = 0;
// callback function for open/close trackbar
static void OpenClose(int, void*)
{
	int n = open_close_pos - max_iters;
	int an = n > 0 ? n : -n;
	Mat element = getStructuringElement(element_shape, Size(an * 2 + 1, an * 2 + 1), Point(an, an));
	if (n < 0)
		morphologyEx(src, dst, MORPH_OPEN, element);
	else
		morphologyEx(src, dst, MORPH_CLOSE, element);
	imshow("Open/Close", dst);
}
// callback function for erode/dilate trackbar
static void ErodeDilate(int, void*)
{
	int n = erode_dilate_pos - max_iters;
	int an = n > 0 ? n : -n;
	Mat element = getStructuringElement(element_shape, Size(an * 2 + 1, an * 2 + 1), Point(an, an));
	if (n < 0)
		erode(src, dst, element);
	else
		dilate(src, dst, element);
	imshow("Erode/Dilate", dst);
}
int main(int argc, char** argv)
{
	cv::CommandLineParser parser(argc, argv, "{help h||}{ @image |C:\\Users\\Lenovo\\Desktop\\img\\110.jpg| }");
	if (parser.has("help"))
	{
		help();
		return 0;
	}
	std::string filename = parser.get<std::string>("@image");
	if ((src = imread(filename, IMREAD_COLOR)).empty())
	{
		help();
		return -1;
	}
	//create windows for output images
	namedWindow("Open/Close", 1);
	namedWindow("Erode/Dilate", 1);
	open_close_pos = erode_dilate_pos = max_iters;
	createTrackbar("iterations", "Open/Close", &open_close_pos, max_iters * 2 + 1, OpenClose);
	createTrackbar("iterations", "Erode/Dilate", &erode_dilate_pos, max_iters * 2 + 1, ErodeDilate);
	for (;;)
	{
		OpenClose(open_close_pos, 0);
		ErodeDilate(erode_dilate_pos, 0);
		char c = (char)waitKey(0);
		if (c == 27)
			break;
		if (c == 'e')
			element_shape = MORPH_ELLIPSE;
		else if (c == 'r')
			element_shape = MORPH_RECT;
		else if (c == 'c')
			element_shape = MORPH_CROSS;
		else if (c == ' ')
			element_shape = (element_shape + 1) % 3;
	}
	return 0;
}