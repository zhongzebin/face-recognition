#include "pch.h"
#include <iostream>
#include <opencv.hpp>
#include <stdio.h>
#include <opencv2\face\facerec.hpp>
using namespace std;
using namespace cv;
using namespace cv::face;
void read_csv(string& filename, vector<Mat>& images, vector<int>& labels)//必须取地址，才能将形参传回主函数，改变实参
{
	char separator=';';
	ifstream file(filename);
	string line,path,classlabel;
	while (getline(file, line))//得到文件中的每一行
	{
		stringstream liness(line);
		getline(liness, path, separator);//得到每一行分号前存储的路径
		getline(liness, classlabel);//得到每一行分号后存储的标签
		images.push_back(imread(path, 0));
		labels.push_back(atoi(classlabel.c_str()));//将字符串转化为整数
	}
}
int main()
{
	string fn_csv = "C:\\face\\att_faces\\at.txt";//带标签的路径文件的路径，每行为路径+;+标签
	vector<Mat> images;
	vector<int> labels;
	read_csv(fn_csv, images, labels);
	Ptr<BasicFaceRecognizer> model = EigenFaceRecognizer::create();//创建一个EigenFaceRecognizer训练模型
	model->train(images, labels);//训练
	model->save("MyFacePCAModel.xml");//将训练好的模型存为.xml文件
	return 0;
}
