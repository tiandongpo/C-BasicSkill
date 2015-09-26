/*bitset类提供to_ulong操作。如果bitset提供操作的位数大于unsigned long的长度，则抛出一个overflow_error的异常。编写捕获异常并输出提示信息的程序。*/
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