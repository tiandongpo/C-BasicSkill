#include"textquery.h"

string make_plural(size_t,const string&,const string&);
ifstream& open_file(ifstream&,const string&);
void print_results(const vector<textquery::line_no>& locs,const string& sought,const textquery &file)
{
	//如果找到单词sought，则输出单词出现的行数
	typedef vector<textquery::line_no> line_nums;
	line_nums::size_type size = locs.size();
	cout<<"\n"<<sought<<locs.size()<<"occurs"<<size<<" "<<make_plural(size,"time","s")<<endl;
	//输出出现该单词的每一行
	line_nums::const_iterator it = locs.begin();
	for(;it!=locs.end();++it)
	{
		cout<<"\t(line"<<(*it)+1<<")"<<file.text_line(*it)<<endl;
	}
}
//main函数接受文件名为参数
int main(int argc,char **argv)
{
	//open the file frome which user will query words
    ifstream infile;
	if(argc<2||!open_file(infile,argv[1]))
	{
		cerr<<"no input file!"<<endl;
		return EXIT_FAILURE;
	}

	textquery tq;
	tq.read_file(infile);//建立map容器

	//循环接受用户的查询要求并输出结果
	while(true)
	{
		cout<<"enter word to look for,or q to quit:";
		string s;
		cin>>s;
		//将s变为小写
		string ret;
		for(string::const_iterator it = s.begin();it!=s.end();++it)
		{
			ret += tolower(*it);
		}
		s = ret;
		//如果用户输入文件结束符q或Q，则循环结束
		if(!cin||s=="q"||s=="Q")break;

		//获取出现所查询单词所有行的行号
		vector<textquery::line_no>locs = tq.run_query(s);

		//输出出现次数及所有相关文本
		print_results(locs,s,tq);
	}
	system("pause");
	return 0;
}
