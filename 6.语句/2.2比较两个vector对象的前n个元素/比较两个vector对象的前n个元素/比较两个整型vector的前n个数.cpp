/*��������int�͵�vector���󣬱�д�����ж�һ�������Ƿ�����һ�������ǰ׺���������vector����ĳ��Ȳ�ͬ������϶̵�vector���󳤶�Ϊn
,��ֻ�Ƚ������������ǰn��Ԫ�أ����磺���ڣ�0 ��1��1,2���ͣ�0��1��1��2��3��5��8��������vector����ĳ���Ӧ�÷���true.*/
#include<iostream>
#include<vector>
using namespace std;
int main()
{
	vector<int> ivec1,ivec2;
	int ival;


	//�����һ��vector��Ԫ��
	cout<<"enter elements for the first vector:(ctrl+z to end)"<<endl;

	while(cin>>ival)
	{ 
		ivec1.push_back(ival);
		
	}
	 
	cin.clear();


	//����ڶ���vector��Ԫ��

 cout<<"enter elements for the second vector:(ctrl + z to end)"<<endl;

 while(cin>>ival)
	{ 
		ivec2.push_back(ival);
		
	}

 //�Ƚ�����vector����
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



 //������
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

