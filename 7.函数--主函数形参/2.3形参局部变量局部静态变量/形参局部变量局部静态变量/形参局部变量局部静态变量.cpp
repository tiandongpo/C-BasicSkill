//读入上限值uplmt,输出(1...uplmt)之间所有整数的阶乘
#include<iostream>
using namespace std;

//用于辅助求阶乘的函数
int fac(int x)//x为形参
{
	int static result = 1;//result 为静态局部变量
	result *=x;
	return result;
}
int main()
{
	int uplmt;//uplmt为普通（非静态）局部变量
	cout<<"enter value of upper limit:"<<endl;
	cin>>uplmt;

	//依次输出[1...uplmt]之间的所有整数的阶乘
	for(int i = 1;i<=uplmt;++i)
		cout<<i<<"!="<<fac(i)<<endl;
	system("pause");
	return 0;
}