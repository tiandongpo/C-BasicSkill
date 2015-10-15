//建立作者和作品的multimap
//使用find函数在multimap中查找元素，并调用erase将其删除
//当所寻找的元素不存在时，程序依然能正确执行
#include<iostream>
#include<map>
#include<string>
using namespace std;

int main()
{
	multimap<string,string> authors;
	string author,work,searchitem;


	//建立作者和作品的multimap容器
	do
	{
		cout<<"enter author name(ctrl+z to end):"<<endl;
		cin>>author;

		if(!cin)
			break;

		cout<<"enter author's works(ctrl+z to end):"<<endl;
		while(cin>>author)
			authors.insert(make_pair(author,work));
		cin.clear();//读入了一位作者的所有作品后使流对象重新有效
	}
	while(cin);
		cin.clear();//使流对象重新有效


		//读入要查找的的作者
		cout<<"who is the author that you want erase:"<<endl;
		cin>>searchitem;

		//找到该作者对应的第一个元素
		multimap<string,string>::iterator iter = authors.find(searchitem);

		if(iter!=authors.end())
			//删除该作者的所有作品
			authors.erase(searchitem);
		else
			cout<<"cannot find this author!"<<endl;
		//输出multimap对象
		cout<<"author\t\twork:"<<endl;
		for(iter=authors.begin();iter!=authors.end();++iter)
			cout<<iter->first<<"\t\t"<<iter->second<<endl;
		system("pause");
		return 0;
}
