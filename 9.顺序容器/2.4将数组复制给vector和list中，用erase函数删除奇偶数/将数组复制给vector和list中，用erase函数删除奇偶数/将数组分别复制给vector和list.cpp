#include<iostream>
#include<vector>
#include<list>
using namespace std;


int main()
{
	int ia[]={0,1,1,2,3,5,8,13,21,55,89};
	vector<int> ivec(ia,ia+11);
	list<int> ilst(ia,ia+11);


	//删除list容器中奇数值元素
	for(list<int>::iterator lit=ilst.begin();lit!=ilst.end();++lit)
	{
		if(*lit%2!=0)//迭代器所指向的元素为奇数
		{
			lit=ilst.erase(lit);/*删除元素  （删除元素后迭代器会失效，因此一定要对迭代器重新赋值。另外，erase函数返回一个迭代器
			                    指向被删除元素的下一个元素。因为在for语句头要对迭代器加1,所以在if语句中将迭代器减1，以免遗漏需处理
								的元素*/
			--lit;//迭代器回退，指向被删除的前一元素
		}
	}


	//删除vector容器中的偶数值元素
	
      for(vector<int>::iterator vit=ivec.begin();vit!=ivec.end();++vit)
	  {
		  if(*vit%2==0)//迭代器所指向的元素为偶数
		  {
		      vit=ivec.erase(vit);//删除元素

		        --vit;//迭代器回退，指向被删除元素的前一元素
		  }
	  }
    system("pause");
    return 0;
}