//�Ƚ�����string���͵��ַ���
#include<iostream>
#include<string>
#include<cstring>
using namespace std;
/*int main()
{   //���������ַ���
	string str1,str2;
	cout<<"enter two strings:"<<endl;
	cin>>str1>>str2;
	//�Ƚ������ַ���
    if(str1>str2)
		cout<<"\""<<str1<<"\""<<"is bigger than"<<"\""<<str2<<"\""<<endl;
	else if(str1>str2)
		cout<<"\""<<str2<<"\""<<"is bigger than"<<"\""<<str1<<"\""<<endl;
	else
		cout<<"they are equal"<<endl;
	system("pause");
	return 0;
}*/
//�Ƚ�����c�����ַ���

int main()
{    //char *str1="string1" *str2="string2"
	const int str_size =80;
	char *str1,*str2;
	
	
	//Ϊ�����ַ��������ڴ�
	str1=new char[str_size];
	
	//�Ƚ������ַ���
	str2=new char[str_size];
	if(str1==NULL||str2==NULL)
	{cout<<"no enough memory!"<<endl;
	return -1;}
	  cout<<"enter two strings:"<<endl;
	  cin>>str1>>str2;

	  int result;
	  result=strcmp(str1,str2);
	  if(result>0)
		  cout<<"\""<<str1<<"\""<<"is bigger than"<<"\""<<str2<<"\""<<endl;
	  if(result<0)
		  cout<<"\""<<str2<<"\""<<"is bigger than"<<"\""<<str1<<"\""<<endl;
	  else 
		  cout<<"they are equal!"<<endl;

	  //�ͷ��ַ�����ռ�õ��ڴ�
	  delete[] str1;
	  delete[] str2;


	  system("pause");
	  return 0;
}
