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
		if(*iter!=')')//�������ַ�������Բ����
			sexp.push(*iter);
		else
		{   //�������ַ�����Բ���ţ�����Ԫ�أ�ֱ��ջ��Ϊ��Բ���Ż�ջΪ��
			while(sexp.top()!='(' &&!sexp.empty())
			{
				sexp.pop();
			}
			if(sexp.empty())//ջΪ��
				cout<<"parentheses are not matched"<<endl;
			else
			{//ջ��Ϊ��Բ����
				sexp.pop();
				sexp.push('@');
			}
			++iter;
		}
		
	}
	
	system("pause");
		return 0;
}

