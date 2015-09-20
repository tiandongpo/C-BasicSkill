#include<iostream>
int main()
{
	int base,exponent;//定义变量并且初始化
	long result =1;
	std::cout<<"本程序实现求一个底数的指数次方的值"<<std::endl;
	std::cout<<"enter base and expant:"<<std::endl;
	std::cin>>base>>exponent;
	 
	if(exponent<0)//函数实现：if语句和for循环
	{std::cout<<"exponent cannont be smaller than 0"<<std::endl;
	return -1;
	}
	if(exponent>=0)
	{for(int cnt = 1;cnt<=exponent;++cnt)
	result *=base;
	}
	std::cout<<base<<"raised to the power of"<<exponent<<":"<<result<<std::endl;
	system("pause");
	return 0;
}