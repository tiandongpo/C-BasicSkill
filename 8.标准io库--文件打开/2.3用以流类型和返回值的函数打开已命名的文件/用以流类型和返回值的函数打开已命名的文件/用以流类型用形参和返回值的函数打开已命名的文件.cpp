#include<iostream>
#include"ss.h"
#include<fstream>
#include<string>
using namespace std;

int main()
{
	string fileName;
	//读入文件名
	cout<<"enter file name:"<<endl;
	cin>>fileName;
	//创建ifstream对象并绑定到名为fileName的文件夹
	ifstream inFile(fileName.c_str());
	if(!inFile)//打开制定文件夹失败
	{
		cerr<<"error:can not open input file:"
			<<fileName<<endl;
		return -1;
	}
	get(inFile);//以inFile为实参调用函数get
	system("pause");
	return 0;
}

