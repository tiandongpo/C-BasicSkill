/*��дһ��С���򣬴ӱ�׼�������һϵ�е�string����Ѱ�������ظ����ֵĵ��ʡ�����Ӧ���а�����������
�����ĵ��ʵ�����λ�ã��õ��ʵĺ���������ٴγ����Լ����������ظ��������ĵ��ʻ����ظ�����������ظ�������
���ֵ����û�е����ظ������˵����Ϣ�����磬��������ǣ�how ,now now now brown cow cow
�����Ӧ�ñ�����now��������ʳ���������*/
#include<iostream>
#include<string>
using namespace std;
 
int main()
{
	string preword,currword;//��ǰ����ĵ��ʻ���ǰһ����
	string repword;//�ظ��������ĵ���
	int currcnt=0,maxcnt=1;//��ǰ���ʵ��ظ������������ظ����������ֵ

	cout<<"enter some words(ctrl+z to end)"<<endl;
	while(cin>>currword)
	{
		if(currword==preword)//��ǰ�������ظ�����
		    ++currcnt;
		else//��ǰ���ʲ����ظ�����
		{
			if(currcnt > maxcnt)//�������ظ���������ĵ���
			{
				maxcnt = currcnt;
				repword = preword;
			}
			currcnt = 1;
		}
		preword = currword;//�޸Ķ�ǰһ���ʵļ�¼
	}
	if(maxcnt!=1)//�е����ظ�
		cout<<'"'<<repword<<'"'<<"repeater for"<<maxcnt<<"times."<<endl;
	else
	    cout<<"there is no repeated word"<<endl;
	system("pause");
	return 0;
}