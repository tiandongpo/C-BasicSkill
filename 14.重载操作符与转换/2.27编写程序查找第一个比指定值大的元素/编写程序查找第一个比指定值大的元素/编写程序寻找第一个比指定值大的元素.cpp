#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

class GT_cls
{
public:
	GT_cls(int val = 0):bound(val){}
	bool operator ()(const int &ival)
	{
		return ival>bound;
	}
private:
	int bound;
};


int main()
{
	vector<int> ivec;

	int ival;
	cout<<"enter numbers(ctrl + z to end)"<<endl;
	//����vectorԪ��
	while(cin>>ival)
		ivec.push_back(ival);


	cin.clear();//ʹ��������Ч

	int spval;
	cout<<"enter a  specified value:"<<endl;
	//�������ڲ��ҵ�ָ��ֵ
    cin>>spval;

	vector<int>::iterator iter;
	iter = find_if(ivec.begin(),ivec.end(),GT_cls(spval));

	//������
	if(iter != ivec.end())
		cout<<"the first element that is larger than"
		<<spval<<":"
		<<*iter<<endl;

	else
		cout<<"no element that is larger than"
		<<spval<<endl;


	system("pause");
	return 0;
}
