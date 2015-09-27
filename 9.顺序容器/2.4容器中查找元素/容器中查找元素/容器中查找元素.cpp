/*编写一个函数,其形参是一对迭代器和一个int型的数值，实现在迭代器标记的范围内
寻找该int型数值的功能，并返回指向找到的元素的迭代器，确保程序在要寻找的元素
在不存在是也能正确工作*/
#include<iostream>
#include<vector>
using namespace std;

vector<int> ::iterator findInt(vector<int>::iterator beg,vector<int>::iterator end,int ival)
{
	while(beg!=end)
		if(*beg==ival)
			break;
		else
			++beg;
	return beg;
}

int main()
{
	int ia[]={0,1,2,3,4,5,6};
	vector<int>ivec(ia,ia+7);

	cout<<"enter a integer:"<<endl;
	int ival;
	cin>>ival;

	vector<int>::iterator it;
	it= findInt(ivec.begin(),ivec.end(),ival);
	if(it != ivec.end())
		   cout<<ival<<"is a element of the vector."<<endl;
	else
		cout<<ival<<"isn't a element of the vector."<<endl;
	

	system("pause");
	return 0;
}

