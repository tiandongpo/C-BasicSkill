//�����ı��ļ���ʹ�ñ�׼�⺯������greater_equal,
//ͳ�Ƴ�����10���ϣ���10���ĵ��ʵ���Ŀ
#include<iostream>
#include<fstream>
#include<vector>
#include<algorithm>
#include<string>
#include<functional>
using namespace std;


    //���ڽ����ʰ���������ıȽϺ���
	bool isShort(const string  &s1,const string &s2)
	{
		return s1.size() <s2.size();
	}


	//���ctr��Ϊ1������word�ĸ����汾
	string make_plural(size_t ctr,const string &word,const string &ending)
	{
		return(ctr==1)?word:word+ending;
	}


	//main���������ļ���Ϊ����
	int main(int argc,char **argv)
	{   

		//��������в�������
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
			cerr<<"no input file!"<<endl;
			return EXIT_FAILURE;
		}

		vector<string> words;
		string word;

		//����Ҫ�������������У��������vector������
		while(inFile>>word)
			words.push_back(word);

		//�����������Ա�ȥ���ظ��ĵ���
		sort(words.begin(),words.end());

		//ʹ��unique�㷨��Ԫ���������򲢷���һ��������
		//��ʾ���ظ��ĵ��ʷ�Χ����
		//erase����ʹ�øõ�����ɾ�������������ظ��ĵ���
		words.erase(unique(words.begin(),words.end()),words.end());


		//���㲢���������10���ϣ���10���ĵ��ʵ���Ŀ
		//��Ϊû�п�����ֱ�ӱȽ��ַ������ȵı�׼�⺯��
		//����greater_equal����ѭ��ʵ�ֵ�ϵ����
		vector<string>::size_type wc = 0;
		greater_equal<string::size_type> greq;
		for(vector<string>::iterator iter = words.begin();iter != words.end();++iter)
		{
			if(greq(iter ->size(),10))
			{
				++wc;
			}
		}

		cout<<wc<<" "<<make_plural(wc,"word","s")
			<<"10 charaters or longer"<<endl;

		system("pause");
		return 0;
	}
