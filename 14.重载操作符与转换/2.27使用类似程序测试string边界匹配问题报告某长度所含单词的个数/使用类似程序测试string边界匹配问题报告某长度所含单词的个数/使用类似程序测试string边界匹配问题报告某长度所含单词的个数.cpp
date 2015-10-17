#include<iostream>
#include<fstream>
#include<vector>
#include<algorithm>
#include<string>
using namespace std;


//用于将单词按长度排序的比较函数
bool isShorter(const string &s1,const string &s2)
{
	return  s1.size()<s2.size();
}


//测试给定的string对象是否与其边界相匹配
class BET_cls
{
public:
	BET_cls(string::size_type len1,string::size_type len2)
	{
		if(len1 < len2)
		{
			minlength = len1;
			maxlength = len2;
		}
		else
		{
			minlength = len2;
			maxlength = len1;
		}
	}

	bool operator () (const string &s)
	{
		return s.size()>=minlength&&s.size()<=maxlength;
	}

private:
	string::size_type minlength;
	string::size_type maxlength;
};

//如果ctr不为1，则返回word的复数版本
string make_plural(size_t ctr,const string &word,const string &ending)
{
	return(ctr==1)?word:word+ending;
}


//main函数接受文件名为参数
int main(int argc,char **argv)
{

	//检查命令行参数个数
	if(argc <2)
	{
		cerr<<"no input file!"<<endl;
		return EXIT_FAILURE;
	}


	//打开输入文件
	ifstream inFile;
	inFile.open(argv[1]);
	if(!inFile)
	{
		cerr<<"can not open input file!<<endl"<<endl;
		return EXIT_FAILURE;
	}

	vector<string> words;
	string word;

	//读入要分析的输入序列，并存放在vector容器中
	while(inFile>>word)
		words.push_back(word);

	//对读入序列排序一边取出重复单词
	sort(words.begin(),words.end());


	//使用算法unique对元素重新排序并返回一个迭代器
	//表示无重复的单词范围的结束
	//erase操作使用该迭代器删除输入序列中重复的单词
	words.erase(unique(words.begin(),words.end()),words.end());


	//将单词按长度排序，等长的单词按字典顺序排序
	stable_sort(words.begin(),words.end(),isShorter);

	//计算并输出长度在1到10之间的单词的数目
	vector<string>::size_type wc = count_if(words.begin(),words.end(),BET_cls(1,10));
	cout<<wc<<" "<<make_plural(wc,"word","s")
		<<"are of sizes 1 through 10 inclusive"<<endl;

	system("pause");
	return 0;
}