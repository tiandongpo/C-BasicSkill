//����example�࣬����������ƿ��Ƴ�Ա���������캯��
//�ò�ͬ�ķ�ʽʹ��Exampl���͵Ķ���
//��Ϊ�������βκ������βδ��ݣ���̬����
//��Ϊ��������ֵ�����и�ֵ��������ΪԪ�ط���vector������
//�о���ʱִ���ĸ����캯���͸��ƿ��Ƴ�Ա

#include<vector>
#include<iostream>
using namespace std;

struct Exampl
{   //Ĭ�Ϲ��캯��
	Exampl()
	{
		cout<<"Exampl()"<<endl;
	}
	//���ƹ��캯��
	Exampl(const Exampl&)
	{
		cout<<"Examp1(const Exampl&)"<<endl;
	}
	//��ֵ���캯��
	Exampl& operator = (const Exampl &rhe)
	{
		cout<<"operator = (const Exampl &rhe)"<<endl;
		return *this;
	}
	//��������
	~Exampl()
	{cout<<"~Exampl()"<<endl;}
};
void func1(Exampl obj)//�β�ΪExampl����
{}
void func2(Exampl& obj)//�β�ΪExampl���������
{}
Exampl func3()
{
	Exampl obj;
	return obj;//����exampl����
}

int main()
{
	Exampl eobj;//����Ĭ�Ϲ��캯������Exampl����eobj;

	func1(eobj);//���ø��ƹ��캯��
	            //���β�Exampl���󴴽�Ϊʵ��Examp����ĸ���
	            //����ִ����Ϻ�����������������β�Exampl����

	func2(eobj);//�β�ΪExampl��������ã�������ø��ƹ��캯������ʵ��

	eobj = func3();//����Ĭ�Ϲ��캯�������ֲ�Exampl����
	               //��������ʱ���ø��ƹ��캯��������Ϊ����ֵ������empl����
	               //Ȼ������������������ֲ�exampl����
	               //Ȼ����ø��Ʋ�����
	               //ִ���긳ֵ������
	               //������������������Ϊ����ֵ������exampl����



	Exampl *p = new Exampl;//����Ĭ�Ϲ��캯��������̬��exampl����

	vector<Exampl>evec(3);//����Ĭ�Ϲ��캯��
	                      //����һ����ʱ��exampl����
	                      //Ȼ�����ε��ø��ƹ��캯��
	                       //����ʱֵexampl�����Ƶ�vector����evec��ÿ��Ԫ��
	                       //Ȼ�������������������ʱ��exampl����

	delete p;//������������������̬������exampl����

	system("pause");
	return 0;//evec��eobj�������ڽ������Զ�����������������
	         //����evec����������������Σ�evec������Ԫ�أ�
}
