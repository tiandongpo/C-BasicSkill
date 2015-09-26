#include"sales_item.h"
#include<iostream>
using namespace std;


int main()
{
	Sales_item item;
    //读入并输出一组交易
	cout<<"enter some transactions(ctrl+z to end):"<<endl;
	while(item.input(cin))
	{
		cout<<"the transaction readed is:"<<endl;
		item.output(cout);
	}

	cin.clear();

   Sales_item total,trans;

   cout<<"enter some transactions(ctrl+z to end):"<<endl;
   if(total.input(cin))
   {
	   while (trans.input(cin))
		   if(total.same_isbn(trans))
			   total.add(trans);
		   else
			   {
				   total.output(cout)<<endl;
	               total=trans;
		   }
		   total.output(cout)<<endl;
   }
   else
   {
	   cout<<"no data?!"<<endl;
	   return -1;
   }



	system("pause");
	return 0;
}