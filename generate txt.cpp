#include "pch.h"
#include <iostream>
#include<fstream>
#include<string>
using namespace std;
int main()
{
	ofstream outfile("at.txt");
	for (int i = 1; i <= 40; i++)
	{
		for (int j = 1; j <= 10; j++)
		{
			string s1 = to_string(i);
			string s2 = to_string(j);
			outfile << "C:\\face\\att_faces\\s";
			outfile << s1;
			outfile << '\\';
			outfile << s2;
			outfile << ".pgm";
			outfile << ';';
			outfile << s1;
			outfile << '\n';
		}
	}
	for(int i=41;i<=41;i++)
	for (int j = 1; j <= 100; j++)
	{
		string s1 = to_string(i);
		string s2 = to_string(j);
		outfile << "C:\\face\\att_faces\\s";
		outfile << s1;
		outfile << '\\';
		outfile << s2;
		outfile << ".jpg";
		outfile << ';';
		outfile << s1;
		outfile << '\n';
	}
	int i = 42;
	for (int j = 1; j <= 50; j++)
	{
		string s1 = to_string(i);
		string s2 = to_string(j);
		outfile << "C:\\face\\att_faces\\s";
		outfile << s1;
		outfile << '\\';
		outfile << s2;
		outfile << ".jpg";
		outfile << ';';
		outfile << s1;
		outfile << '\n';
	}
	for (int j = 236; j <= 285; j++)
	{
		string s1 = to_string(i);
		string s2 = to_string(j);
		outfile << "C:\\face\\att_faces\\s";
		outfile << s1;
		outfile << '\\';
		outfile << s2;
		outfile << ".jpg";
		outfile << ';';
		outfile << s1;
		outfile << '\n';
	}
	return 0;
}
