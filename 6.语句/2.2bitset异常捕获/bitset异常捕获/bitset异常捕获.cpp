/*bitset���ṩto_ulong���������bitset�ṩ������λ������unsigned long�ĳ��ȣ����׳�һ��overflow_error���쳣����д�����쳣�������ʾ��Ϣ�ĳ���*/
#include<iostream>
#include<bitset>
using namespace std;
int main()
{
	bitset<100> bs;

	for(size_t ix=0;ix!=bs.size();++ix)
		bs[ix]=1;
	try{
		bs.to_ulong();
	}
	catch(runtime_error err)
	{
		cout<<err.what()<<endl;
	}
	system("pause");
	return 0;
}