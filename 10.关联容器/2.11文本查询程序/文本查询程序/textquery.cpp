#include"textquery.h"
#include<sstream>

string textquery::text_line(line_no line)const
{
	if(line<lines_of_text.size())
		return lines_of_text[line];
	throw out_of_range("line number out of range");
}

	//���������ļ�����ÿ�д洢Ϊlines_of_text��һ��Ԫ��
	void textquery::store_file(ifstream &is)
	{
		string textline;
		while(getline(is,textline))
			lines_of_text.push_back(textline);
	}

	//������vector�����Կհ�Ϊ����ĵ���
	//�������Լ��õ��ʵ��е��к�һ�����word_map
	void textquery::build_map()
	{
		//��������vector�е�ÿһ��
		for(line_no line_num = 0;line_num != lines_of_text.size();++line_num)
		{
			//һ�ζ���һ������
			istringstream line(lines_of_text[line_num]);
			string word;
			while(line>>word)
			{
				//ȥ�����
				word = cleanup_str(word);
				//���кż��뵽vector������
				if(word_map.count(word)==0)//���ʲ���map������
					//С�����������õ���
					word_map[word].push_back(line_num);
				else
				{
					if(line_num != word_map[word].back())
						//�к���vector���������һ��Ԫ�ز����
						word_map[word].push_back(line_num);
				}
			}
		}
	}

	vector<textquery::line_no>
    textquery::run_query(const string &query_word)const
	{
		//ע�⣬Ϊ�˱�����word_map�м��뵥�ʣ�ʹ��find����������С�����
		map<string,vector<line_no> >::const_iterator loc = word_map.find(query_word);
		if(loc == word_map.end())
			return vector<line_no>();
		else
			//��ȡ��������õ��ʹ������к�vector����
			return loc->second;
	}
	//ȥ����㲢����ĸ���Сд
	string textquery::cleanup_str(const string &word)
	{
		string ret;
		for(string::const_iterator it =word.begin();it!=word.end();++it)
		{
			if(!ispunct(*it))
				ret+=tolower(*it);
		}
		return ret;
	}

