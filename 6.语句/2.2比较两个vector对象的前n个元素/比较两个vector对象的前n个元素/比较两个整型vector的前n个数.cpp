/*给出两个int型的vector对象，编写程序判断一个对象是否是另一个对象的前缀。如果两个vector对象的长度不同，假设较短的vector对象长度为n
,责只比交这两个对象的前n个元素，例如：对于｛0 ，1，1,2｝和｛0，1，1，2，3，5，8｝这两个vector，你的程序应该返回true.*/
#include<iostream>
#include<vector>
using namespace std;
int main()
{
	vector<int> ivec1,ivec2;
	int ival;


	//读入第一个vector的元素
	cout<<"enter elements for the first vector:(ctrl+z to end)"<<endl;

	while(cin>>ival)
	{ 
		ivec1.push_back(ival);
		
	}
	 
	cin.clear();


	//读入第二个vector的元素

 cout<<"enter elements for the second vector:(ctrl + z to end)"<<endl;

 while(cin>>ival)
	{ 
		ivec2.push_back(ival);
		
	}

 //比较两个vector对象
 vector<int>::size_type size1,size2;
 size1 = ivec1.size();
 size2 = ivec2.size();
 bool result = true;
 for(vector<int>::size_type ix = 0;ix!=(size1>size2?size2:size1);++ix)
	 if(ivec1[ix]!=ivec2[ix])
	 {
		 result = false;
      break;
	 }



 //输出结果
   if(result)
	   if(size1<size2)
		   cout<<"the first vector is prefix of the second one."<<endl;
	   else if(size1==size2)
		   cout<<"two vectors are equal."<<endl;
	   else
		   cout<<"the second vector is prefix of the first one."<<endl;
   else
	   cout<<"no vector is prefix of the other one."<<endl;
   system("pause");
   return 0;
}

