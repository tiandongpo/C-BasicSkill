//创建string:the child is in the dooryard
#include<iostream>
#include<string>
using namespace std;
 
int main()
{
	string q1("when lilacs last in the dooryard bloom'd");
	string q2("the child is father of the man");
	string sentence;
	//将sentence赋值为“the child is”
	sentence.assign(q2.begin(),q2.begin()+13);
	//在sentence末尾添加“in the dooryard”
	sentence.append(q1.substr(q1.find("in"),15));
	//输出sentence
	cout<<sentence<<endl;

	system("pause");
	return 0;
}