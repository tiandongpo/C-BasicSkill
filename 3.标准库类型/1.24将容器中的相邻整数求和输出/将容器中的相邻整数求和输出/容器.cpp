#include<iostream>
#include<vector>
using namespace std;
int main()
{
	vector<int> ivec;
	int ival;
	//读入数据到vector对象

	cout<<"enter numbers(ctrl+z to end:"<<endl;
	while(cin>>ival)
		ivec.push_back(ival);
	//计算相邻元素的和并输出
	if(ivec.size()==0)
	{
		cout<<"no element?!"<<endl;
		return -1;
	}
	cout<<"sum of each pair of adjacent elements in the vextor:"<<endl;
	for(vector<int>::size_type ix = 0;ix<ivec.size()-1;ix=ix+2)
	{
		cout<<ivec[ix]+ivec[ix+1]<<"\t";
		if((ix+1)%6==0)//没行输出六个
			cout<<endl;
	}
	if(ivec.size()%2!=0)//提示最后一个元素没有求和
		cout<<endl;
	cout<<"the last element is not been summed"
		<<"and its value is"
		<<ivec[ivec.size()-1]<<endl;
	system("pause");
	return 0;
}

