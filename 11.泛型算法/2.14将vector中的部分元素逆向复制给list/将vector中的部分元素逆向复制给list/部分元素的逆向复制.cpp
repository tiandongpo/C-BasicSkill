//将存储了10个元素的vector容器中的3~7位的元素逆向复制给list
#include<iostream>
#include<vector>
#include<list>
#include<algorithm>
using namespace std;

int main()
{
	int ia[]={1,2,3,4,5,6,7,8,9,10};
	vector<int> ivec(ia,ia+10);
	list<int> ilst;
	vector<int>::reverse_iterator rstart,rend;


	rstart = ivec.rbegin();
	for(int cnt1 = 1;cnt1 != 4;++cnt1)
		++rstart;

	rend=rstart;
	for(int cnt2 = 1;cnt2 != 6;++cnt2)
		++rend;

	copy(rstart,rend,inserter(ilst,ilst.begin()));

	for(list<int>::iterator iter = ilst.begin();iter!=ilst.end();++iter)
		cout<<*iter<<endl;

	system("pause");
	return  0;
}