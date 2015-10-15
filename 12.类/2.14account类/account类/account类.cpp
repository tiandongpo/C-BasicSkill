#include<string>

class Account
{
public:
	//���캯��
	Account(std::string own,double amnt)
	{
		owner = own;
		amount = amnt;
	}

	//�������
	void applyint()
	{
		amount += amount * interestRate;
	}

	//���ص�ǰ����
	static double rate()
	{
		return interestRate;
	}

	//�����µ�����
	static void rate(double newRate)
	{
		interestRate = newRate;
	}
	
	//���
	double deposit(double amnt)
	{
		amount += amnt;
		return amount;
	}

	//ȡ��
	bool withdraw(double amnt)
	{
		if(amount<amnt)//����
			return false;
		else
		{
			amount -= amnt;
			return true;
		}
	}
	

	//��Ѫ��ǰ���
	double getBalance()
	{
		return amount;
	}

private:
    std::string owner;
	double amount;
	static double interestRate;
};

double Account::interestRate = 2.5;