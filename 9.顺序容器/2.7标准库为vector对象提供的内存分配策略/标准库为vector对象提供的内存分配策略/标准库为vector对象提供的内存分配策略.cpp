//�о���׼���vector�����ṩ���ڴ�������
#include<iostream>
#include<vector>
using namespace std;

int main()
{
	vector<int> ivec;
	//����Ӧ��Ϊ�㣬������ʵ�ֶ���

	cout<<"ivec:size:"<<ivec.size()
		<<"capacity:"<<ivec.capacity()<<endl;

	//���ʮ��Ԫ��
	for(int ix=1;ix!=11;++ix)
	{
		ivec.push_back(ix);

		//����Ϊix������>=iz,������ʵ�ֶ���
		cout<<"ivec:size:"<<ivec.size()
			<<"capacity:"<<ivec.capacity()<<endl;
	}
	//��������������
	while(ivec.size()!=ivec.capacity())
		ivec.push_back(0);
	//����һ��Ԫ��
	ivec.push_back(0);
	//����Ӧ��Ϊԭ����+1������>=ԭ����+1��������ʵ�ֶ���
	cout<<"ivec:size:"<<ivec.size()
		<<"capacity:"<<ivec.capacity()<<endl;
   
	//��������Ϊ����100
	ivec.reserve(100);

	//���ȱ��ֲ��䣬����>=100��������ʵ�ֶ���
	cout<<"ivec:size:"<<ivec.size()
		<<"capacity:"<<ivec.capacity()<<endl;
	//����ǰ��������
	while(ivec.size()!=ivec.capacity())
		ivec.push_back(0);
	//�������䣬����Ӧ����������ͬ
	cout<<"ivec:size:"<<ivec.size()
		<<"capacity:"<<ivec.capacity()<<endl;
	//������һ��Ԫ��
	ivec.push_back(42);
	//����Ӧ�ü�1������>=ԭ������һ��������ʵ�ֶ���
	cout<<"ivec:size:"<<ivec.size()
		<<"capacity:"<<ivec.capacity()<<endl;

	system("pause");
	return 0;
}

		