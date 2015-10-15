#include"textquery.h"

string make_plural(size_t,const string&,const string&);
ifstream& open_file(ifstream&,const string&);
void print_results(const vector<textquery::line_no>& locs,const string& sought,const textquery &file)
{
	//����ҵ�����sought����������ʳ��ֵ�����
	typedef vector<textquery::line_no> line_nums;
	line_nums::size_type size = locs.size();
	cout<<"\n"<<sought<<locs.size()<<"occurs"<<size<<" "<<make_plural(size,"time","s")<<endl;
	//������ָõ��ʵ�ÿһ��
	line_nums::const_iterator it = locs.begin();
	for(;it!=locs.end();++it)
	{
		cout<<"\t(line"<<(*it)+1<<")"<<file.text_line(*it)<<endl;
	}
}
//main���������ļ���Ϊ����
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
	tq.read_file(infile);//����map����

	//ѭ�������û��Ĳ�ѯҪ��������
	while(true)
	{
		cout<<"enter word to look for,or q to quit:";
		string s;
		cin>>s;
		//��s��ΪСд
		string ret;
		for(string::const_iterator it = s.begin();it!=s.end();++it)
		{
			ret += tolower(*it);
		}
		s = ret;
		//����û������ļ�������q��Q����ѭ������
		if(!cin||s=="q"||s=="Q")break;

		//��ȡ��������ѯ���������е��к�
		vector<textquery::line_no>locs = tq.run_query(s);

		//������ִ�������������ı�
		print_results(locs,s,tq);
	}
	system("pause");
	return 0;
}
