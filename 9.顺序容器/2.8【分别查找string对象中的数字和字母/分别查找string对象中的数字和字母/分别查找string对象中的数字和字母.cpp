//string对象：“ab2c3d7r4e5”，编写程序寻找该字符串中的所有数字字符和字母字符
#include<iostream>
#include<string>
using namespace std;

int main()
{
	string str = "ab2c3d7R4E6";
	string numerics("0123456789");
	string letters("abcdefghijklmnopqrstuvwxyz ABCDEFGHIJILMNOPQRSTUVWXYZ");
	string::size_type pos = 0;

	//调用find_first_of函数将pos定位到下一个出现数字的位置

	while((pos = str.find_first_of(numerics,pos))!=string::npos)
	{
		cout<<"found numbers at index:"<<pos<<"element is"<<str[pos]<<endl;
		++pos;//pos定位到下一字符
	}



	//调用find_first_of函数将pos定位到下一个出现字母的位置
	while((pos = str.find_first_of(letters,pos))!=string::npos)
	{
		cout<<"found letter at index:"<<pos<<"element is"<<str[pos]<<endl;
		++pos;
	}
system("pause");
return 0;
}
