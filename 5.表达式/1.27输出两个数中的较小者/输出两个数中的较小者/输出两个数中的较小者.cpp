#include<iostream>
using namespace std;
int main()

{
	int ival1,ival2;

	cout<<"enter two numbers:"<<endl;
		cin>>ival1>>ival2;
	cout<<"the smaller one is :"<<(ival1>ival2?ival2:ival1)<<endl;
	system("pause");
	return 0;
}
