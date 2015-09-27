#include"get.h"
#include<iostream>
#include<fstream>
#include<string>
using namespace std;

ifstream& open_file(ifstream &in,const string &file)
{
	in.close();//关闭以防他已近是打开的
	in.clear();//清除内部状态
	in.open(file.c_str());//打开给定文件
	return in;
}
int main()
{
	string fileName,s;
	//读入文件名
	cout<<"enter filename:"<<endl;
	cin>>fileName;
	//调用open_file函数打开文件
	ifstream inFile;
	if(!open_file(inFile,fileName.c_str()))
	{
		cout<<"error:can not open file:"
		<<fileName<<endl;
	return -1;
	}
	//调用get函数读取文件
	get(inFile);
	//关闭文件
	inFile.close();
	system("pause");
	return 0;
}