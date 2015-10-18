#include<iostream>
using namespace std;
int main()
{
	long long d,m;
	int t;
	cin>>t;
	while(t--)
	{
		cin>>d;
		m=1;


		/*while(m>10)  
		m-=5,m++;  
		cout<<m<<endl;*/  
		if(d <= 10)
		{
			cout<<m<<endl;
		}
		else
		{
			m=(d-10)/5; 
			d%=5;
			if(!d)
			{
				cout<<m+1<<endl;
			}
			else 
			{
				cout<<m+2<<endl;
			}
		}
	}
	system("pause");
	return 0;
}