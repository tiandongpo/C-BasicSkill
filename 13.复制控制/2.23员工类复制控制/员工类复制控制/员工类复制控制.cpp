//����һ��employee�࣬������Ա���ֺ�һ��Ψһ�Ĺ�Ա��ʶ��Ϊ���ඨ��Ĭ�Ϲ��캯���Ͳ���Ϊ��ʾ��Ա���ֵ�string���캯��
//���������Ҫ���캯����ֵ��������ʵ����Щ����
//�ü�����ʵ�ֶԹ�Ա��Ψһ��ʶ
#include<string>
using namespace std;
class Employee
{
public:

	//���캯��
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

	//��ֵ����
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