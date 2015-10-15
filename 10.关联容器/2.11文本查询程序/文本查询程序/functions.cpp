//定义函数make_plural和open_file
#include<fstream>
#include<string>
using namespace std;

//如果str不为1，返回word的复数版本
string make_plural(size_t ctr,const string &word,const string &ending)
{
	return(ctr==1)?word:word+ending;
}
//打开输入文件流in并绑定到给定的文件
ifstream& open_file(ifstream &in,const string &file)
{
	in.close();//close in case it was already opne
	in.clear();//clear any existing errors;
	//if  the open fails,the stream will be in an invalid state

	in.open(file.c_str());//open the file we were given
	return in;//condition state is good if open succeeded
}