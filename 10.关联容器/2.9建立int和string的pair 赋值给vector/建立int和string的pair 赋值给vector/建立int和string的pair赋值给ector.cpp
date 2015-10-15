#include<iostream>
#include<utility>//使用其中的pair类型
#include<vector>
#include<string>
using namespace std;

int main()
{
	pair<string,int> sipr;
	string str;
	int ival;
	vector< pair<string,int> >pvec;

	cout<<"enter a string and an iterget(ctrl+z to end):"<<endl;
	while(cin>>str>>ival)
	{
		sipr = make_pair(str,ival);//生成pair对象
		pvec.push_back(sipr);//将pair对象存储在vector容器中
	}
	system("pause");
	return 0;
}
