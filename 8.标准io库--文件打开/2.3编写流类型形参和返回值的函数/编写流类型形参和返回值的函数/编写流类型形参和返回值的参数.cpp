/*��дһ����������Ψһ���βκͷ���ֵ����istream���ͣ��ú�����־��ȡ�����ļ�������Ϊֹ����Ӧ����ȡ�������������׼����У����������ʹ����Ч�������ظ�����
*/
#include<iostream>
using namespace std;

istream& get(istream& in)//�����Ͳ�����Ϊ�������βλ򷵻����ͣ�����ʹ�������͵�ָ�������
{
	int ival;
	while(in>>ival,!in.eof())//�����ļ���������ǰһֱ��������
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
int main()
{
	double dval;
	get(cin);
	cin>>dval;//����ʹ�ûָ������
	cout<<dval<<endl;
    system("pause");
	return 0;
}