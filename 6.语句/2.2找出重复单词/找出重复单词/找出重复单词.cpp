/*编写一个小程序，从标准输入读入一系列的string对象，寻找连续重复出现的单词。程序应该中啊处满足以下
条件的单词的输入位置：该单词的后面紧跟着再次出现自己本身。跟踪重复次数最多的单词机器重复次数。输出重复次数的
最大值，若没有单次重复则输出说明信息。例如，如果输入是：how ,now now now brown cow cow
则输出应该表明”now“这个单词出现了三次*/
#include<iostream>
#include<string>
using namespace std;
 
int main()
{
	string preword,currword;//当前输入的单词机器前一单词
	string repword;//重复次数最多的单词
	int currcnt=0,maxcnt=1;//当前单词的重复次数及单词重复次数的最大值

	cout<<"enter some words(ctrl+z to end)"<<endl;
	while(cin>>currword)
	{
		if(currword==preword)//当前单词是重复出现
		    ++currcnt;
		else//当前单词不是重复出现
		{
			if(currcnt > maxcnt)//出现了重复次数更多的单词
			{
				maxcnt = currcnt;
				repword = preword;
			}
			currcnt = 1;
		}
		preword = currword;//修改对前一单词的记录
	}
	if(maxcnt!=1)//有单词重复
		cout<<'"'<<repword<<'"'<<"repeater for"<<maxcnt<<"times."<<endl;
	else
	    cout<<"there is no repeated word"<<endl;
	system("pause");
	return 0;
}