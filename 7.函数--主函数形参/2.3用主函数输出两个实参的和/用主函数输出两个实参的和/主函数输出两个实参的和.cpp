/*编写一个主函数mian,使用两个值作为实参，并输出他们的和。*/
#include<iostream>
using namespace std;

int main(int argc,char **argv)
{
	
	if(argc != 3)
	{
		cout<<"you should use three agruements!"<<endl;
		return -1;
	}
	//使用标准库函数atof将c风格字符串转换为double型数据
	cout<<"summmation of"<<argv[1]<<"and"<<argv[2]<<"is"<<(atof(argv[1])+atof(argv[2]))<<endl;
	system("pause");
	return 0;
}