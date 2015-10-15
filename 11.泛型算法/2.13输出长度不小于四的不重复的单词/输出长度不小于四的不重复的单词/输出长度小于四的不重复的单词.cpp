//�����ı��ļ�
//ͳ�Ƴ��Ȳ�С���ĵĵ��ʣ�����������в��ظ��ĵ���
#include<iostream>
#include<fstream>
#include<vector>
#include<algorithm>
#include<string>
using namespace std;


//���ڽ����ʰ���������ıȽϺ���
bool isshort( const string &s1,const string &s2)
{
	return s1.size()<s2.size();
}


//ȷ�����������Ƿ�С����
bool GT4(const string &s)
{
	return  s.size()>=4;
}


//���str��Ϊ1���򷵻�word�ĸ����汾
string make_plural(size_t ctr,const string &word,const string &ending)
{
	return (ctr==1)?word:word+ending;
}


//main���������ļ���Ϊ����
int main(int argc,char **argv)
{   

	//��������в���
	if(argc<2)
	{
		cerr<<"no input file!"<<endl;
		return EXIT_FAILURE;
	}

	//�������ļ�
	ifstream inFile;
	inFile.open(argv[1]);
	if(!inFile)
	{
		cerr<<"can not open input file!"<<endl;
		return EXIT_FAILURE;
	}

	vector<string> words;
	string word;


	//����Ҫ�������������У��������vector������
	while(inFile>>word)
		words.push_back(word);

	//�����������Ա�ȥ���ظ��ĵ���
	sort(words.begin(),words.end());


	//ʹ��unique��Ԫ���������򲢷���һ��������
	//��ʾ���ظ��ĵ��ʵķ�Χ�Ľ���
	//erase����ʹ�øõ�����ɾ�������������ظ��ĵ���
	words.erase(unique(words.begin(),words.end()),words.end());


	//�����ʰ��������򣬵ȳ��ĵ��ʰ��ֵ�����
	stable_sort(words.begin(),words.end(),isshort);


	//���㲢������Ȳ�С���ĵĵ��ʵ���Ŀ
	vector<string>::size_type wc = count_if(words.begin(),words.end(),GT4);
	cout<<wc<<" "<<make_plural(wc,"word","s")
		<<"4 characters or longer"<<endl;

	//������������в��ظ��ĵ���
	cout<<"unique words:"<<endl;
	for(vector<string>::iterator iter = words.begin();iter!=words.end();++iter)
		cout<<*iter<<" ";
	cout<<endl;

	system("pause");
	return 0;
}