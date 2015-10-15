#include"textquery.h"
#include<sstream>

string textquery::text_line(line_no line)const
{
	if(line<lines_of_text.size())
		return lines_of_text[line];
	throw out_of_range("line number out of range");
}

	//读入输入文件，将每行存储为lines_of_text的一个元素
	void textquery::store_file(ifstream &is)
	{
		string textline;
		while(getline(is,textline))
			lines_of_text.push_back(textline);
	}

	//在输入vector中找以空白为间隔的单词
	//将单词以及该单词的行的行号一起放入word_map
	void textquery::build_map()
	{
		//处理输入vector中的每一行
		for(line_no line_num = 0;line_num != lines_of_text.size();++line_num)
		{
			//一次读入一个单词
			istringstream line(lines_of_text[line_num]);
			string word;
			while(line>>word)
			{
				//去掉标点
				word = cleanup_str(word);
				//将行号加入到vector容器中
				if(word_map.count(word)==0)//单词不再map容器中
					//小标操作将加入该单词
					word_map[word].push_back(line_num);
				else
				{
					if(line_num != word_map[word].back())
						//行号与vector容器中最后一个元素不相等
						word_map[word].push_back(line_num);
				}
			}
		}
	}

	vector<textquery::line_no>
    textquery::run_query(const string &query_word)const
	{
		//注意，为了避免在word_map中加入单词，使用find函数而不用小标操作
		map<string,vector<line_no> >::const_iterator loc = word_map.find(query_word);
		if(loc == word_map.end())
			return vector<line_no>();
		else
			//获取并返回与该单词关联的行号vector对象
			return loc->second;
	}
	//去掉标点并将字母变成小写
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

