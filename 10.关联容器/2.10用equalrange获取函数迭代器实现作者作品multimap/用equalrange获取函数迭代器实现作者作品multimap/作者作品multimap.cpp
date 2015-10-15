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
	//输出multimap对象
	typedef multimap<string,string>::iterator ittype;
	ittype iter=authors.begin();
	if(iter==authors.end())//multimap对象为空
	{
		cout<<"empty multimap!"<<endl;
		return 0;
	}
	string  currauthor,preauthor;//几率当前作者和前一作者
	do
	{
		currauthor = iter->first;

		if(preauthor.empty()||currauthor[0]!=preauthor[0])
			//如果出现了首字母不同的作者，则输出首字母
			cout<<"author names beginning with '"<<iter->first[0]<<" '; "<<endl;
		//输出作者
		cout<<currauthor;
        //输出该作者的所有作品
		pair<ittype,ittype> pos = authors.equal_range(iter->first);
		while(pos.first != pos.second)
		{
			cout<<" , "<<pos.first->second;
			++pos.first;
		}

		//输出一个作者的所有作品后，换行
		cout<<endl;

		iter = pos.second;//iter指向下一作者
		preauthor = currauthor;//将当前作者设为前一作者
	}
	while(iter != authors.end());
	return 0;
}