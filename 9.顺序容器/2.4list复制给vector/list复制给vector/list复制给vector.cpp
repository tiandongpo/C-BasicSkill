//编写一个程序讲一个list容器的所有元素赋值给一个vector容器，期中list容器
//中存储的是指向c风格字符串的char*指针，而vector容器的元素则是string类型
#include<iostream>
#include<list>
#include<vector>
#include<string>

using namespace std;
int main()
{
	char* sa[] ={"marry","tom","bob","alice"};
	list<char*>slst(sa,sa+4);
	vector<string>  svec;
	string str;

	svec.assign(slst.begin(),slst.end());

	for(list<char*>::iterator lit=slst.begin();lit!=slst.end();
          ++lit)
		  cout<<*lit<<" ";
    cout<<endl;


	for(vector<string>::iterator vit = svec.begin();vit!=svec.end();++vit)
     cout<< *vit <<" ";

	cout<<endl;
	system("pause");
	return 0;
}