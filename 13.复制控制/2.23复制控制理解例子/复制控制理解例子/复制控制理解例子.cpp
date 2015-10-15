//定义example类，该类给出复制控制成员和其它构造函数
//用不同的方式使用Exampl类型的对象
//作为非引用形参和引用形参传递，动态分配
//作为函数返回值，进行赋值操作，作为元素放在vector容器中
//研究何时执行哪个构造函数和复制控制成员

#include<vector>
#include<iostream>
using namespace std;

struct Exampl
{   //默认构造函数
	Exampl()
	{
		cout<<"Exampl()"<<endl;
	}
	//复制构造函数
	Exampl(const Exampl&)
	{
		cout<<"Examp1(const Exampl&)"<<endl;
	}
	//赋值构造函数
	Exampl& operator = (const Exampl &rhe)
	{
		cout<<"operator = (const Exampl &rhe)"<<endl;
		return *this;
	}
	//析构函数
	~Exampl()
	{cout<<"~Exampl()"<<endl;}
};
void func1(Exampl obj)//形参为Exampl对象
{}
void func2(Exampl& obj)//形参为Exampl对象的引用
{}
Exampl func3()
{
	Exampl obj;
	return obj;//返回exampl对象
}

int main()
{
	Exampl eobj;//调用默认构造函数创建Exampl对象eobj;

	func1(eobj);//调用复制构造函数
	            //将形参Exampl对象创建为实参Examp对象的副本
	            //函数执行完毕后调用析构函数撤销形参Exampl对象

	func2(eobj);//形参为Exampl对象的引用，无需调用复制构造函数传递实参

	eobj = func3();//调用默认构造函数创建局部Exampl对象
	               //函数返回时调用复制构造函数创建作为返回值副本的empl对象
	               //然后调用析构函数撤销局部exampl对象
	               //然后调用复制操作符
	               //执行完赋值操作后
	               //调用析构函数撤销作为返回值副本的exampl对象



	Exampl *p = new Exampl;//调用默认构造函数创建动态的exampl对象

	vector<Exampl>evec(3);//调用默认构造函数
	                      //创建一个临时的exampl对象
	                      //然后三次调用复制构造函数
	                       //将临时值exampl对象复制到vector容器evec的每个元素
	                       //然后调用析构函数撤销临时的exampl对象

	delete p;//调用析构函数撤销动态创建的exampl对象

	system("pause");
	return 0;//evec及eobj声明周期结束，自动调用析构函数撤销
	         //撤销evec需调用析构函数三次（evec有三个元素）
}
