#include<iostream>
#include<list>
#include<vector>
#include<algorithm>
using namespace std;

int main()
{
	int ia[]={1,2,3,4,100,5,100};
	list<int> ilst(ia,ia+7);
	vector<int> ivec;


	//��list����ilst�в��ظ���Ԫ�ظ��Ƶ��յ�vector����ivec��
	unique_copy(ilst.begin(),ilst.end(),back_inserter(ivec));

	//���vector����
	cout<<"vector"<<endl;
	for(vector<int>::iterator iter=ivec.begin();iter!=ivec.end();++iter)
		cout<<*iter<<" ";
	cout<<endl;


	system("pause");
	return 0;
}