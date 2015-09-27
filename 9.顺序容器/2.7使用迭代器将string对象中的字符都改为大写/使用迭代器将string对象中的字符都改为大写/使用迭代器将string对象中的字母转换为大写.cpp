#include<iostream>
#include<string>
#include<cctype>
using namespace std;

int main()
{
	string str = "this is a example";
	for(string::iterator iter=str.begin();iter!=str.end();++iter)
{		*iter=toupper(*iter);
	cout<<*iter;
}
	system("pause");
	return 0;
}