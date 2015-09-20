#include<iostream>
#include<vector>
using namespace std;
int main()
{
	vector<int> ivec;
	int ival;
	 

	//读入元素并建立vector
	cout<<"enter numbers:(ctr+z to end)"<<endl;
    while(cin>>ival)
		ivec.push_back(ival);
	//创建动态数组
	int *pia = new int[ivec.size()];

	//复制元素
	int *tp=pia;
	cout<<"the array is:"<<endl;
	for(vector<int>::iterator iter = ivec.begin ();iter!=ivec.end();++iter,++tp)
		{ *tp=*iter;
	     cout<<*tp<<endl;
	}
	delete[] pia;
	system("pause");
	return 0;
}

	
