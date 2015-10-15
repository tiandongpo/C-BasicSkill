//读取一系列int型整数，并将他们存储到vector对象中
//然后用algorihem头文件中定义的名为count的函数
//统计某个指定的值出现的次数
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int main()
{
	int ival,searchvalue;
	vector<int> ivec;

	//读入int型数据并存储到vector对象中，直至遇到文件结束符
	cout<<"enter some integers(ctrl+z to en):"<<endl;
	while(cin>>ival)
		ivec.push_back(ival);
	
	cin.clear();//使输入流重新有效

	//读入欲统计其出现次数的int值
	cout<<"enter an integer you want to search:"<<endl;
	cin>>searchvalue;

	//使用count函数统计该值出现的次数并输出结果
	cout<<count(ivec.begin(),ivec.end(),searchvalue)
		<<"elements in the vector hava value"
		<<searchvalue<<endl;

	system("pause");
	return 0;
}