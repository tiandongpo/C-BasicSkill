#include<iostream>
#include<vector>
#include<string>
#include<cctype>
using namespace std;
int main()
{
	vector<string> svec;
	string str;
	//�����ı���vector ����
	cout<<"enter text(ctrl + z to end):"<<endl;
	while(cin>>str)
		svec.push_back(str);
	//��vector�����е�ÿ������ת��Ϊ��д��ĸ�������
	if(svec.size()==0)
	{cout<<"no string?!"<<endl;
	return -1;
	}
	cout<<"transformed element from the vector"<<endl;
	for(vector<string>::size_type ix=0;ix!=svec.size();++ix){
		for(string::size_type index=0;index!=svec[ix].size();++index)
			if(islower(svec[ix][index]))
				//�������±�Ϊindex����ĸΪСд��ĸ
				svec[ix][index]=toupper(svec[ix][index]);
	cout<<svec[ix]<<" ";
	if((ix+1)%8==0)//ÿ�˸��������һ��
		cout<<endl;
	}
	system("pause");
	return 0;
}


