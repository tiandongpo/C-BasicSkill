#include<iostream>
int main()
{
	int base,exponent;//����������ҳ�ʼ��
	long result =1;
	std::cout<<"������ʵ����һ��������ָ���η���ֵ"<<std::endl;
	std::cout<<"enter base and expant:"<<std::endl;
	std::cin>>base>>exponent;
	 
	if(exponent<0)//����ʵ�֣�if����forѭ��
	{std::cout<<"exponent cannont be smaller than 0"<<std::endl;
	return -1;
	}
	if(exponent>=0)
	{for(int cnt = 1;cnt<=exponent;++cnt)
	result *=base;
	}
	std::cout<<base<<"raised to the power of"<<exponent<<":"<<result<<std::endl;
	system("pause");
	return 0;
}