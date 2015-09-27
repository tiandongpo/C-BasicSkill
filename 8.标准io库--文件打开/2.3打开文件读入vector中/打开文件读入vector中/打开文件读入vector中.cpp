/*��д�������ļ��������룬���ļ����ݱ���string���͵�vector�� ÿһ�д洢Ϊ��
vector�����һ��Ԫ��*/
#include<iostream>
#include<fstream>
#include<string>
#include<vector>
using namespace std;

int fileToVector(string fileName,vector<string>& svec)

{    //����ifstream����inFile���󶨵����β�fileNameָ�����ļ�
	ifstream inFile(fileName.c_str());
	if(!inFile)//���ļ�ʧ��
		return 1;


	//���ļ����ݶ��뵽string���͵�vector����
	//ÿһ�д洢Ϊ�����������һ��Ԫ��
	string s;
	while(getline(inFile,s))
		svec.push_back(s);
	inFile.close();//�ر��ļ�
	if(inFile.eof())//�����ļ�������
		return 4;
	if(inFile.bad())//����ϵͳ������
		return 2;
	if(inFile.fail())//��������ʧ��
		return 3;
}
int main()
{	vector<string> svec;
    string fileName,s;

	//�����ļ���
	cout<<"enter filename:"<<endl;
	cin>>fileName;

    //�����ļ�
	switch(fileToVector(fileName,svec))
	{
	case 1:
		cout<<"error:can not open file:"
			<<fileName<<endl;
		return -1;
	case 2:
		cout<<"error:system failure"<<endl;
		return -1;
	case 3:
		cout<<"error:read failure"<<endl;
		return -1;
	}

	//���vector������м���
	cout<<"vector:"<<endl;
	for(vector<string>::iterator iter = svec.begin();
    iter != svec.end();++iter)
	cout<<*iter<<endl;
	system("pause");
	return 0;
}
