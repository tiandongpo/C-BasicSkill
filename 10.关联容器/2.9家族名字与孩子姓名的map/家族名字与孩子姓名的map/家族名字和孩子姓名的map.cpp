//����һ��map����Ԫ�صļ�ֵ�Ǽ������ϣ�ֵ�Ǵ洢�ü��庢�����ֵ�vector���� ��
//Ϊ���map������������6����Ŀ��ͨ�����ڼ������ϵĲ�ѯ�����ĳ��򣬲�ѯӦ��
//����ü������к��ӵ�����
#include<iostream>
#include<map>
#include<vector>
#include<string>

using namespace std;


int main()
{
	map<string,vector<pair<string,string> > > children;
	string surname,childname,birthday;

	//������Ŀ���������ϼ������к��ӵ����֣�
	do
	{
		cout<<"enter surname(ctrl+z to end):"<<endl;
		cin>>surname;
		if(!cin)//�������
			break;

		//��������Ŀ
		vector<string> chd;
		pair<map<string,vector<pair<string,string> > >::iterator,bool>ret=children.insert(make_pair(surname,chd));

		if(!ret.second)//�ü�����������map�����д���
		{
			cout<<"repeated surname:"<<surname<<endl;
		continue;
		}

		cout<<"enter children's name and birthday(ctrl+z to end):"<<endl;
		while(cin>>childname>>birthday)//����ü������к��ӵ�����
			ret.first->second.push_back(make_pair(childname,birthday));
		cin.clear();//ʹ������������Ч
	}
	while(cin);

	cin.clear();//ʹ������������Ч

    //����Ҫ��ѯ�ļ���
	cout<<"enter a surname to search:"<<endl;
	cin>>surname;

	//���ݶ���ļ������Ͻ��в���
	map<string,vector<pair<string,string> > >::iterator iter = children.find(surname);

	//�����ѯ���
	if(iter==children.end())
		cout<<"no this surname:"<<surname<<endl;//�Ҳ����ü��������
	else
	{//�ҵ��˸ü��������
		cout<<"children\t\tbirthday:"<<endl;
		//����ü��������к��ӵ�����������
	    vector<pair<string,string> >::iterator it= iter->second.begin();
		while(it!=iter->second.end())
			cout<<it->first<<"\t\t"<<it->second<<endl;
		it++;
	}
	system("pause");
	return 0;
}
