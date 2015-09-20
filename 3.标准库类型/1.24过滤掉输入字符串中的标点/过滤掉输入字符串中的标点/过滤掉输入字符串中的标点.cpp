#include<iostream>
#include<string>
#include<cctype>
using namespace std;
int main()
{
	string s,result_str;
	bool has_punct=false;//用于标记字符串中是否有标点符号
	char ch;
	//输入字符串
	cout<<"enter a string: "<<endl;
	getline(cin,s);
	//处理字符串：去掉其中的标点符号
	for (string::size_type index = 0;index!=s.size();++index)
	{
		ch=s[index];
		if(ispunct(ch))
			has_punct=true;
		else
			result_str+=ch;
	}
	if(has_punct)
		cout<<"result:"<<endl<<result_str<<endl;
	else{
		cout<<"no punctuation character in the string?!"<<endl;
		return -1;
	}
	system("pause");
	return 0;
}











































