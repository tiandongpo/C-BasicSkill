//���庯��make_plural��open_file
#include<fstream>
#include<string>
using namespace std;

//���str��Ϊ1������word�ĸ����汾
string make_plural(size_t ctr,const string &word,const string &ending)
{
	return(ctr==1)?word:word+ending;
}
//�������ļ���in���󶨵��������ļ�
ifstream& open_file(ifstream &in,const string &file)
{
	in.close();//close in case it was already opne
	in.clear();//clear any existing errors;
	//if  the open fails,the stream will be in an invalid state

	in.open(file.c_str());//open the file we were given
	return in;//condition state is good if open succeeded
}