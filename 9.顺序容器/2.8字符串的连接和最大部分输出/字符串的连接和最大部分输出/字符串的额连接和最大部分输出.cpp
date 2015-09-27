//string line1 = "we were pride of 10 she named us:"  string line2="benjamin,phoenix,the prodigal";string line3= "and perspocacious pacific suzanne";
//string sentence=line1+' '+line2+' '+line3  计算sentence中的单词数，输出最长最短单词
//定义代表分隔符集合的string对象separators,使用find_first_of和find_first_not_of函数来获取单词的初始位置和结束位置；
//使用两个vector对象存放最长和最短单词
#include<iostream>
#include<string>
#include<vector>
using namespace std;
int main()
{
	string line1 = "we were her pride of 10 she named us:";
	string line2= "benjamin，phoneix,the prodigal";
	string line3= "and perspicacious pacific suzuanne";
	string sentence = line1+' '+line2+' '+line3;
    string separators("\t:,\v\r\n\f");//用做分隔符的字符
	string word;


	//string中最长，最短单词以及下一单词的长度，单词的数目
	string::size_type maxlen,minlen,wordlen,count=0;
	//存放最长和最短单词的容器
	vector<string>longestwords,shortestwords;
    //单词的起始位置和结束位置
	string::size_type startpos = 0,endpos= 0;
	//每次循环处理sentence中的一个单词
	while((startpos = sentence.find_first_not_of(separators,endpos))!=string::npos)
{  //找到下一个单词的起始位置
		++count;
		//找到一个单词的结束位置
		endpos = sentence.find_first_of(separators,endpos);
		if(endpos==string::npos)
		{
     //找不到下一个出现分隔符的位置，即该单词是最后一个单词  
	  		wordlen=sentence.size()-startpos;
		}
		else
		{//找到了下一个出现分隔符的位置
			wordlen = endpos - startpos;
		}

	
	     word.assign(sentence.begin()+startpos,sentence.begin()+startpos+wordlen);//获取单词
	     //设置下次查找的起始位置
	     startpos = sentence.find_first_not_of(separators,endpos);

 
    	if(count==1)
	{//找到的是第一个单词
		maxlen=minlen=wordlen;
		longestwords.push_back(word);
		shortestwords.push_back(word);
	}
	else
	{
		if(wordlen>maxlen)
		{//当前单词比目前的最长单词更长
			maxlen=wordlen;
			longestwords.clear();//清空存储最长单词的容器
			longestwords.push_back(word);
		}
		else if(wordlen==maxlen)//当前单词比目前的最长单词等长
			longestwords.push_back(word);
		if(wordlen<minlen)//当前单词比目前的最短单词更短
		{
			minlen=wordlen;
			shortestwords.clear();//清空存放最短单词的容器
			shortestwords.push_back(word);
		}
		else if(wordlen==minlen)//当前单词与目前的最短单词等长
			shortestwords.push_back(word);
	}
}

	//输出单词数目
	cout<<"word amount:"<<count<<endl;
	vector<string>::iterator iter;
	//输出最长单词
	cout<<"longest word(s):"<<endl;
	iter = longestwords.begin();
	while(iter!=longestwords.end())
		cout<<*iter++<<endl;
	//输出最短单词
	cout<<"shortest word(s):"<<endl;
	iter = shortestwords.begin();
	while(iter!=shortestwords.end())
		cout<<*iter++<<endl;
	system("pause");
	return 0;
}