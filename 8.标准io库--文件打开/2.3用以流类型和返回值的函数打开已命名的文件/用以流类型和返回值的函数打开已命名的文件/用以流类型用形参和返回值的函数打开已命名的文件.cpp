#include<iostream>
#include"ss.h"
#include<fstream>
#include<string>
using namespace std;

int main()
{
	string fileName;
	//�����ļ���
	cout<<"enter file name:"<<endl;
	cin>>fileName;
	//����ifstream���󲢰󶨵���ΪfileName���ļ���
	ifstream inFile(fileName.c_str());
	if(!inFile)//���ƶ��ļ���ʧ��
	{
		cerr<<"error:can not open input file:"
			<<fileName<<endl;
		return -1;
	}
	get(inFile);//��inFileΪʵ�ε��ú���get
	system("pause");
	return 0;
}

