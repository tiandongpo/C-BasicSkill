//��д������ʹ���ڵ�һ�ε���ʱ����0,Ȼ���ٴε����ǰ�˳����������������ص�ǰ���ô�����
#include<iostream>
using namespace std;
size_t count_calls()
{
	static size_t ctr = -1;//ctr���������ڽ���Խ�����Ķ�ε���
	return ++ctr;
}
int main()
{
	for(size_t i=0;i!=10;++i)
		cout<<count_calls()<<endl; 
	system("pause");
	return 0;
}