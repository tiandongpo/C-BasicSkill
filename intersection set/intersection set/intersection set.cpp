#include<iostream>
#include<algorithm>
using namespace std;
int  num[110010];
int main()
{
	int m,i,n,count;
	while(cin>>m>>n)
	{
		count = 0;
		for(i=0;i<m+n;i++)
			cin>>num[i];
		sort(num,num+m+n);
        
		for(i=0;i<n+m-1;i++)
			if(num[i]==num[i+1])
			count++;
	 cout<<count;
	}
	system("pause");
	return 0;
}