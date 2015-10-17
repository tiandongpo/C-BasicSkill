
#include<iostream>
#include<string>
using namespace std;
class Item_base
{
public:
	Item_base(const string &book = " ",double sales_price = 0.0,bool dbg = false):isbn(book),price(sales_price),is_debug(dbg){}
	//根据is_debug成员决定是否显示其他数据成员
	virtual void debug(ostream& os = cout)const
	{
		if(!is_debug)
			return;
		os<<isbn<<"/t"<<price;
	}


	//设置is_debug数据成员
	void set_debug(bool dbg)
	{
		is_debug = dbg;
	}
	Item_base(const string &book = " ",double sales_price = 0.0):isbn(book),price(sales_price){}
	string book() const
	{
		return isbn;
	}


	//返回特定购书量的总价格
	//派生类将重载该函数以应用不同的折扣策略
	virtual double net_price(size_t n)const
	{
		return n*price;
	}

	virtual ~Item_base(){}

private:
	string isbn;
protected:

	bool is_debug;
	double price;
};


	
//保存折扣率和可实行折扣策略的数量
//派生类将使用这些数据实现定价策略
class Disc_item: public Item_base
{
public:
	Disc_item(const string& book = " ",double sales_price = 0.0,size_t qty = 0,double disc_rate = 0.0):Item_base(book,sales_price),quantity(qty),discount(dis_rate){}
	double netprice(size_t) const = 0;
	pair<size_t,double>discount_policy()const
	{
		return make_pair(quantity,discount);
	}

	Disc_item(const  string &book = " ",double sales_price = 0.0,size_t qty=0,double disc_rate= 0.0,bool dbg= false):Item_base(book,sales_price,dbg),quantity(qty),discount(disc_rate){}
	
	//根据debug成员决定是否显示其他数据成员
	virtual void debug(ostream& os = cout)const
	{
		if(!is_debug)
			return;
		Item_base::debug(os);
		os<<" \t"<<quantity<<"\t"<<discount;
	}
protected:
	size_t quantity;//可实行折扣策略的购买量
	double discount;//折扣率
};


//批量购买折扣类
class Bulk_item: public Disc_item
{
public:
	

	Bulk_item(const string& book=" ",double sales_price = 0.0,size_t qty =0,double disc_rate = 0.0,bool dbg = false):Disc_item(book,sales_price,qty,disc_rate,dbg){}
	
	//重新定义基类版本以实现批量购买折扣策略
	//若购书量高于下限，则使用折扣价格
	double net_price(size_t cnt)const
	{
		if(cnt >=quantity)
			return cnt*(1-discount)*price;
		else
			return cnt*price;
	}
};


//有限折扣类
class Lds_item: public Disc_item
{
public:
	//构造函数
	Lds_item(const string& book = " ",double sales_price = 0.0,size_t qty = 0,double dis_rate = 0.0,bool dbg = false):Disc_item(book,sales_price,qty,disc_rate,dbg){}
    
	//重定义基类版本以实现有限折扣策略
	//对低于上限的购书量使用折扣价格
	double net_price(size_t cnt)const
	{
		if(cnt <= quantity)
			return cnt*(1-discount)*price;
		else
			return cnt*price-quantity*discount*price;
	}
};