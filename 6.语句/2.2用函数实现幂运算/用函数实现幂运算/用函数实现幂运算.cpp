/*��дһ����������int���βεĺ�����������һ�������ĵڶ����������ݵ�ֵ����д���򴫵�����int
��ֵ���øú�������������*/
#include<iostream>
using namespace std;
int power(int x ,int y)
{
	int result = 1;
	for(int loop = 1;loop<=y;++loop)
		result *=x;
	return result;
}
int main()
{
	int xval,yval;
	cout<<"enter two integers(the second one should be equal to or bigger than 0"<<endl;
	cin>>xval>>yval;
	if(yval<0)
	{cout<<"the second integer should be equal to or bigger than 0"<<endl;
	return -1;
	}
	cout<<"result of raising"<<xval
		<<"to the power of"<<yval
		<<"is"<<power(xval,yval)<<endl;
	system("pause");
	return 0;
}