#include<iostream>
#include<vector>
using namespace std;
int main()
{
	vector<int> ivec;
	int ival;
	//�������ݵ�vector����

	cout<<"enter numbers(ctrl+z to end:"<<endl;
	while(cin>>ival)
		ivec.push_back(ival);
	//��������Ԫ�صĺͲ����
	if(ivec.size()==0)
	{
		cout<<"no element?!"<<endl;
		return -1;
	}
	cout<<"sum of each pair of adjacent elements in the vextor:"<<endl;
	for(vector<int>::size_type ix = 0;ix<ivec.size()-1;ix=ix+2)
	{
		cout<<ivec[ix]+ivec[ix+1]<<"\t";
		if((ix+1)%6==0)//û���������
			cout<<endl;
	}
	if(ivec.size()%2!=0)//��ʾ���һ��Ԫ��û�����
		cout<<endl;
	cout<<"the last element is not been summed"
		<<"and its value is"
		<<ivec[ivec.size()-1]<<endl;
	system("pause");
	return 0;
}

