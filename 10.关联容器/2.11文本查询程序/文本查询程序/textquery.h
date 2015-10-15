#ifndef	TEXTQUERY_H
#define TEXTQUERY_H
#include<string>
#include<map>
#include<vector>
#include<cctype>
#include<iostream>
#include<fstream>
#include<cstring>
using namespace std;

class textquery
{
public:;
	//���ͱ���   
	typedef string::size_type str_szie;
	typedef vector<string>::size_type line_no;

	//�ӿڣ�
	//read_file���������ļ����ڲ����ݽṹ
	void read_file(ifstream &is)
	{
		store_file(is);build_map();
	}

	//run_query��ѯ�������ʲ����ظõ��������е��кż���
	vector<line_no>run_query(const string&) const;

	//text_line���������ļ���ָ�����кŶ�Ӧ����
	string text_line(line_no)const;

private:
	//read_file���õĸ�������
	void store_file(ifstream&);//�洢�����ļ�
	void build_map();//��ÿ��������һ���кż��������

	//���������ļ�
	vector<string> lines_of_text;

	//����������ָõ��ʵ��е��к������
	map<string,vector<line_no> >word_map;

	//ȥ����㲢����ĸ���Сд
	static std::string cleanup_str(const std::string&);
};
#endif;
