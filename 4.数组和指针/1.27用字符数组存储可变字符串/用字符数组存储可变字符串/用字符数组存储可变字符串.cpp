#include<iostream>
#include<string>
#include<cstring>
using namespace std;

int main()
{
	string in_str;
	const size_t str_size = 10;
	char result_str[str_size+1];

	//�����ַ�
	cout<<"enter a string��<="<<str_size<<"characters):"<<endl;
	cin>>in_str;
	//�����踴���ַ�����Ŀ
	size_t len= strlen(in_str.c_str());
	if(len > str_size)
	{len=str_size;
	cout<<"string is longger than:"<<str_size<<"characters and is stored only"<<str_size<<"characters!"<<endl;
	}
	//����len���ַ����ַ�����result_str
	strncpy(result_str,in_str.c_str(),len);
	//��ĩβ���Ͽ��ַ�����null���ַ���
	result_str[len+1]='\0';
	cout<<"the result_str is:"<<result_str<<endl;
	system("pause");
	return 0;
}
