#include<iostream>
#include<vector>
#include<fstream>
#include<map>
#include<string>
using namespace std;

void restricted_wc(ifstream &removefile,map<string,int>&wordcount)
{
	vector<string> excluded;//���汻�ų��ĵ���
	string removeword;
	while(removefile>>removeword)
		excluded.push_back(removeword);
	//�����ı����Բ����ų��еĵ��ʽ��г��ִ���ͳ��
	cout<<"enter text(ctrl+z to end):"<<endl;
	string word;
	while(cin>>word)
	{
		bool find = false;

		//ȷ���öδ��Ƿ����ų�����
		vector<string>::iterator iter = excluded.begin();
		while(iter!=excluded.end())
		{

			if(*iter==word)
			{
				find=true;
				break;
			}
			++iter;
		}
	//������ʲ����ų����У�����м���
	if(!find)
		++wordcount[word];
	}
}
int main()
{
	map<string,int>wordcount;
	string filename;

	//���뵥���ų������ļ������ֲ�����Ӧ���ļ�
	cout<<"enter filename:"<<endl;
	cin>>filename;
	ifstream  exfile(filename.c_str());
	if(!exfile)
	{//���ļ�ʧ��
		cout<<"error:can not open file:" <<filename<<endl;
		return -1;
	}


	//����restricted_wc����
	//�������ı��в����ų������еĵ��ʽ��г��ִ���ͳ��

	restricted_wc(exfile,wordcount);


	//���ͳ�ƽ��
	cout<<"word\t\t"<<"times"<<endl;
	map<string,int>::iterator iter = wordcount.begin();
	while(iter!=wordcount.end())
	{
		cout<<iter->first<<"\t\t"<<iter->second<<endl;
		iter++;
	}
	system("pause");
	return 0;
}

