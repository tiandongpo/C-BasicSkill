//��������ֵuplmt,���(1...uplmt)֮�����������Ľ׳�
#include<iostream>
using namespace std;

//���ڸ�����׳˵ĺ���
int fac(int x)//xΪ�β�
{
	int static result = 1;//result Ϊ��̬�ֲ�����
	result *=x;
	return result;
}
int main()
{
	int uplmt;//uplmtΪ��ͨ���Ǿ�̬���ֲ�����
	cout<<"enter value of upper limit:"<<endl;
	cin>>uplmt;

	//�������[1...uplmt]֮������������Ľ׳�
	for(int i = 1;i<=uplmt;++i)
		cout<<i<<"!="<<fac(i)<<endl;
	system("pause");
	return 0;
}