//string���󣺡�ab2c3d7r4e5������д����Ѱ�Ҹ��ַ����е����������ַ�����ĸ�ַ�
#include<iostream>
#include<string>
using namespace std;

int main()
{
	string str = "ab2c3d7R4E6";
	string numerics("0123456789");
	string letters("abcdefghijklmnopqrstuvwxyz ABCDEFGHIJILMNOPQRSTUVWXYZ");
	string::size_type pos = 0;

	//����find_first_of������pos��λ����һ���������ֵ�λ��

	while((pos = str.find_first_of(numerics,pos))!=string::npos)
	{
		cout<<"found numbers at index:"<<pos<<"element is"<<str[pos]<<endl;
		++pos;//pos��λ����һ�ַ�
	}



	//����find_first_of������pos��λ����һ��������ĸ��λ��
	while((pos = str.find_first_of(letters,pos))!=string::npos)
	{
		cout<<"found letter at index:"<<pos<<"element is"<<str[pos]<<endl;
		++pos;
	}
system("pause");
return 0;
}
