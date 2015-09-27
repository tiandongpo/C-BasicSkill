//将list中的奇数 偶数分贝存储在两个deque中
#include<iostream>
#include<list>
#include<deque>
#include<string>
using namespace std;

int main()
{
	list<int> ilst;
	deque<int> evenDq,oddDq;
	int ival;
	//读入int对象并存储在list对象中
	cout<<"enter some integers(ctrl+z to end):"<<endl;
	while(cin>>ival)
		ilst.push_back(ival);


	//复制list对象的元素至合适的deque对象中
	for(list<int>::iterator iter= ilst.begin();iter!=ilst.end();++iter)
	{
		if(*iter%2==0)
			evenDq.push_back(*iter);
		else
			oddDq.push_back(*iter);
	}
    //输出deque对象进行确认
	deque<int>::iterator it;
	//输出存放偶数的deque对象
	it=evenDq.begin();
	cout<<"even deque:"<<endl;
	while(it!=evenDq.end())
	{
		cout<<*it<<" ";
		++it;
	}
	cout<<endl;


	//输出存放奇数的deque对象
	it = oddDq.begin();
	cout<<"odd deque:"<<endl;
	while(it != oddDq.end())
	{
		cout<<*it<<" ";
		++it;
	}
	cout<<endl;
	system("pause");
	return 0;
}
	