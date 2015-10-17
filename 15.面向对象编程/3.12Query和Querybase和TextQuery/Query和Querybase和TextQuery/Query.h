#ifndef QUERY_H
#define QUERY_H

#include"TextQuery.h"
#include<string>
#include<set>
#include<iostream>
#include<fstream>
using namespace std;


//���������ѯ���͵Ļ��������
class Query_base
{
	friend class Query;
protected:
	typedef TextQuery::line_no line_no;
	virtual ~Query_base(){}
private:
	//������ò�ѯƥ����е��кż���
	virtual set<line_no>
		eval(const TextQuery&)const = 0;

	virtual ostream&
		display(ostream& = cout)const=0;
}


//����Query_base�̳в�εľ����
class Query
{   

	//��Щ��������Ҫ����Query_base*���캯��
	friend Query operator~(const Query &);
	friend Query operator | (const Query&,const Query&);
	friend Query operator & (const Query&,const Query&);
public:
	Query(const string&);//�����ĵ�wordquery����

	//����ָ�뼰ʹ�ü����ĸ��ƿ��Ƴ�Ա
	Query(const Query &c):q(c.q),use(c.use){++*use;}
	~Query(){decr_use();}
	Query& operator = (const Query&);
    

	//�ӿں�������������Ӧ��Query_base����
	set<TextQuery::line_no>
		eval(const TextQuery &t) const {return q->eval(t);}
	ostream &display(ostream &os)const
	{
		return q->display(os);
	}
private:
	Query(Query_base *query):q(query),use(new size_t(1){}
	Query_base * q;
	size_t *use;
	void decr_use()
	{
		if(--*use==0)
		{
			delete q;delete use;
		}
	}
};

inline ostream&
	operator << (ostream &os,const Query &q)
{
	return q.display(os);
}

class WordQuery: public Query_base
{
	friend class Query;//queryʹ��wordquery���캯��
	WordQuery(const string &s):query_word(s){}


	//������wordquery�������м̳ж����Ĵ��麯��
	set<line_no> eval(const TextQuery &t)const
	{
		return t.run_query(query_word);}
	ostream& display(ostream &os)const
	{
		return os << query_word;}
	string query_word;//Ҫ���ҵĵ���
};

inline
	Query::Query(const string &s):q(new WordQuery(s)),use(new size_t(1)){}


class NotQuery: public Query_base
{
	friend Query operator~(const Query &);
	NotQuery(Query q):query(q){}


	//������NotQuery�������м̳ж����Ĵ��麯��
	set<line_no>eval(const TextQuery&) const;
	ostream& display(ostream &os) const
	{
		return os<<"~)"<<query<<")";
	}
	const Query query;
};

class BinaryQuery: public Query_base
{
protected:
	BinaryQuery(Query left,Query right,string op):lhs(left),rhs(right),oper(op){}


	//������binary������eval
	ostream& display(ostream &os) const
	{
		return os<<"("<<lhs<<" "<<oper<<" "<<rhs<<")";
	}

	const Query lhs,rhs;//���Ҳ�����
	const string oper;//������
};

class AndQuery: public BinaryQuery
{
	friend Query operator&(const Query&,const Query&);
	AndQuery(Query left,Query right):BinaryQuery(left,right,"&"){}


	//������andquery�̳�display������Ϊ�麯��
	set<line_no>eval(const TextQuery&)const;
};

class OrQuery: public BinaryQuery
{
	friend Query operator | (const Query&,const Query&);
	OrQuery(Query left,Query right):BinaryQuery(left,right,"|"){}

	set<line_no>eval(const TextQuery&)const;
};

class AndQuery:public BinaryQuery
{
	friend Query operator & (const Query&,const Query&);
	AndQuery(Query left,Query right):BinaryQuery(left,right,"&"){}

	set<line_no>eval(const TextQuery&)const;
};

inline Query operator  & (const	Query &lhs,const Query &rhs)
{
	return new AndQuery(lhs,rhs);
}

inline Query operator | (const Query &lhs,const Query &rhs)
{
	return new OrQuery(lhs,rhs);
}

inline Query operator~(const Query &oper)
{
	return new NotQuery(oper);
}
#endif