#include<iostream>
#include<map>
#include<string>
using namespace std;

int main()
{
	multimap<string,string> authors;
	string author,work,searchitem;

	do
	{
		cout<<"enter author name(ctrl+z to end):"<<endl;
		cin>>author;

		if(!cin)
			break;

		cout<<"enter author's works(ctrl+z to end):"<<endl;
		while(cin>>work)
			authors.insert(make_pair(author,work));

		cin.clear();
	}
	while(cin);
	//���multimap����
	typedef multimap<string,string>::iterator ittype;
	ittype iter=authors.begin();
	if(iter==authors.end())//multimap����Ϊ��
	{
		cout<<"empty multimap!"<<endl;
		return 0;
	}
	string  currauthor,preauthor;//���ʵ�ǰ���ߺ�ǰһ����
	do
	{
		currauthor = iter->first;

		if(preauthor.empty()||currauthor[0]!=preauthor[0])
			//�������������ĸ��ͬ�����ߣ����������ĸ
			cout<<"author names beginning with '"<<iter->first[0]<<" '; "<<endl;
		//�������
		cout<<currauthor;
        //��������ߵ�������Ʒ
		pair<ittype,ittype> pos = authors.equal_range(iter->first);
		while(pos.first != pos.second)
		{
			cout<<" , "<<pos.first->second;
			++pos.first;
		}

		//���һ�����ߵ�������Ʒ�󣬻���
		cout<<endl;

		iter = pos.second;//iterָ����һ����
		preauthor = currauthor;//����ǰ������Ϊǰһ����
	}
	while(iter != authors.end());
	return 0;
}