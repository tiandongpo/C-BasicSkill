//ʹ��replace��һ��vector�����е����и��Ƹ�һ��list����
//����ǰһ�������и�����ֵ�滻Ϊָ������ֵ
//�ֱ�ʹ��inserter��back_inserter��front_inserterʵ��
#include<iostream>
#include<list>
#include<vector>
#include<algorithm>
using namespace std;

int main()
{
	int ia[]={1,2,3,4,100,5,100};
	vector<int> ivec(ia,ia+7);
	list<int> ilst;


	//��ivec���Ƹ�ilst������ivec�е�ֵΪ100��Ԫ���滻Ϊ��ֵ
	//ʹ��inserterʵ��
	replace_copy(ivec.begin(),ivec.end(),inserter(ilst,ilst.begin()),100,0);


    //ʹ��back_inserterʵ��
	//replace_copy(ivec.begin(),ivec.end(),back_inserter(ilst),100,0);

	//ʹ��front_inserterʵ��
	//replace_copy(ivec.begin(),ivec.end(),front_inserter(ilst),100,0);

	cout<<"list:"<<endl;
	for(list<int>::iterator iter= ilst.begin();iter!=ilst.end();++iter)
		cout<<*iter<<" ";
	cout<<endl;
	 
	system("pause");
	return 0;
}