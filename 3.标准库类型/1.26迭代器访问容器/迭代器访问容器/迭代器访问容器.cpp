//创建一个整数容器。然后用迭代器讲容器中的值改为两倍
#include<iostream>
#include<vector>
using namespace std;
int main()
{
	vector<int> ivec;
	int ival;

	cout<<"enter the numbers(ctrl+z to end)"<<endl;
	while(cin>>ival)
	{ivec.push_back(ival);}

	for(vector<int>::iterator iter =ivec.begin();iter!=ivec.end();++iter)
		{*iter=(*iter)*2;
	cout<<*iter<<endl;}
	system("pause");
	return 0;
}