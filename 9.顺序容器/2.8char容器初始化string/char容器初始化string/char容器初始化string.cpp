#include<iostream>
#include<string>
#include<vector>
using namespace std;

int main()
{
	vector<char> cvec(10,'a');
	string str(cvec.begin(),cvec.end());
	system("pause");
	return 0;
}