#include<iostream>
#include<cstring>
#include<string>
using namespace std;
//c风格字符串连接
/*
int main()
{
  const char *cp1="mary and linda";
  cout<<" *cp1='mary and linda'"<<endl;
  const char *cp2="are friends";
  cout<<"*cp2='are friends'"<<endl;

  size_t len=strlen(cp1)+strlen(cp2);
  char *result_str= new char[len +1];
  strcpy(result_str,cp1);
  strcat(result_str,cp2);
  for(size_t len1 =0;len1!=len+1;++len1)
  cout<<result_str[len1];
  delete[] result_str;
  system("pause");
  return 0;
}*/
//连接两个string 类型的字符串
int main()
{
	const string str1("mary and linda");
	const string str2("are friend");
	const string str3(" "+str2);
	string result_str;

	result_str=str1;
	result_str+=str3;
	cout<<result_str<<endl;
	system("pause");
	return 0;
}
   

  