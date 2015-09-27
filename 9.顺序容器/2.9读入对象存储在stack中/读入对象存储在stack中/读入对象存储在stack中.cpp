#include<iostream>
#include<string>
#include<stack>
using namespace std;

int main()
{
	stack<string> sstack;
	string str;

	cout<<"enter some words(ctrl + z to end)"<<endl;
	while(cin>>str)
		sstack.push(str);


	system("pause");
	return 0;
}