//����һ��vector������ÿ��Ԫ�ض���ָ��string���͵�ָ��
//��ȡ��vector�������ÿ��string�����ݼ�����Ӧ�ĳ���
#include<iostream>
#include<string>
#include<vector>
using namespace std;
int main()
{
	vector<string*> spvec;
	//��ȡvector����
	string str;
	cout<<"enter some strings(ctr+z to end):"<<endl;
	while(cin>>str)
	 { string *pstr = new string;//ָ��string�����ָ��
	  *pstr = str;
	spvec.push_back(pstr);
	}
   //���ÿ��string�����ݻ�����Ӧ�ĳ���
	vector<string*>::iterator iter = spvec.begin();
	while(iter!=spvec.end())
	{
		cout<<**iter<<(**iter).size()<<endl;
		iter++;
	}
	//�ͷŸ�����̬�����string����
	iter = spvec.begin();
	while(iter!=spvec.end())
	{
		delete *iter;
		iter++;
	}
	system("pause");
	return 0;
}
