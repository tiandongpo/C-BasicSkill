//定义一个map对象，元素的键值是家族姓氏，值是存储该家族孩子名字的vector对象 ，
//为这个map对象输入至少6个条目，通过基于家族姓氏的查询检测你的程序，查询应该
//输出该家族所有孩子的姓名
#include<iostream>
#include<map>
#include<vector>
#include<string>

using namespace std;


int main()
{
	map<string,vector<pair<string,string> > > children;
	string surname,childname,birthday;

	//读入条目（家族姓氏及其所有孩子的名字）
	do
	{
		cout<<"enter surname(ctrl+z to end):"<<endl;
		cin>>surname;
		if(!cin)//输入结束
			break;

		//插入新条目
		vector<string> chd;
		pair<map<string,vector<pair<string,string> > >::iterator,bool>ret=children.insert(make_pair(surname,chd));

		if(!ret.second)//该家族姓氏已在map容器中存在
		{
			cout<<"repeated surname:"<<surname<<endl;
		continue;
		}

		cout<<"enter children's name and birthday(ctrl+z to end):"<<endl;
		while(cin>>childname>>birthday)//读入该家族所有孩子的姓名
			ret.first->second.push_back(make_pair(childname,birthday));
		cin.clear();//使输入流重新有效
	}
	while(cin);

	cin.clear();//使输入流重新有效

    //输入要查询的家族
	cout<<"enter a surname to search:"<<endl;
	cin>>surname;

	//根据读入的家族姓氏进行查找
	map<string,vector<pair<string,string> > >::iterator iter = children.find(surname);

	//输出查询结果
	if(iter==children.end())
		cout<<"no this surname:"<<surname<<endl;//找不到该家族的姓氏
	else
	{//找到了该家族的姓氏
		cout<<"children\t\tbirthday:"<<endl;
		//输出该家族中所有孩子的姓名和生日
	    vector<pair<string,string> >::iterator it= iter->second.begin();
		while(it!=iter->second.end())
			cout<<it->first<<"\t\t"<<it->second<<endl;
		it++;
	}
	system("pause");
	return 0;
}
