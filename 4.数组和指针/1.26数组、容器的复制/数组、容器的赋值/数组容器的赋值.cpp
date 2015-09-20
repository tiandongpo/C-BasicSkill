//分别实现数组的复制和容器的复制
#include<iostream>
#include<vector>
using namespace std;
/*
int main()
{
	const size_t array_size = 10;
	int ia1[]={0,1,2,3,4,5,6,7,8,9};
	int ia2[array_size];

	for(size_t ix= 0;ix!=array_size;++ix)
		{ia2[ix]=ia1[ix];
	    cout<<"ia1[ix]:"<<ia1[ix]<<" "<<"ia2[ix]:"<<ia2[ix]<<" ";
       
	}
	system("pause");
	return 0;
}*/

int main()
{
	vector<int> ivec1(10,20);
	vector<int> ivec2;
	for(vector<int>::iterator iter =ivec1.begin ();iter!=ivec1.end();++iter)
		ivec2.push_back(*iter);

	return 0;
}
