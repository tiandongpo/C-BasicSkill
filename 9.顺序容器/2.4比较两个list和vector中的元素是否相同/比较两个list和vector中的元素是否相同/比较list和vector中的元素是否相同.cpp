#include<iostream>
#include<list>
#include<vector>
using namespace std;

int main()
{
	vector<int> ivec;
	list<int> ilst;
	int ival;


	//����int���󲢴洢��vector��
	cout<<"enter some integers for vector(ctrl+z to end):"<<endl;
	while(cin>>ival)
		ivec.push_back(ival);
	cin.clear();

	//����int���󲢴洢��list��
	cout<<"enter some integers for list(ctrl+z to end):"<<endl;
	while(cin>>ival)
		ilst.push_back(ival);
	
	//�Ƚ�vector��list�����ж�Ӧ��Ԫ��
	vector<int>::iterator vit=ivec.begin();
	list<int>::iterator lit=ilst.begin();
	while(vit!=ivec.end()&&lit!=ilst.end())
	{
		if(*vit!=*lit)
			break;
		++vit;
		++lit;
	}


	//����ȽϽ��
	if(vit==ivec.end()&&lit==ilst.end())
		cout<<"the vector contains the same elements as the list."<<endl;
	else
		cout<<"list and vector contains different element."<<endl;
	system("pause");
	return 0;
}



