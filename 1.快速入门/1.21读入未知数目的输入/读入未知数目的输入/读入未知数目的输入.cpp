#include<iostream>
int main()
{
	int sum=0,value;//变量的定义和初始化
	std::cout<<"本程序实现未知数目输入的累加"<<std::endl;
	std::cout<<"输入一些整数数.然后以‘ctrl+z’结束"<<std::endl;
	while(std::cin>>value)//函数实现;while语句
	{sum+=value;}
	std::cout<<"the sum is:"<<sum<<std::endl;
	system("pause");
	return 0;
	}