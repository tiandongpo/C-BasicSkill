//��д�������һ��string���͵����ݣ��������Ǵ洢��vector�С����ţ���vector�����Ƹ�һ���ַ�ָ�����顣Ϊvector�е�ÿһ��Ԫ�ش���һ���µ�
//�ַ����飬���Ѹ�vectorԪ�ص����ݸ��Ƶ���Ӧ���ַ������У�����ָ����������ָ������ַ�ָ�����顣
#include<iostream>
#include<string>
#include<vector>
using namespace std;
int main()
{
	vector<string> svec;
	string str;
	//����vectotԪ��
	cout<<"enter strings:(ctr+z to end)"<<endl;
	while(cin>>str)
		svec.push_back(str);
	//�����ַ�ָ������
	char **parr = new char *[svec.size()];
	 //����vectorԪ��
	size_t ix = 0;
	for(vector<string>::iterator iter = svec.begin();
		iter!=svec.end();++iter,++ix)
	{   //�����ַ�����
		char *p = new char[(*iter).size()+1];
		//����vectorԪ�ص����ݵ��ַ�����
		strcpy(p,(*iter).c_str());
		//��ָ����ַ������ָ����뵽�ַ�ָ������
		parr[ix] = p;

	}
	//�ͷŸ����ַ�����
	for (ix=0;ix!=svec.size();++ix)
		delete[] parr[ix];
	//�ͷ��ַ�ָ������
	delete[] parr;
	system("pause");
	return 0;
}


