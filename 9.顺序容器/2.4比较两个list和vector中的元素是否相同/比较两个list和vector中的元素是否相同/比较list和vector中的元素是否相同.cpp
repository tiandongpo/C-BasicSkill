#include<iostream>
#include<list>
#include<vector>
using namespace std;

int main()
{
	vector<int> ivec;
	list<int> ilst;
	int ival;


	//读入int对象并存储在vector中
	cout<<"enter some integers for vector(ctrl+z to end):"<<endl;
	while(cin>>ival)
		ivec.push_back(ival);
	cin.clear();

	//读入int对象并存储在list中
	cout<<"enter some integers for list(ctrl+z to end):"<<endl;
	while(cin>>ival)
		ilst.push_back(ival);
	
	//比较vector和list对象中对应的元素
	vector<int>::iterator vit=ivec.begin();
	list<int>::iterator lit=ilst.begin();
	while(vit!=ivec.end()&&lit!=ilst.end())
	{
		if(*vit!=*lit)
			break;
		++vit;
		++lit;
	}


	//输出比较结果
	if(vit==ivec.end()&&lit==ilst.end())
		cout<<"the vector contains the same elements as the list."<<endl;
	else
		cout<<"list and vector contains different element."<<endl;
	system("pause");
	return 0;
}



