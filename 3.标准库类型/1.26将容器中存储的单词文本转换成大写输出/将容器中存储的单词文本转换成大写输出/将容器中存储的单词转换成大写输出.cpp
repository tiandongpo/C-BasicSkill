#include<iostream>
#include<vector>
#include<string>
#include<cctype>
using namespace std;
int main()
{
	vector<string> svec;
	string str;
	//读入文本到vector 对象
	cout<<"enter text(ctrl + z to end):"<<endl;
	while(cin>>str)
		svec.push_back(str);
	//将vector对象中的每个单词转化为大写字母，并输出
	if(svec.size()==0)
	{cout<<"no string?!"<<endl;
	return -1;
	}
	cout<<"transformed element from the vector"<<endl;
	for(vector<string>::size_type ix=0;ix!=svec.size();++ix){
		for(string::size_type index=0;index!=svec[ix].size();++index)
			if(islower(svec[ix][index]))
				//单词中下标为index的字母为小写字母
				svec[ix][index]=toupper(svec[ix][index]);
	cout<<svec[ix]<<" ";
	if((ix+1)%8==0)//每八个单词输出一行
		cout<<endl;
	}
	system("pause");
	return 0;
}


