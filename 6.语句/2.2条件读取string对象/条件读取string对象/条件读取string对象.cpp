/*编写程序从标准输入一系列string对象，直到同一个单词连续出现两次，或者所有的单词都已经读完，才结束读取。请使用while循环，每次
读取一个单词。如果连续出现相同的单词，便以break语句结束循环，此时，请输出这个重复出现的单词；否则输出没有任何单词连续出现的信息；*/
#include<iostream>
#include<string>
using namespace std;
int main()
{
	string currword,preword;//记录当前单词和前一单词
	cout<<"enter some words:(ctrl+z to end  every word end with enter)"<<endl;
	while(cin>>currword)
	{ 
		if(currword==preword)//当前单词重复出现
			break;
		else
			preword=currword;
	}
	//输出结果
	if(currword==preword&&!currword.empty())//若要只寻找大写字母开头的连续出现的单词，则改为if(currword==preword&&isupper(currword[0])
		cout<<"the repeated word:"<<currword<<endl;
	else
		cout<<"there is no repeated word."<<endl;
	system("pause");
	return 0;
}