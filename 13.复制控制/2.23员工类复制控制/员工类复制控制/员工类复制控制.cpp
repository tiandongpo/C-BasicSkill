//定义一个employee类，包含雇员名字和一个唯一的雇员标识，为该类定义默认构造函数和参数为表示雇员名字的string构造函数
//如果该类需要构造函数或赋值操作符，实现这些函数
//用计数器实现对雇员的唯一标识
#include<string>
using namespace std;
class Employee
{
public:

	//构造函数
	Employee(): name("NoName"),id(counter)
	{
		++counter;
	}
	Employee(string nm):name(nm),id(counter)
	{
		++counter;
	}
	Employee(const Employee& other):name(other.name),id(counter)
	{
		++counter;
	}

	//赋值操作
	Employee& operator = (const Employee& rhe)
	{
		name=rhe.name;
		return *this;
	}
private:
	std::string name;
	int id;
	static int counter;
};
int Employee::counter = 1;