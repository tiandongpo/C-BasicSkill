//定义一个vector对象，其每个元素都是指向string类型的指针
//读取该vector对象输出每个string的内容及其相应的长度
#include<iostream>
#include<string>
#include<vector>
using namespace std;
int main()
{
	vector<string*> spvec;
	//读取vector对象
	string str;
	cout<<"enter some strings(ctr+z to end):"<<endl;
	while(cin>>str)
	 { string *pstr = new string;//指向string对象的指针
	  *pstr = str;
	spvec.push_back(pstr);
	}
   //输出每个string的内容机器相应的长度
	vector<string*>::iterator iter = spvec.begin();
	while(iter!=spvec.end())
	{
		cout<<**iter<<(**iter).size()<<endl;
		iter++;
	}
	//释放各个动态分配的string对象
	iter = spvec.begin();
	while(iter!=spvec.end())
	{
		delete *iter;
		iter++;
	}
	system("pause");
	return 0;
}
