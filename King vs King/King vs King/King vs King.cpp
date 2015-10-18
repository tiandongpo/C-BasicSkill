#include<iostream>  
#include<cstdio>  
//#include<algorithm>  
using namespace std;  
  
int main()  
{  
    int t,n,i,j,p,q;  
    cin>>t;// 主干不分循环次数控制 
    
	while(t--)  
    {  
        
		cin>>n;            //数组大小确定
        int *a =new int[n];//动态数组申明及初始化
	    int *b=new int[n];  
        for(i=0;i<n;i++)  
            cin>>a[i];
        for(i=0;i<n;i++)  
            cin>>b[i]; 
       
		
		//sort(x,x+n);  
        //sort(y,y+n); 
		for(i = 0; i< n; i++)//数组从小到大排序
        for(j = i+1; j< n; j++)
        if(a[i] > a[j])
         {
             t = a[i];
             a[i] = a[j];
             a[j] = t;
        }
		
		for(i = 0; i< n; i++)
        for(j = i+1; j< n; j++)
        if(b[i] > b[j])
       {
           t = b[i];
             b[i] = b[j];
             b[j] = t;
         }


        p=q=0;                //比较得分信息，输出结果
        for(i=0;i<n;i++)  
            if(a[i]>b[i]) p+=2;  
            else if(a[i]<b[i]) q+=2;  
            else { p++; q++; }  
  
        if(p>q) printf("X\n");  
        else if(p<q) printf("Y\n");  
        else printf("none\n"); 
		delete[]a,b;
		
		
    }  
	system("pause");
	return 0;
}  