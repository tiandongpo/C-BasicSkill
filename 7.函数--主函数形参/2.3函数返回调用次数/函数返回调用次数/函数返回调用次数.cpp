//编写函数，使其在第一次调用时返回0,然后再次调用是按顺序产生正整数（返回当前调用次数）
#include<iostream>
using namespace std;
size_t count_calls()
{
	static size_t ctr = -1;//ctr的生命周期将跨越函数的多次调用
	return ++ctr;
}
int main()
{
	for(size_t i=0;i!=10;++i)
		cout<<count_calls()<<endl; 
	system("pause");
	return 0;
}