//�޸�Item_base��Bulk_item��
//Ϊ���캯�����Ӵ�ӡ���
//���帴�ƿ��Ƴ�Ա��ʹ֮�����ϳɰ汾��ͬ�Ĺ����⣬����ӡ�йر���������Ϣ
//��Ϊ�������βκ������βδ��ݣ���̬����
//��Ϊ��������ֵ�����и��Ʋ���
//�о���ʱִ���ĸ����캯���͸��ƿ��Ƴ�Ա

#include<iostream>
#include<string>
using namespace std;


//��ʵ���ۿ۲��ԵĻ���
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



	//�����ض����������ܼ۸�
	//�����ཫ�ع�������Ӧ�ò�ͬ���ۿ۲���
	virtual double net_price(size_t n)const
	{
		return n*price;
	}

	//���ƿ��Ƴ�Ա
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

//���������ۿ���

class Bulk_item: public Item_base
{
public:
	Bulk_item(const std::string& book = " ",double sales_price = 0.0,size_t qty = 0,double disc_rate = 0.0):Item_base(book,sales_price),min_qty(qty),discount(disc_rate)
	{
		cout<<"Bulk_item(const std::string&,double,size_t,double)"<<endl;
	}

	//�ض������汾ʵ�����������ۿ۲���
	//���������������ޣ���ʹ���ۿۼ۸�

	 double net_price(size_t cnt)const
	 {
		 if(cnt >= min_qty)
			 return cnt * (1-discount)*price;
		 else
			 return cnt*price;
	 }


	 //���ƿ��Ƴ�Ա
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
	size_t min_qty;//�ɴ��۵���С������
	double discount;//�ۿ���
};

void func1(Item_base obj)//�β�ΪItem_base����
{}
void func2(Item_base obj)//�β�ΪItem_base���������
{}
Item_base func3()
{
	Item_base obj;
	return obj;//����Item_base����
}

int main()
{
	Item_base iobj;//����Item_base�����ͨ���캯��
	               //����Item_base����obj
	func1(iobj);//����Item_base��ĸ��ƹ��캯��
	            //���β�Item_base���󴴽�Ϊʵ��Item_base����ĸ���
	             //����ִ����Ϻ����Item_base�����������
	            //�����β�Item_base����
	func2(iobj);//�β�ΪItem_base���������
	             //������ø��ƹ��캯������ʵ��
	iobj = func3();//����Item_base�����ͨ���캯��
	               //�����ֲ�Item_base���� 
	               //��������ʱ����Item_base��ĸ��ƹ��캯��
	                //������Ϊ����ֵ������Iitem_base����
	                //Ȼ�����Item_base�����������
	                  //�����ֲ�Item_base���� 
	                   //Ȼ�����Item_base��ĸ�ֵ������
	                   //ִ���긳ֵ�����󣬵���Item_base�����������
	                  //������Ϊ��������ֵ�ĸ�����Item_base��
	Item_base *p =new  Item_base;//����Item_base�����ͨ���캯��
	                              //������̬Item_base����
	delete p;//����Item_base�����������������̬������Item_base����

	Bulk_item bobj;//����Bulk_item������ʽת��ΪItem_base����
	               //����Item_base��ĸ��ƹ��캯�����β�Item_base����
	               //����Ϊʵ��Item_base����ĸ���
	               //����ִ����Ϻ����Item_base�����������
	               //�����β�Item_base����
	func1(bobj);//��ʵ��Bulk_item������ʽ��ת��ΪItem_base����
	             //����Item_base��ĸ��ƹ��캯�����β�Item_base����
	             //����Ϊʵ��Item_base����ĸ���
	             //����ִ����Ϻ����Item_base�����������
	             //����Item_base����
	func2(bobj);//��ʵ��Bulk_item������ʽ��ת��ΪItem_base����
	            //�β�ΪItem_base���������
	            //������ø��ƹ��캯������ʵ��
	Bulk_item *q  = new Bulk_item;//����Bulk_item��ĸ��ƹ��캯��
	                               //��̬����Bulk_item����
	                               //�ɴ˵������ȵ���Item_base���
	                               //��ͨ���캯��������Bulk_item�����е�Item_base�Ӷ���
	delete q;//����Bulk_item�����������������̬������Bulk_item����
	          //�ɴ˵��µ���Item_base�����������
	          //����bobj��Item_base����
	          //iobj�������ڽ������Զ�����Item_base���������������
	system("pause");
	return 0;
}