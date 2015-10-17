#include<string>
class Item_base
{ 
public:
	Item_base(const std::string &book =" ",double sales_price = 0.0):isbn(book),price(sales_price){}
	std::string book() const
	{
		return isbn;
	}
	//返回特定购书量的总价格
	//派生类将重载函数以应用不同的折扣策略
	virtual double net_price(size_t n)const
	{
		return n*price;
	}

	virtual ~Item_base(){}
private:
	std::string isbn;
protected:
	double price;
};


class Lds_item : public Item_base
{
public:
	Lds_item(const std::string& book = " ",double sales_price = 0.0): Item_base(book,sales_price),max_qty(qty),discount(disc_rate){}

	double Lds_item::net_price(size_t  cnt)const
	{
		if(cnt <= max_qty)
			return cnt*(1-discount)*price;
		else
			return cnt * price - max_qty*discount*price;
	}
private:
	size_t max_qty;
	double discount;
};