//��ȡһϵ��int���������������Ǵ洢��vector������
//Ȼ��ʹ��algorithemͷ�ļ�����Ϊaccumulate�ĺ�����
//ͳ��vector�����е�Ԫ��֮��
#include<iostream>
#include<vector>
#include<numeric>
using namespace std;
 
int main()
{
	int ival;
	vector<int> ivec;

	//����int���������洢��vector�У�ֱ�������ļ�������
	cout<<"enter some integers(ctrl+z to end):"<<endl;
	while(cin>>ival)
		ivec.push_back(ival);

	//ʹ��accumulate����ͳ��vector��Ԫ��֮�Ͳ�������
	cout<<"summation of element in the vector:"
		<<accumulate(ivec.begin(),ivec.end(),0)
		<<endl;

	system("pause");
	return 0;
}