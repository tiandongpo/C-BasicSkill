/*编写一个函数，其唯一的形参和返回值都是istream类型，该函数意志读取流到文件结束符为止，还应将读取的内容输出到标准输出中，最后，重设流使其有效，并返回该流；
*/
#include<iostream>
using namespace std;

istream& get(istream& in)//流类型不能作为函数的形参或返回类型，必须使用流类型的指针或引用
{
	int ival;
	while(in>>ival,!in.eof())//遇到文件结束符以前一直读入数据
	{
		if(in.bad())//出现系统级故障
			throw runtime_error("IO stream corrupted");
		if(in.fail())//出现可恢复故障
		{
			cerr<<"bad data,try again";//提示用户
			in.clear();//恢复流
			in.ignore(200,' ');//跳过类型非法的输入项
			continue;//继续读入数据
		}
		//读入正常
		cout<<ival<<" ";
	}
	in.clear();

	return in;
}
int main()
{
	double dval;
	get(cin);
	cin>>dval;//重新使用恢复后的流
	cout<<dval<<endl;
    system("pause");
	return 0;
}