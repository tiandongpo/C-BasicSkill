//修改Item_base和Bulk_item类
//为构造函数增加打印语句
//定义复制控制成员，使之完成与合成版本相同的工作外，还打印有关本函数的信息
//作为非引用形参和引用形参传递，动态分配
//做为函数返回值，进行复制操作
//研究何时执行哪个构造函数和复制控制成员

#include<iostream>
#include<string>
using namespace std;


//不实用折扣策略的基类
class Item_base
{
public:
	Item_base(const std::string &book = " ",double sales_price = 0.0):isbn(book),price(sales_price)
	{
		cout<<"Item_base(cosnt std::string,double)"<<std::endl;
	}
	std::string book() const
	{
		return isbn;
	}



	//返回特定购书量的总价格
	//派生类将重构函数以应用不同的折扣策略
	virtual double net_price(size_t n)const
	{
		return n*price;
	}

	//复制控制成员
	Item_base(const Item_base& ib):isbn(ib.isbn),price(ib.price)
	{
		std::cout<<"Item_base(const Item_base& rhs)"<<std::endl;
	}

	Item_base& operator = (const Item_base& rhs)
		{
			isbn = rhs.isbn;
			price = rhs.price;
			std::cout<<"Item_base::operator = ()"<<std::endl;
			return *this;
		}
		virtual ~Item_base()
		{
			std::cout<<"~Item_base()"<<std::endl;
		}
private:
		std::string isbn;
	
protected:
		double price;
	};

//批量购买折扣类

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
		 std::cout<<"Bulk_item(const Bulk_item&)"<<std::endl;
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

void func1(Item_base obj)//形参为Item_base对象
{}
void func2(Item_base obj)//形参为Item_base对象的引用
{}
Item_base func3()
{
	Item_base obj;
	return obj;//返回Item_base对象
}

int main()
{
	Item_base iobj;//调用Item_base类的普通构造函数
	               //创建Item_base对象obj
	func1(iobj);//调用Item_base类的复制构造函数
	            //将形参Item_base对象创建为实参Item_base对象的副本
	             //函数执行完毕后调用Item_base类的析构函数
	            //撤销形参Item_base对象
	func2(iobj);//形参为Item_base对象的引用
	             //无需调用复制构造函数传递实参
	iobj = func3();//调用Item_base类的普通构造函数
	               //创建局部Item_base对象 
	               //函数返回时调用Item_base类的复制构造函数
	                //创建作为返回值副本的Iitem_base对象
	                //然后调用Item_base类的析构函数
	                  //撤销局部Item_base对象 
	                   //然后调用Item_base类的赋值操作符
	                   //执行完赋值操作后，调用Item_base类的析构函数
	                  //撤销作为函数返回值的副本的Item_base类
	Item_base *p =new  Item_base;//调用Item_base类的普通构造函数
	                              //创建动态Item_base对象
	delete p;//调用Item_base类的析构函数撤销动态创建的Item_base对象

	Bulk_item bobj;//调用Bulk_item对象将隐式转换为Item_base对象
	               //调用Item_base类的复制构造函数将形参Item_base对象
	               //创建为实参Item_base对象的副本
	               //函数执行完毕后调用Item_base类的析构函数
	               //撤销形参Item_base对象
	func1(bobj);//将实参Bulk_item对象隐式的转换为Item_base对象
	             //调用Item_base类的复制构造函数将形参Item_base对象
	             //创建为实参Item_base对象的副本
	             //函数执行完毕后调用Item_base类的析构函数
	             //撤销Item_base对象
	func2(bobj);//将实参Bulk_item对象隐式的转换为Item_base对象
	            //形参为Item_base对象的引用
	            //无需调用复制构造函数传递实参
	Bulk_item *q  = new Bulk_item;//调用Bulk_item类的复制构造函数
	                               //动态创建Bulk_item对象
	                               //由此导致首先调用Item_base类的
	                               //普通构造函数，创建Bulk_item对象中的Item_base子对象
	delete q;//调用Bulk_item类的析构函数撤销动态创建的Bulk_item对象
	          //由此导致调用Item_base类的析构函数
	          //撤销bobj中Item_base对象
	          //iobj生命周期结束，自动调用Item_base类的析构函数撤销
	system("pause");
	return 0;
}