#include<iostream>
#include<map>
#include<string>
using namespace std;

int main()
{
	map<string,int> wordcount;
	string word;

	cout<<"enter some words(ctrl+z to end):"<<endl;
	while(cin>>word)
		++wordcount[word];

	cout<<"word\t\t"<<"times"<<endl;
	for(map<string,int>::iterator iter = wordcount.begin();iter!=wordcount.end();++iter)
		cout<<(*iter).first<<"\t\t"
		<<(*iter).second<<endl;
	system("pause");
	return 0;
}