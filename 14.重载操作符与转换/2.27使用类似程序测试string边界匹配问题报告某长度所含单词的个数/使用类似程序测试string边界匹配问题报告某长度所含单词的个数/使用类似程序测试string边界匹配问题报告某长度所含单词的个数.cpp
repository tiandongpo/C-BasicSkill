#include<iostream>
#include<fstream>
#include<vector>
#include<algorithm>
#include<string>
using namespace std;


//���ڽ����ʰ���������ıȽϺ���
bool isShorter(const string &s1,const string &s2)
{
	return  s1.size()<s2.size();
}


//���Ը�����string�����Ƿ�����߽���ƥ��
class BET_cls
{
public:
	BET_cls(string::size_type len1,string::size_type len2)
	{
		if(len1 < len2)
		{
			minlength = len1;
			maxlength = len2;
		}
		else
		{
			minlength = len2;
			maxlength = len1;
		}
	}

	bool operator () (const string &s)
	{
		return s.size()>=minlength&&s.size()<=maxlength;
	}

private:
	string::size_type minlength;
	string::size_type maxlength;
};

//���ctr��Ϊ1���򷵻�word�ĸ����汾
string make_plural(size_t ctr,const string &word,const string &ending)
{
	return(ctr==1)?word:word+ending;
}


//main���������ļ���Ϊ����
int main(int argc,char **argv)
{

	//��������в�������
	if(argc <2)
	{
		cerr<<"no input file!"<<endl;
		return EXIT_FAILURE;
	}


	//�������ļ�
	ifstream inFile;
	inFile.open(argv[1]);
	if(!inFile)
	{
		cerr<<"can not open input file!<<endl"<<endl;
		return EXIT_FAILURE;
	}

	vector<string> words;
	string word;

	//����Ҫ�������������У��������vector������
	while(inFile>>word)
		words.push_back(word);

	//�Զ�����������һ��ȡ���ظ�����
	sort(words.begin(),words.end());


	//ʹ���㷨unique��Ԫ���������򲢷���һ��������
	//��ʾ���ظ��ĵ��ʷ�Χ�Ľ���
	//erase����ʹ�øõ�����ɾ�������������ظ��ĵ���
	words.erase(unique(words.begin(),words.end()),words.end());


	//�����ʰ��������򣬵ȳ��ĵ��ʰ��ֵ�˳������
	stable_sort(words.begin(),words.end(),isShorter);

	//���㲢���������1��10֮��ĵ��ʵ���Ŀ
	vector<string>::size_type wc = count_if(words.begin(),words.end(),BET_cls(1,10));
	cout<<wc<<" "<<make_plural(wc,"word","s")
		<<"are of sizes 1 through 10 inclusive"<<endl;

	system("pause");
	return 0;
}