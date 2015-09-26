//自定义类的实现文件
#include"sales_item.h"

std::istream& Sales_item::input(std::istream& in)
{
	double price;
	in>>isbn>>units_sold>>price;
	//检验是否读入成功
	if(in)
		revenue = units_sold *price;
	else//读入失败 将对象复位为默认状态
	{
		units_sold = 0;
		revenue=0.0;
	}
	return in;
}
std::ostream& Sales_item::output(std::ostream& out)const
{
         out<<isbn<<"\n"<<units_sold<<"\t"<<revenue<<"\t"<<avg_price();
      return out;
}

double Sales_item::avg_price() const
{
	if(units_sold)
		return revenue/units_sold;
	else
		return 0;
}
Sales_item Sales_item::add(Sales_item& other)
{
	revenue += other.revenue;
	units_sold +=other.units_sold;
	return *this;
}