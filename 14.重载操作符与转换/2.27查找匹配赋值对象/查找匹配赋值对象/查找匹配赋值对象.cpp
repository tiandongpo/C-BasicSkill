//ʹ�ñ�׼�⺯������ͺ���������������һ���������ڣ�
//���Ҵ���1024������ֵ
//���Ҳ�����pooh�������ַ���
//������ֵ����2
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


	//���Ҵ���1024������ֵ
	cout<<"all values that are greater than 1024:"<<endl;
	vector<int>::iterator iter = ivec.begin();

	while((iter =find_if(iter,ivec.end(),bind2nd(greater<int>(),1024))) != ivec.end())
	{    //�ҵ�����һ������1024����
		 //���Ԫ��
		cout<<*iter<<' ';
		++iter;
	}


	//�������в����ڡ�pooh���������ַ���
	cout<<endl<<"all strings that are not equal to pooh:"<<endl;

	vector<string>::iterator it = svec.begin();
	//ʹ��bind2nd������������not_equal_to������Ҳ�������Ϊ"pooh"
	while((it = find_if(it,svec.end(),bind2nd(not_equal_to<string>(),"pooh"))) != svec.end())
	{   //�ҵ�����һ��������pooh��Ԫ��
		//���Ԫ��
		cout<<*it<<' ';
		//it��һ����ʣ��Ԫ���н��в���
		++it;
	}
	 

	//������ֵ����2
	//ʹ�ú���bind2nd������������multimaplies������Ҳ�������Ϊ2
	transform(ivec.begin(),ivec.end(),ivec.begin(),bind2nd(multiplies<int>(),2));

	//���Ԫ��
	cout<<endl<<"all values multimaplied by 2:"<<endl;
	for(vector<int>::iterator it2 = ivec.begin();it2 != ivec.end();++it2)
	cout<< *it2<<' ';


	system("pause");
	return 0;
}