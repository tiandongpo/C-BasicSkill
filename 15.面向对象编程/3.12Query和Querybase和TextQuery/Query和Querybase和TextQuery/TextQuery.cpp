#include "TextQuery.h"
#include<sstream>

string TextQuery::text_line(line_no line)const
{
	if(line<lines_of_text.size())
		return lines_of_text[line];
	throw out_of_range("line number out of range");
}

//�������ļ�����ÿ�д洢Ϊlines_of_text��һ��Ԫ��
void TextQuery::store_file(ifstream &is)
{
	string textline;
	while(getline(is,textline))
		lines_of_text.push_back(textline);
}


//������vector�����Կհ�Ϊ����ĵ���
//�������Լ����ָõ��ʵ��е��к�һ�����word_map��
void TextQuery::build_map()
{

	//��������vector�е�ÿһ��
	for(line_no line_num=0;line_num != lines_of_text.size();++line_num)
	{   
		//һ�ζ�һ������
		istringstream line(lines_of_text[line_num]);
		string word;
		while(line >> word)
			//���кż��뵽set������ 
			//�����ʲ���map�����У�С�����������õ���
			word_map[cleanup_str(word)].insert(line_num);
	}
}

set<TextQuery::line_no>
	TextQuery::run_query(const string &query_word)const
{
	map<string,set<line_no> >::const_iterator loc=word_map.find(query_word);
	if(loc == word_map.end() )
		return set<line_no>();//�Ҳ��������ؿյ�set����
	else
		//��ȡ��������õ��ʹ������к�set����
		return loc->second;
}


//ȥ����㲢����ĸ���Сд
string TextQuery::cleanup_str(const string &word)
{
	string ret;
	for(string::const_iterator it=word.begin();it != word.end();++it)
	{
		if(!ispunct(*it))
			ret+= tolower(*it);
	}
	return ret;
}

//��ȡ�ı�����

vector<string>::size_type TextQuery::size() const
{
	return lines_of_text.size();
}
