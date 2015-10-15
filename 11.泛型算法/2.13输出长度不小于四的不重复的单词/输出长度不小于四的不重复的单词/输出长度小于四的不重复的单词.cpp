//读入文本文件
//统计长度不小于四的单词，并输出序列中不重复的单词
#include<iostream>
#include<fstream>
#include<vector>
#include<algorithm>
#include<string>
using namespace std;


//用于将单词按长度排序的比较函数
bool isshort( const string &s1,const string &s2)
{
	return s1.size()<s2.size();
}


//确定给定单词是否不小于四
bool GT4(const string &s)
{
	return  s.size()>=4;
}


//如果str不为1，则返回word的复数版本
string make_plural(size_t ctr,const string &word,const string &ending)
{
	return (ctr==1)?word:word+ending;
}


//main函数接受文件名为参数
int main(int argc,char **argv)
{   

	//检查命令行参数
	if(argc<2)
	{
		cerr<<"no input file!"<<endl;
		return EXIT_FAILURE;
	}

	//打开输入文件
	ifstream inFile;
	inFile.open(argv[1]);
	if(!inFile)
	{
		cerr<<"can not open input file!"<<endl;
		return EXIT_FAILURE;
	}

	vector<string> words;
	string word;


	//读入要分析的输入序列，并存放在vector容器中
	while(inFile>>word)
		words.push_back(word);

	//对输入排序以便去除重复的单词
	sort(words.begin(),words.end());


	//使用unique对元素重新排序并返回一个迭代器
	//表示无重复的单词的范围的结束
	//erase操作使用该迭代器删除输入序列中重复的单词
	words.erase(unique(words.begin(),words.end()),words.end());


	//将单词按长度排序，等长的单词按字典排序
	stable_sort(words.begin(),words.end(),isshort);


	//计算并输出长度不小于四的单词的数目
	vector<string>::size_type wc = count_if(words.begin(),words.end(),GT4);
	cout<<wc<<" "<<make_plural(wc,"word","s")
		<<"4 characters or longer"<<endl;

	//输出输入序列中不重复的单词
	cout<<"unique words:"<<endl;
	for(vector<string>::iterator iter = words.begin();iter!=words.end();++iter)
		cout<<*iter<<" ";
	cout<<endl;

	system("pause");
	return 0;
}