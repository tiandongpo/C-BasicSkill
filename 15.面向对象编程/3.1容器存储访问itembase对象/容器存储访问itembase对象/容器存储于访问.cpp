//����һ��vector����Item_base���͵Ķ���
//��һЩBulk_item���Ͷ����Ƶ�vector��
//����vector������������Ԫ�ؼ���net_price�ܺ�
#include"item_base.h"
#include<iostream>
#include<string>
#include<utility>
#include<vector>
using namespace std;

int main()
{
	vector<Item_base> itemVec;
	string isbn;
	double price,qty,discount;


	//����Bulk_item���󲢸��Ƶ�vector��
	cout<<"Enter some Bulk_item objects(ctrl+z to end):"<<endl;
	while(cin>>isbn>>price>>qty>>discount)
	{
		itemVec.push_back(Bulk_item(isbn,price,qty,discount));
	}
    

	//����vector������������Ԫ�ؼ��㹺��100�����net_price�ܺ�
	double sum = 0.0;
	for(vector<Item_base>::iterator iter= itemVec.begin();iter != itemVec.end();++iter)
		sum += iter->net_price(100);


	//������
	cout<<"summation of net price;"<<sum<<endl;
	system("pause");
	return 0;
}

