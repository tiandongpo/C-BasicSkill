#include<iostream>
#include<vector>
using namespace std;
int main()
{
	vector<int> ivec;
	int ival;
	 

	//����Ԫ�ز�����vector
	cout<<"enter numbers:(ctr+z to end)"<<endl;
    while(cin>>ival)
		ivec.push_back(ival);
	//������̬����
	int *pia = new int[ivec.size()];

	//����Ԫ��
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

	
