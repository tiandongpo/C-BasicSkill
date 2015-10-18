//��д����ģ�棬����һ��ostream���ú�һ��ֵ������ֵд������
//�����ֲ�ͬ���͵��ú���
//�ֱ�д��cout,�ļ���stringstream
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

	//д��cout
	print(cout,-3)<<endl;
	print(cout,dval)<<endl;
	print(cout,fval)<<endl;
	print(cout,oristr)<<endl;
    
	//д���ļ�
	print(outFile,-3)<<endl;
	print(outFile,dval)<<endl;
	print(outFile,fval)<<endl;
	print(outFile,oristr)<<endl;
	outFile.close();

	//д��stringstream
	print(oss,-3)<<endl;
	print(oss,dval)<<endl;
	print(oss,fval)<<endl;
	print(oss,oristr)<<endl;

	//д��stringstream�е��ַ��������cout������֤
	cout<<oss.str()<<endl;

	system("pause");
	return 0;
}