//读取一系列int型整数，并将他们存储到vector对象中
//然后使用algorithem头文件中名为accumulate的函数，
//统计vector对象中的元素之和
#include<iostream>
#include<vector>
#include<numeric>
using namespace std;
 
int main()
{
	int ival;
	vector<int> ivec;

	//读入int型整数并存储到vector中，直至遇到文件结束符
	cout<<"enter some integers(ctrl+z to end):"<<endl;
	while(cin>>ival)
		ivec.push_back(ival);

	//使用accumulate函数统计vector中元素之和并输出结果
	cout<<"summation of element in the vector:"
		<<accumulate(ivec.begin(),ivec.end(),0)
		<<endl;

	system("pause");
	return 0;
}