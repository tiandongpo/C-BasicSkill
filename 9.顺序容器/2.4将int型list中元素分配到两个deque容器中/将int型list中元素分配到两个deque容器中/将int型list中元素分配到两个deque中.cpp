//��list�е����� ż���ֱ��洢������deque��
#include<iostream>
#include<list>
#include<deque>
#include<string>
using namespace std;

int main()
{
	list<int> ilst;
	deque<int> evenDq,oddDq;
	int ival;
	//����int���󲢴洢��list������
	cout<<"enter some integers(ctrl+z to end):"<<endl;
	while(cin>>ival)
		ilst.push_back(ival);


	//����list�����Ԫ�������ʵ�deque������
	for(list<int>::iterator iter= ilst.begin();iter!=ilst.end();++iter)
	{
		if(*iter%2==0)
			evenDq.push_back(*iter);
		else
			oddDq.push_back(*iter);
	}
    //���deque�������ȷ��
	deque<int>::iterator it;
	//������ż����deque����
	it=evenDq.begin();
	cout<<"even deque:"<<endl;
	while(it!=evenDq.end())
	{
		cout<<*it<<" ";
		++it;
	}
	cout<<endl;


	//������������deque����
	it = oddDq.begin();
	cout<<"odd deque:"<<endl;
	while(it != oddDq.end())
	{
		cout<<*it<<" ";
		++it;
	}
	cout<<endl;
	system("pause");
	return 0;
}
	