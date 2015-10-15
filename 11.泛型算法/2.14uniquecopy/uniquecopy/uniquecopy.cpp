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


	//将list对象ilst中不重复的元素复制到空的vector对象ivec中
	unique_copy(ilst.begin(),ilst.end(),back_inserter(ivec));

	//输出vector容器
	cout<<"vector"<<endl;
	for(vector<int>::iterator iter=ivec.begin();iter!=ivec.end();++iter)
		cout<<*iter<<" ";
	cout<<endl;


	system("pause");
	return 0;
}