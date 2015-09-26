/*编写程序求vector<double>对象中所有元素之和*/
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
	//读入vector元素之和
	cout<<"enter double type elements for vector:(ctrl+z to end)"<<endl;
	double dval;
	while(cin>>dval)
		dvec.push_back(dval);
	//求元素之和并输出
	cout<<"summation of elements:"<<vectorsum(dvec.begin(),dvec.end())<<endl;
	system("pause");
	return 0;
}
