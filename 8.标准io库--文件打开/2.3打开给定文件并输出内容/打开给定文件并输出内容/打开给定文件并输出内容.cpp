#include"get.h"
#include<iostream>
#include<fstream>
#include<string>
using namespace std;

ifstream& open_file(ifstream &in,const string &file)
{
	in.close();//�ر��Է����ѽ��Ǵ򿪵�
	in.clear();//����ڲ�״̬
	in.open(file.c_str());//�򿪸����ļ�
	return in;
}
int main()
{
	string fileName,s;
	//�����ļ���
	cout<<"enter filename:"<<endl;
	cin>>fileName;
	//����open_file�������ļ�
	ifstream inFile;
	if(!open_file(inFile,fileName.c_str()))
	{
		cout<<"error:can not open file:"
		<<fileName<<endl;
	return -1;
	}
	//����get������ȡ�ļ�
	get(inFile);
	//�ر��ļ�
	inFile.close();
	system("pause");
	return 0;
}