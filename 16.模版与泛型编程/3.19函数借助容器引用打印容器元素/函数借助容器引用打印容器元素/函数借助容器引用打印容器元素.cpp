#include<iostream>
#include<string>
#include<vector>
using namespace std;

template<typename Parm>
void print(const Parm& c)
{
	typename Parm::size_type index = 0;
	while(index != c.size())
	{
		cout<<c[index]<<' ';
		++index;
	}
}

int main()
{
	int ia[] = {1,2,1,4,1,6,1};
	string sa[] = {"this","is","Marry","text","example"};
	vector<int> ivec(ia,ia+7);
	vector<string> svec(sa,sa+5);

	print(ivec);
	cout<<endl;
	print(svec);


	system("pause");
	return 0;
}