#include<iostream>
#include<stack>
#include<string>
using namespace std;

int main()
{
	stack<char> sexp;
	string exp;

	cout<<"enter  a  expression:"<<endl;
	cin>>exp;

	string::iterator iter = exp.begin();
	while(iter != exp.end())
	{
		if(*iter!=')')//读到的字符不是右圆括号
			sexp.push(*iter);
		else
		{   //读到的字符是右圆括号，弹出元素，直到栈顶为左圆括号或栈为空
			while(sexp.top()!='(' &&!sexp.empty())
			{
				sexp.pop();
			}
			if(sexp.empty())//栈为空
				cout<<"parentheses are not matched"<<endl;
			else
			{//栈顶为左圆括号
				sexp.pop();
				sexp.push('@');
			}
			++iter;
		}
		
	}
	
	system("pause");
		return 0;
}

