
#include<iostream>
#include<string>
using namespace std;
class Item_base
{
public:
	Item_base(const string &book = " ",double sales_price = 0.0,bool dbg = false):isbn(book),price(sales_price),is_debug(dbg){}
	//����is_debug��Ա�����Ƿ���ʾ�������ݳ�Ա
	virtual void debug(ostream& os = cout)const
	{
		if(!is_debug)
			return;
		os<<isbn<<"/t"<<price;
	}


	//����is_debug���ݳ�Ա
	void set_debug(bool dbg)
	{
		is_debug = dbg;
	}
	Item_base(const string &book = " ",double sales_price = 0.0):isbn(book),price(sales_price){}
	string book() const
	{
		return isbn;
	}


	//�����ض����������ܼ۸�
	//�����ཫ���ظú�����Ӧ�ò�ͬ���ۿ۲���
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


	
//�����ۿ��ʺͿ�ʵ���ۿ۲��Ե�����
//�����ཫʹ����Щ����ʵ�ֶ��۲���
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
	
	//����debug��Ա�����Ƿ���ʾ�������ݳ�Ա
	virtual void debug(ostream& os = cout)const
	{
		if(!is_debug)
			return;
		Item_base::debug(os);
		os<<" \t"<<quantity<<"\t"<<discount;
	}
protected:
	size_t quantity;//��ʵ���ۿ۲��ԵĹ�����
	double discount;//�ۿ���
};


//���������ۿ���
class Bulk_item: public Disc_item
{
public:
	

	Bulk_item(const string& book=" ",double sales_price = 0.0,size_t qty =0,double disc_rate = 0.0,bool dbg = false):Disc_item(book,sales_price,qty,disc_rate,dbg){}
	
	//���¶������汾��ʵ�����������ۿ۲���
	//���������������ޣ���ʹ���ۿۼ۸�
	double net_price(size_t cnt)const
	{
		if(cnt >=quantity)
			return cnt*(1-discount)*price;
		else
			return cnt*price;
	}
};


//�����ۿ���
class Lds_item: public Disc_item
{
public:
	//���캯��
	Lds_item(const string& book = " ",double sales_price = 0.0,size_t qty = 0,double dis_rate = 0.0,bool dbg = false):Disc_item(book,sales_price,qty,disc_rate,dbg){}
    
	//�ض������汾��ʵ�������ۿ۲���
	//�Ե������޵Ĺ�����ʹ���ۿۼ۸�
	double net_price(size_t cnt)const
	{
		if(cnt <= quantity)
			return cnt*(1-discount)*price;
		else
			return cnt*price-quantity*discount*price;
	}
};