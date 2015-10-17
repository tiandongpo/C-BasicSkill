#include"Query.h"
#include"TextQuery.h"


string make_plural(size_t,const string&,const string&);
ifstream& open_file(ifstream&,const string&);
void print_results(const set<TextQuery::line_no>& locs,const TextQuery &file)
{
	typedef set<TextQuery::line_no>line_nums;
	line_nums::size_type size = locs.size();


	//如果找到匹配的结果，则输出匹配的行数
	cout<<"match occurs"
		<<size<<" "
		<<make_plural(size,"time","a")<<endl;
	
	//输出出现该单词的每一行
	line_nums::const_iterator it= locs.begin();
	for(;it!=locs.end();++it)
	{
		cout<<"\t(line"
			//行号从1开始
			<<(*it)+1<<")"<<file.text_line(*it)<<endl;
	}
}

int main(int argc,char **argv)
{    

	//打开要在其中查询的文本文件
	ifstream infile;
	if(argc < 2||!open_file(infile,argv[1]))
	{
		cerr<<"no input file!"<<endl;
		return EXIT_FAILURE;
	}

	TextQuery file;

	file.read_file(infile);//读入文本建立map容器

	typedef set<TextQuery::line_no>line_nums;
	//构造查询

	Query q = Query("fiery")&Query("bird") | Query("wind");

	//计算查询，获得匹配行的行号集合
	const line_nums &locs = q.eval(file);

	//输出查询表达式
	cout<<"\nExecuted Query for:"<<q<<endl;

	//输出查询结果
	print_results(locs,file);

	return 0;
}