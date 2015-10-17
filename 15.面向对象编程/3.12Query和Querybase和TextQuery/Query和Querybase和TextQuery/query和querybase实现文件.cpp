#include"Query.h"
#include"TextQuery.h"
#include<set>
#include<algorithm>
#include<iostream>
using namespace std;


//���ز��������������е��кż���
set<TextQuery::line_no>
	NotQuery::eval(const TextQuery& file)const
{   

	//������������Ľ����
	set<TextQuery::line_no>has_val = query.eval(file);

	set<line_no>ret_lines;


	//��������ļ���ÿһ�У������е��к��Ƿ���has_val��
	//������ڣ������е��кż��뵽ret_lines
	for(TextQuery::line_no n=0;n != file.size();++n)
		if(has_val.find(n) == has_val.end())
			ret_lines.insert(n);
	return ret_lines;
}

//�����������������Ľ���
set<TextQuery::line_no>
	AndQuery::eval(const TextQuery& file)const
{   

	//���������Ҳ������Ľ����
	set<line_no>left = lhs.eval(file),
	right = rhs.eval(file);

	set<line_no> ret_lines;//��������Ľ��

	set_intersection(left.begin(),left.end(),right.begin(),right.end(),inserter(ret_lines,ret_lines.begin()));
	return ret_lines;
}

set<TextQuery::line_no>
	OrQuery::eval(const TextQuery& file)const
{     //���������Ҳ������Ľ����
	set<line_no>right = rhs.eval(file),
		ret_lines= lhs.eval(file);


	//��δ��ret_lines�г��ֵ�right�е��кŲ��뵽ret_lines��
	//ret_lines.insert(right.begin(),right.end());
	//���õı�������֧�ִ�����������������insert�������������´��룺
	for(set<line_no>::const_iterator iter = right.begin();iter!=right.end();++iter)
		ret_lines.insert(*iter);
	return ret_lines;
}