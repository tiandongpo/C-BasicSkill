/*编写一个带有两个int型形参的函数，产生第一个参数的第二个参数次幂的值。编写程序传递两个int
数值调用该函数，请检查其结果*/
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