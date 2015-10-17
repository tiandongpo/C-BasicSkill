#include"Query.h"
#include"TextQuery.h"


string make_plural(size_t,const string&,const string&);
ifstream& open_file(ifstream&,const string&);
void print_results(const set<TextQuery::line_no>& locs,const TextQuery &file)
{
	typedef set<TextQuery::line_no>line_nums;
	line_nums::size_type size = locs.size();


	//����ҵ�ƥ��Ľ���������ƥ�������
	cout<<"match occurs"
		<<size<<" "
		<<make_plural(size,"time","a")<<endl;
	
	//������ָõ��ʵ�ÿһ��
	line_nums::const_iterator it= locs.begin();
	for(;it!=locs.end();++it)
	{
		cout<<"\t(line"
			//�кŴ�1��ʼ
			<<(*it)+1<<")"<<file.text_line(*it)<<endl;
	}
}

int main(int argc,char **argv)
{    

	//��Ҫ�����в�ѯ���ı��ļ�
	ifstream infile;
	if(argc < 2||!open_file(infile,argv[1]))
	{
		cerr<<"no input file!"<<endl;
		return EXIT_FAILURE;
	}

	TextQuery file;

	file.read_file(infile);//�����ı�����map����

	typedef set<TextQuery::line_no>line_nums;
	//�����ѯ

	Query q = Query("fiery")&Query("bird") | Query("wind");

	//�����ѯ�����ƥ���е��кż���
	const line_nums &locs = q.eval(file);

	//�����ѯ���ʽ
	cout<<"\nExecuted Query for:"<<q<<endl;

	//�����ѯ���
	print_results(locs,file);

	return 0;
}