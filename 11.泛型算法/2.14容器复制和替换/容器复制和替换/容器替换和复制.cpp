//使用replace将一个vector容器中的序列复制给一个list容器
//并将前一个序列中给定的值替换为指定的新值
//分别使用inserter，back_inserter和front_inserter实现
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


	//将ivec复制给ilst，并将ivec中的值为100的元素替换为零值
	//使用inserter实现
	replace_copy(ivec.begin(),ivec.end(),inserter(ilst,ilst.begin()),100,0);


    //使用back_inserter实现
	//replace_copy(ivec.begin(),ivec.end(),back_inserter(ilst),100,0);

	//使用front_inserter实现
	//replace_copy(ivec.begin(),ivec.end(),front_inserter(ilst),100,0);

	cout<<"list:"<<endl;
	for(list<int>::iterator iter= ilst.begin();iter!=ilst.end();++iter)
		cout<<*iter<<" ";
	cout<<endl;
	 
	system("pause");
	return 0;
}