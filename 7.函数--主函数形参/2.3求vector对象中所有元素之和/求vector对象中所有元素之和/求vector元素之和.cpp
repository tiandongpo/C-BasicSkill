/*��д������vector<double>����������Ԫ��֮��*/
#include<iostream>
#include<vector>
using  namespace std;
double vectorsum(vector<double>::iterator begin,vector<double>::iterator end)
{
	double sum = 0.0;
	while(begin!=end)
	{
		sum+=*begin++;
	}
	return sum;
}
int main()
{
	vector<double> dvec;
	//����vectorԪ��֮��
	cout<<"enter double type elements for vector:(ctrl+z to end)"<<endl;
	double dval;
	while(cin>>dval)
		dvec.push_back(dval);
	//��Ԫ��֮�Ͳ����
	cout<<"summation of elements:"<<vectorsum(dvec.begin(),dvec.end())<<endl;
	system("pause");
	return 0;
}
