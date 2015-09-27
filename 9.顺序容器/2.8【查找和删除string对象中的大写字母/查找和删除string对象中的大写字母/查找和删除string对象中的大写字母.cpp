#include<iostream>
#include<string>
#include<cctype>
using namespace std;

int main()
{
	string str="this IS A example";
	for(string::iterator iter=str.begin();iter!=str.end();++iter)
	{
		if(isupper(*iter))
		{
			str.erase(*iter);
			--iter;
		}
	}
	for(string::iterator iter=str.begin();iter!=str.end();++iter)
	{
		cout<<*iter;
	}
	system("pause");
	return 0;
}