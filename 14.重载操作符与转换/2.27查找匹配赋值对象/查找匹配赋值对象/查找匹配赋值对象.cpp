//使用标准库函数对象和函数适配器，定义一个对象用于：
//查找大于1024的所有值
//查找不等于pooh的所有字符窜
//将所有值乘以2
#include<iostream>
#include<functional>
#include<algorithm>
#include<string>
#include<vector>
using namespace std;

int main()
{
	const int ARR_SIZE = 7;
	int ia[ARR_SIZE] = {1,1025,2,1026,3,1048};
	vector<int> ivec(ia,ia+ARR_SIZE);
	string sa[ARR_SIZE] = {"many","mach","that","pooh","this","pooh","happy"};
	vector<string> svec(sa,sa+ARR_SIZE);


	//查找大于1024的所有值
	cout<<"all values that are greater than 1024:"<<endl;
	vector<int>::iterator iter = ivec.begin();

	while((iter =find_if(iter,ivec.end(),bind2nd(greater<int>(),1024))) != ivec.end())
	{    //找到了下一个大于1024的数
		 //输出元素
		cout<<*iter<<' ';
		++iter;
	}


	//查找所有不等于“pooh”的所有字符串
	cout<<endl<<"all strings that are not equal to pooh:"<<endl;

	vector<string>::iterator it = svec.begin();
	//使用bind2nd函数适配器将not_equal_to对象的右操作数绑定为"pooh"
	while((it = find_if(it,svec.end(),bind2nd(not_equal_to<string>(),"pooh"))) != svec.end())
	{   //找到了下一个不等于pooh的元素
		//输出元素
		cout<<*it<<' ';
		//it加一便在剩余元素中进行查找
		++it;
	}
	 

	//将所有值乘以2
	//使用函数bind2nd函数适配器将multimaplies对象的右操作数绑定为2
	transform(ivec.begin(),ivec.end(),ivec.begin(),bind2nd(multiplies<int>(),2));

	//输出元素
	cout<<endl<<"all values multimaplied by 2:"<<endl;
	for(vector<int>::iterator it2 = ivec.begin();it2 != ivec.end();++it2)
	cout<< *it2<<' ';


	system("pause");
	return 0;
}