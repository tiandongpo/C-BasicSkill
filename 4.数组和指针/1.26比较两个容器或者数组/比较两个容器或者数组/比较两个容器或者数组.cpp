#include<iostream>
#include<vector>
using namespace std;
/*int main()
{ 
	const int array_size =6;
	int ia1[array_size],ia2[array_size];
	size_t ix;

	cout<<"enter"<<" "<<array_size<<" "<<"numbers of array1:"<<endl;
		for(ix=0;ix!=array_size;++ix)
			cin>>ia1[ix];
	cout<<"enter"<<" "<<array_size<<" "<<"numbers of array2:"<<endl;
		for(ix=0;ix!=array_size;++ix)
			cin>>ia2[ix];
		 
	for(ix=0;ix!=array_size;++ix)
		{if(ia1[ix]!=ia2[ix])
		{cout<<"ia1 is not equal to ia2"<<endl; 
	     system("pause");
	     return 0;}

	     else
	      cout<<"ia1 is equal to ia2"<<endl;
		  }
	system("pause");
	return 0;
}
*/
int main()
{
	vector<int> ivec1,ivec2;
	int ival;
	//读入两个vector的元素值


	cout<<"enter numbers for vector1 (-1 to end):"<<endl;
	cin>>ival;
    while(ival!=-1)
		{ivec1.push_back(ival);
	cin>>ival;}
    cout<<"enter numbers for vector2 (ctr+z to end):"<<endl;
	cin>>ival;
	 while(ival!=-1)
		 {ivec2.push_back(ival);
	 cin>>ival;}


	 //判断两个vector是否相等
	 if(ivec1.size()!=ivec2.size())//长度不等的vector不相等
		 cout<<"vector1 is not equal to vector2"<<endl;
	 else if(ivec1.size()==0&&ivec2.size()==0)//长度都为零相等
		 cout<<"vector1 is  equal to vector2"<<endl;
	 else{//长度相等且不等于零
		 vector<int>::iterator iter1 ,iter2;
		 iter1=ivec1.begin();
		 iter2=ivec2.begin();
		 while(*iter1==*iter2&&iter1!=ivec1.end()&&iter2!=ivec2.end())
		 { ++iter1; ++iter2;}
		 if(iter1==ivec1.end())//所有元素都相等
			 cout<<"vector1 is equal to vector2."<<endl;
		 else
			 cout<<"vector1 is not equal to vector2."<<endl;
	 }
	 system("pause");
	 return 0;
}
   
	