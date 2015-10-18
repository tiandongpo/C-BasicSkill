//��д�������׼find�㷨��ģ�棬��ģ��Ӧ����һ�������βΣ����β��ƶ������βΣ�һ�Ե��������ͣ�
//ʹ����ĺ�����vector<int>��vector<string>�в��Ҹ���ֵ
#include<iostream>
#include<string>
#include<vector>
using namespace std;

template<typename InIt,typename T>
InIt findElem(InIt first,InIt last,const T& val)
{
	while(first!=last)
	{
		if(*first == val)
			return first;
		++first;
	}
	return last;
}

int main()
{
	int ia[] = {1,2,3,4,5,6,7};
	string sa[] = {"this","is","Marry","test","example"};
	vector<int> ivec(ia,ia+7);
	vector<string>svec(sa,sa+5);

	vector<int>::iterator iit;
	if((iit = findElem(ivec.begin(),ivec.end(),6)) != ivec.end())
		cout<<"found this element:"<<*iit<<endl;
	else 
		cout<<"no such element"<<endl;

	vector<string>::iterator sit;
	if((sit = findElem(svec.begin(),svec.end(),"Marry"))!= svec.end())
		cout<<"found this element:"<<*sit<<endl;
	else
		cout<<"no such element"<<endl;
    

	system("pause");
	return 0;
}
