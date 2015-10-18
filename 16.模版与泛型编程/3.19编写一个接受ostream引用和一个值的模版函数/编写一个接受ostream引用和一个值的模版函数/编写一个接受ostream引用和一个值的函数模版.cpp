//编写函数模版，接受一个ostream引用和一个值，将该值写入流。
//用四种不同类型调用函数
//分别写至cout,文件和stringstream
#include<iostream>
#include<string>
#include<fstream>
#include<sstream>
using namespace std;

template<typename T1,typename T2>
T1& print(T1& s,T2 val)
{
	s<<val;
	return s;
}

int main()
{
	double dval = 0.88;
	float fval = -12.3;
	string oristr = "this is a text",desstr;
	ostringstream oss(desstr);
	ofstream outFile("result.dat");

	//写至cout
	print(cout,-3)<<endl;
	print(cout,dval)<<endl;
	print(cout,fval)<<endl;
	print(cout,oristr)<<endl;
    
	//写至文件
	print(outFile,-3)<<endl;
	print(outFile,dval)<<endl;
	print(outFile,fval)<<endl;
	print(outFile,oristr)<<endl;
	outFile.close();

	//写至stringstream
	print(oss,-3)<<endl;
	print(oss,dval)<<endl;
	print(oss,fval)<<endl;
	print(oss,oristr)<<endl;

	//写至stringstream中的字符串输出到cout进行验证
	cout<<oss.str()<<endl;

	system("pause");
	return 0;
}