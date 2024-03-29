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
	VideoCapture cap(0);
	Mat frame;
	Mat myface;
	CascadeClassifier cascade;
	cascade.load("haarcascade_frontalface_alt2.xml");//加载分类器
	Ptr<BasicFaceRecognizer> model = EigenFaceRecognizer::create();
	model->read("MyFacePCAModel.xml");//加载训练好的模型
	while (1)
	{
		cap >> frame;
		vector<Rect> faces;
		Mat frame_gray;
		cvtColor(frame, frame_gray, COLOR_BGR2GRAY);
		cascade.detectMultiScale(frame_gray, faces, 1.1, 4, CV_HAAR_DO_ROUGH_SEARCH, Size(70, 70), Size(1000, 1000));//输入灰度图像，输出矩形框，每次矩形框缩小的比例，至少有n次被检出才是真目标，检测模式，最小检测框，最大检测框
		vector<Mat> faceroi;
		for (int i = 0; i < faces.size(); i++)//将脸在图像中用矩形框住
		{
			rectangle(frame, faces[i], Scalar(255, 0, 0), 2, 8, 0);
			faceroi.push_back(frame_gray(faces[i]));//提取人脸区域
			resize(faceroi[i], myface, Size(92, 112));//将其大小变为训练样本大小
			int predict = model->predict(myface);//使用训练好的模型，生成该人脸对应的标签
			if (predict == 41)//根据标签显示相应的人脸名
				putText(frame, "zzb", faces[i].tl(), 3, 1.2, (0, 0, 225), 2, 0);
			if (predict == 42)
				putText(frame, "wrz", faces[i].tl(), 3, 1.2, (0, 0, 225), 2, 0);
		}
		imshow("frame", frame);
		int c=waitKey(100);
		if (c == 27) break;
	}
	return 0;
}
