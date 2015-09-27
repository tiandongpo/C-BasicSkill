//研究标准库对vector对象提供的内存分配策略
#include<iostream>
#include<vector>
using namespace std;

int main()
{
	vector<int> ivec;
	//长度应该为零，容量有实现而定

	cout<<"ivec:size:"<<ivec.size()
		<<"capacity:"<<ivec.capacity()<<endl;

	//添加十个元素
	for(int ix=1;ix!=11;++ix)
	{
		ivec.push_back(ix);

		//长度为ix，容量>=iz,具体由实现而定
		cout<<"ivec:size:"<<ivec.size()
			<<"capacity:"<<ivec.capacity()<<endl;
	}
	//将现有容量用完
	while(ivec.size()!=ivec.capacity())
		ivec.push_back(0);
	//附加一个元素
	ivec.push_back(0);
	//长度应该为原容量+1，容量>=原容量+1，具体由实现而定
	cout<<"ivec:size:"<<ivec.size()
		<<"capacity:"<<ivec.capacity()<<endl;
   
	//将容量设为至少100
	ivec.reserve(100);

	//长度保持不变，容量>=100，具体由实现而定
	cout<<"ivec:size:"<<ivec.size()
		<<"capacity:"<<ivec.capacity()<<endl;
	//将当前容量用完
	while(ivec.size()!=ivec.capacity())
		ivec.push_back(0);
	//容量不变，长度应该与容量相同
	cout<<"ivec:size:"<<ivec.size()
		<<"capacity:"<<ivec.capacity()<<endl;
	//再增加一个元素
	ivec.push_back(42);
	//长度应该加1，容量>=原容量加一，具体由实现而定
	cout<<"ivec:size:"<<ivec.size()
		<<"capacity:"<<ivec.capacity()<<endl;

	system("pause");
	return 0;
}

		