//����һ������������Ȼ���õ������������е�ֵ��Ϊ����
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