//读入文本文件，使用标准库函数对象greater_equal,
//统计长度在10以上（含10）的单词的数目
#include<iostream>
#include<fstream>
#include<vector>
#include<algorithm>
#include<string>
#include<functional>
using namespace std;


    //用于将单词按长度排序的比较函数
	bool isShort(const string  &s1,const string &s2)
	{
		return s1.size() <s2.size();
	}


	//如果ctr不为1，返回word的复数版本
	string make_plural(size_t ctr,const string &word,const string &ending)
	{
		return(ctr==1)?word:word+ending;
	}


	//main函数接受文件名为参数
	int main(int argc,char **argv)
	{   

		//检查命令行参数个数
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
			cerr<<"no input file!"<<endl;
			return EXIT_FAILURE;
		}

		vector<string> words;
		string word;

		//读入要分析的输入序列，并存放在vector容器中
		while(inFile>>word)
			words.push_back(word);

		//对输入排序以便去除重复的单词
		sort(words.begin(),words.end());

		//使用unique算法对元素重新排序并返回一个迭代器
		//表示无重复的单词范围结束
		//erase操作使用该迭代器删除输入序列中重复的单词
		words.erase(unique(words.begin(),words.end()),words.end());


		//计算并输出长度在10以上（含10）的单词的数目
		//因为没有可用于直接比较字符串长度的标准库函数
		//所以greater_equal对象循环实现但系计数
		vector<string>::size_type wc = 0;
		greater_equal<string::size_type> greq;
		for(vector<string>::iterator iter = words.begin();iter != words.end();++iter)
		{
			if(greq(iter ->size(),10))
			{
				++wc;
			}
		}

		cout<<wc<<" "<<make_plural(wc,"word","s")
			<<"10 charaters or longer"<<endl;

		system("pause");
		return 0;
	}
