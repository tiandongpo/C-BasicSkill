#include<iostream>
using namespace std;
istream& get(istream& in)//�����Ͳ�����Ϊ�������βλ򷵻����ͣ�����ʹ�������͵�ָ�������
{
	int ival;
	while(in>>ival,!in.eof())//�����ļ���������ǰ��־��������
	{
		if(in.bad())//����ϵͳ������
			throw runtime_error("IO stream corrupted");
		if(in.fail())//���ֿɻָ�����
		{
			cerr<<"bad data,try again";//��ʾ�û�
			in.clear();//�ָ���
			in.ignore(200,' ');//�������ͷǷ���������
			continue;//������������
		}
		//��������
		cout<<ival<<" ";
	}
	in.clear();

	return in;
}