/*��д����ӱ�׼����һϵ��string����ֱ��ͬһ�����������������Σ��������еĵ��ʶ��Ѿ����꣬�Ž�����ȡ����ʹ��whileѭ����ÿ��
��ȡһ�����ʡ��������������ͬ�ĵ��ʣ�����break������ѭ������ʱ�����������ظ����ֵĵ��ʣ��������û���κε����������ֵ���Ϣ��*/
#include<iostream>
#include<string>
using namespace std;
int main()
{
	string currword,preword;//��¼��ǰ���ʺ�ǰһ����
	cout<<"enter some words:(ctrl+z to end  every word end with enter)"<<endl;
	while(cin>>currword)
	{ 
		if(currword==preword)//��ǰ�����ظ�����
			break;
		else
			preword=currword;
	}
	//������
	if(currword==preword&&!currword.empty())//��ҪֻѰ�Ҵ�д��ĸ��ͷ���������ֵĵ��ʣ����Ϊif(currword==preword&&isupper(currword[0])
		cout<<"the repeated word:"<<currword<<endl;
	else
		cout<<"there is no repeated word."<<endl;
	system("pause");
	return 0;
}