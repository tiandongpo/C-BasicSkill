#include<iostream>
#include<string>
#include<cctype>
using namespace std;
int main()
{
	string s,result_str;
	bool has_punct=false;//���ڱ���ַ������Ƿ��б�����
	char ch;
	//�����ַ���
	cout<<"enter a string: "<<endl;
	getline(cin,s);
	//�����ַ�����ȥ�����еı�����
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











































