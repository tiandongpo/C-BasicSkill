//����string:the child is in the dooryard
#include<iostream>
#include<string>
using namespace std;
 
int main()
{
	string q1("when lilacs last in the dooryard bloom'd");
	string q2("the child is father of the man");
	string sentence;
	//��sentence��ֵΪ��the child is��
	sentence.assign(q2.begin(),q2.begin()+13);
	//��sentenceĩβ��ӡ�in the dooryard��
	sentence.append(q1.substr(q1.find("in"),15));
	//���sentence
	cout<<sentence<<endl;

	system("pause");
	return 0;
}