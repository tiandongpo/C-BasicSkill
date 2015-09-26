#ifndef SALESITEM_H
#define SALESITEM_H
#include<iostream>
#include<string>
  
class Sales_item
{
public:
	//sales_item�����Ĳ���
	std::istream& input(std::istream& in);
	std::ostream& output(std::ostream& out)const;
	Sales_item add(Sales_item& other);
	double avg_price() const;
	bool same_isbn(const Sales_item &rhs)const
	{
		return isbn == rhs.isbn;
	}
	//Ĭ�Ϲ��캯����Ҫ��ʼ���������͵����ݳ�Ա
	Sales_item::Sales_item():units_sold(),revenue(0.0){}
private:
	std::string isbn;
	unsigned units_sold;
	double revenue;
};
#endif;
