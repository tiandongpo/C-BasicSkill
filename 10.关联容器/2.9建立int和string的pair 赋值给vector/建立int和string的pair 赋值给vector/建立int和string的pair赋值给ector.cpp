#include<iostream>
#include<utility>//ʹ�����е�pair����
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
		sipr = make_pair(str,ival);//����pair����
		pvec.push_back(sipr);//��pair����洢��vector������
	}
	system("pause");
	return 0;
}
