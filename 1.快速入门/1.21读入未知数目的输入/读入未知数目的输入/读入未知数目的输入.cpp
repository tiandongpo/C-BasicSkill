#include<iostream>
int main()
{
	int sum=0,value;//�����Ķ���ͳ�ʼ��
	std::cout<<"������ʵ��δ֪��Ŀ������ۼ�"<<std::endl;
	std::cout<<"����һЩ������.Ȼ���ԡ�ctrl+z������"<<std::endl;
	while(std::cin>>value)//����ʵ��;while���
	{sum+=value;}
	std::cout<<"the sum is:"<<sum<<std::endl;
	system("pause");
	return 0;
	}