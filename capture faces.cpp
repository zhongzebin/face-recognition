#include "pch.h"
#include <iostream>
#include <opencv.hpp>
#include <stdio.h>
#include <opencv2\face\facerec.hpp>
using namespace std;
using namespace cv;
using namespace cv::face;
int main()
{
	int num = 1;
	VideoCapture cap(0);
	Mat frame;
	Mat myface;
	CascadeClassifier cascade;
	cascade.load("haarcascade_frontalface_alt2.xml");//加载分类器
	while (1)
	{
		cap >> frame;
		vector<Rect> faces;
		Mat frame_gray;
		cvtColor(frame, frame_gray, COLOR_BGR2GRAY);
		cascade.detectMultiScale(frame_gray, faces, 1.1, 6, CV_HAAR_DO_ROUGH_SEARCH, Size(70, 70), Size(1000, 1000));//输入灰度图像，输出矩形框，每次矩形框缩小的比例，至少有n次被检出才是真目标，检测模式，最小检测框，最大检测框
		cout << "检测到的人脸个数：" << faces.size() << endl;
		for (int i = 0; i < faces.size(); i++)//将脸在图像中用矩形框住
		{
			rectangle(frame, faces[i], Scalar(255, 0, 0), 2, 8, 0);
		}
		if (faces.size() == 1)//如果检测到的人脸数为1，则开始捕捉
		{
			Mat faceroi = frame_gray(faces[0]);//提取矩形框内图像
			resize(faceroi, myface, Size(92, 112));//由于数据集都是92*112的，所以将图像调节至该尺寸
			putText(frame, to_string(num), faces[0].tl(), 3, 1.2, (0, 0, 225), 2, 0);//将捕捉到的人脸次数显示在框左上角
			string filename = format("%d.jpg", num);//生成文件名
			imwrite(filename, myface);//将图像写入该文件名下
			num++;
		}
		imshow("frame", frame);
		int c=waitKey(100);
		if (c == 27)//按esc键退出
			break;
	}
	return 0;
}
