//��дһ������һ��list����������Ԫ�ظ�ֵ��һ��vector����������list����
//�д洢����ָ��c����ַ�����char*ָ�룬��vector������Ԫ������string����
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