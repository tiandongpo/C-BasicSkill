/*��дһ��������mian,ʹ������ֵ��Ϊʵ�Σ���������ǵĺ͡�*/
#include<iostream>
using namespace std;

int main(int argc,char **argv)
{
	
	if(argc != 3)
	{
		cout<<"you should use three agruements!"<<endl;
		return -1;
	}
	//ʹ�ñ�׼�⺯��atof��c����ַ���ת��Ϊdouble������
	cout<<"summmation of"<<argv[1]<<"and"<<argv[2]<<"is"<<(atof(argv[1])+atof(argv[2]))<<endl;
	system("pause");
	return 0;
}