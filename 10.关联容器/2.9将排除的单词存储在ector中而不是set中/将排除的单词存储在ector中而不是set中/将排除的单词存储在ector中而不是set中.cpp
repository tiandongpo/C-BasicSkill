#include<iostream>
#include<vector>
#include<fstream>
#include<map>
#include<string>
using namespace std;

void restricted_wc(ifstream &removefile,map<string,int>&wordcount)
{
	vector<string> excluded;//保存被排除的单词
	string removeword;
	while(removefile>>removeword)
		excluded.push_back(removeword);
	//读入文本并对不再排除中的单词进行出现次数统计
	cout<<"enter text(ctrl+z to end):"<<endl;
	string word;
	while(cin>>word)
	{
		bool find = false;

		//确定该段次是否在排除集中
		vector<string>::iterator iter = excluded.begin();
		while(iter!=excluded.end())
		{

			if(*iter==word)
			{
				find=true;
				break;
			}
			++iter;
		}
	//如果单词不在排除集中，则进行计数
	if(!find)
		++wordcount[word];
	}
}
int main()
{
	map<string,int>wordcount;
	string filename;

	//读入单词排除集的文件的名字并打开相应的文件
	cout<<"enter filename:"<<endl;
	cin>>filename;
	ifstream  exfile(filename.c_str());
	if(!exfile)
	{//打开文件失败
		cout<<"error:can not open file:" <<filename<<endl;
		return -1;
	}


	//调用restricted_wc函数
	//对输入文本中不在排除集中中的单词进行出现次数统计

	restricted_wc(exfile,wordcount);


	//输出统计结果
	cout<<"word\t\t"<<"times"<<endl;
	map<string,int>::iterator iter = wordcount.begin();
	while(iter!=wordcount.end())
	{
		cout<<iter->first<<"\t\t"<<iter->second<<endl;
		iter++;
	}
	system("pause");
	return 0;
}

