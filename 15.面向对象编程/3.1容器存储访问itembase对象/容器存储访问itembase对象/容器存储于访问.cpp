//定义一个vector保存Item_base类型的对象
//将一些Bulk_item类型对象复制到vector中
//遍历vector并根据容器中元素计算net_price总和
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


	//读入Bulk_item对象并复制到vector中
	cout<<"Enter some Bulk_item objects(ctrl+z to end):"<<endl;
	while(cin>>isbn>>price>>qty>>discount)
	{
		itemVec.push_back(Bulk_item(isbn,price,qty,discount));
	}
    

	//遍历vector并根据容器中元素计算购买100本书的net_price总和
	double sum = 0.0;
	for(vector<Item_base>::iterator iter= itemVec.begin();iter != itemVec.end();++iter)
		sum += iter->net_price(100);


	//输出结果
	cout<<"summation of net price;"<<sum<<endl;
	system("pause");
	return 0;
}

