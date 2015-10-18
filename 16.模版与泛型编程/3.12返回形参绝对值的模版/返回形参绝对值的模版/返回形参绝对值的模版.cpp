//编写一个模版函数返回形参的绝对值
//用三种不同类型的值调用该模版
#include<iostream>
using namespace std;

template<typename T>
T absVal(T val)
{
	return val>0?val:-val;
}

int main()
{
	double dval = 0.88;
	float fval = -12.3;

	cout<<absVal(-3)<<endl;
	cout<<absVal(dval)<<endl;
	cout<<absVal(fval)<<endl;

	system("pause");
	return 0;
}