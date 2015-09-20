#include<iostream>
int main()

{
	std::cout<<"本程序实现输出任意两个整数之间的所有整数"<<std::endl;
	std::cout<<"enter two numbers:"<<std::endl;
	int v1,v2;
	std::cin>>v1>>v2;

	int lower,upper;
	if(v1<=v2)
	{lower=v1;upper=v2;}
	else
	{lower=v2;upper=v1;}
	std::cout<<"values of"<<lower<<"to"<<upper<<"inclusive are:"<<std::endl;
	for(int val = lower,count =1;val<=upper;++val,++count)
	{std::cout<<val<<" ";
	if(count % 10==0)
		std::cout<<std::endl;
	}
	system("pause");
	return  0;
}
