//��ȡһϵ��int���������������Ǵ洢��vector������
//Ȼ����algorihemͷ�ļ��ж������Ϊcount�ĺ���
//ͳ��ĳ��ָ����ֵ���ֵĴ���
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int main()
{
	int ival,searchvalue;
	vector<int> ivec;

	//����int�����ݲ��洢��vector�����У�ֱ�������ļ�������
	cout<<"enter some integers(ctrl+z to en):"<<endl;
	while(cin>>ival)
		ivec.push_back(ival);
	
	cin.clear();//ʹ������������Ч

	//������ͳ������ִ�����intֵ
	cout<<"enter an integer you want to search:"<<endl;
	cin>>searchvalue;

	//ʹ��count����ͳ�Ƹ�ֵ���ֵĴ�����������
	cout<<count(ivec.begin(),ivec.end(),searchvalue)
		<<"elements in the vector hava value"
		<<searchvalue<<endl;

	system("pause");
	return 0;
}