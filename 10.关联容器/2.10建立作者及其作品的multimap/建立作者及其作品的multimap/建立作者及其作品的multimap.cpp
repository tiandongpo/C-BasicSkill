//�������ߺ���Ʒ��multimap
//ʹ��find������multimap�в���Ԫ�أ�������erase����ɾ��
//����Ѱ�ҵ�Ԫ�ز�����ʱ��������Ȼ����ȷִ��
#include<iostream>
#include<map>
#include<string>
using namespace std;

int main()
{
	multimap<string,string> authors;
	string author,work,searchitem;


	//�������ߺ���Ʒ��multimap����
	do
	{
		cout<<"enter author name(ctrl+z to end):"<<endl;
		cin>>author;

		if(!cin)
			break;

		cout<<"enter author's works(ctrl+z to end):"<<endl;
		while(cin>>author)
			authors.insert(make_pair(author,work));
		cin.clear();//������һλ���ߵ�������Ʒ��ʹ������������Ч
	}
	while(cin);
		cin.clear();//ʹ������������Ч


		//����Ҫ���ҵĵ�����
		cout<<"who is the author that you want erase:"<<endl;
		cin>>searchitem;

		//�ҵ������߶�Ӧ�ĵ�һ��Ԫ��
		multimap<string,string>::iterator iter = authors.find(searchitem);

		if(iter!=authors.end())
			//ɾ�������ߵ�������Ʒ
			authors.erase(searchitem);
		else
			cout<<"cannot find this author!"<<endl;
		//���multimap����
		cout<<"author\t\twork:"<<endl;
		for(iter=authors.begin();iter!=authors.end();++iter)
			cout<<iter->first<<"\t\t"<<iter->second<<endl;
		system("pause");
		return 0;
}
