#ifndef TEXTQUERY_H
#define TEXTQUERY_H

#include<string>
#include<vector>
#include<set>
#include<map>
#include<cctype>
#include<iostream>
#include<fstream>
#include<cstring>
using namespace std;


class TextQuery
{
public:

	//���ͱ���
	typedef string::size_type str_size;
	typedef vector<string>::size_type line_no;

	//�ӿ�
	//read_file���������ļ��ڲ����ݽṹ
	void read_file(ifstream &is)
	{store_file(is);build_map();}


	//run_query��ѯ�������ʲ����ظõ��������е��кż���
	set<line_no>run_query(const string&)const;


	//text_line���������ļ���ָ���кŶ�Ӧ����
	string text_line(line_no) const;

	line_no size() const;

private:
	//read_file���õĸ�������
	void store_file(ifstream&);//�洢�����ļ�
	void build_map();//��ÿ��������һ���кż��������


	//���������ļ�
	vector<string> lines_of_text;

	//����������ָõ��ʵ��е��кż��������
	map<string,set<line_no> >word_map;

	//ȥ����㲢����ĸ���Сд
	static string cleanup_str(const string&);
};
#endif
