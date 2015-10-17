#include<iostream>
#include<string>
using namespace std;
class Item_base
{
public:
	Item_base(const string &book = " ",double sales_price = 0.0):isbn(book),price(sales_price){}
	string book() const
	{
		return isbn;
	}

	virtual double net_price(size_t n)const
	{
		return n*price;
	}

	virtual ~Item_base(){}
private:
	std::string isbn;
protected:
	double price;
}

class Bulk_item: public Item_base
{
public:
	Bulk_item(const std::string& book = " ",double sales_price = 0.0,size_t qty = 0,double disc_rate = 0.0):Item_base(book,sales_price),min_qty(qty),discount(disc_rate)
	{
		cout<<"Bulk_item(const std::string&,double,size_t,double)"<<endl;
	}

	//重定义基类版本实现批量购买折扣策略
	//若购书量高于下限，则使用折扣价格

	 double net_price(size_t cnt)const
	 {
		 if(cnt >= min_qty)
			 return cnt * (1-discount)*price;
		 else
			 return cnt*price;
	 }


	 //复制控制成员
	 Bulk_item(const Bulk_item& b):Item_base(b),min_qty(b.min_qty),discount(b.discount)
	 {
		 cout<<"Bulk_item(const Bulk_item&)"<<std::endl;
	 }
	 Bulk_item& operator = (const Bulk_item& rhs)
	 {
		 if(this != &rhs)
			 Item_base::operator = (rhs);
		 min_qty = rhs.min_qty;
		 discount = rhs.discount;

		 cout<<"Bulk_item::operator = ()"<<endl;
		 return *this;
	 }

	 virtual ~Bulk_item()
	 {
		 cout<<"~Bulk_item()"<<endl;
	 }
private:
	size_t min_qty;//可打折的最小购买量
	double discount;//折扣率
};
