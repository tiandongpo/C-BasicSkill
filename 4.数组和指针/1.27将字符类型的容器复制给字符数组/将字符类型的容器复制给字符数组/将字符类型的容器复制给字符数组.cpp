//编写程序读入一组string类型的数据，并将他们存储在vector中。接着，把vector对象复制给一个字符指针数组。为vector中的每一个元素创建一个新的
//字符数组，并把该vector元素的数据复制到相应的字符数组中，最后把指向该书数组的指针插入字符指针数组。
#include<iostream>
#include<string>
#include<vector>
using namespace std;
int main()
{
	vector<string> svec;
	string str;
	//输入vectot元素
	cout<<"enter strings:(ctr+z to end)"<<endl;
	while(cin>>str)
		svec.push_back(str);
	//创建字符指针数组
	char **parr = new char *[svec.size()];
	 //处理vector元素
	size_t ix = 0;
	for(vector<string>::iterator iter = svec.begin();
		iter!=svec.end();++iter,++ix)
	{   //创建字符数组
		char *p = new char[(*iter).size()+1];
		//复制vector元素的数据到字符数组
		strcpy(p,(*iter).c_str());
		//将指向该字符数组的指针插入到字符指针数组
		parr[ix] = p;

	}
	//释放各个字符数组
	for (ix=0;ix!=svec.size();++ix)
		delete[] parr[ix];
	//释放字符指针数组
	delete[] parr;
	system("pause");
	return 0;
}


