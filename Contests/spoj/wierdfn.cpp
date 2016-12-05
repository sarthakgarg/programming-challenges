#include<stdio.h>
#include <vector>
#include "iostream"
#include <queue>
using namespace std;
int main()                          //f[i]=(a*m[i]+b*i+c)%p
{
	int t,a,b,c,n,median,p,q,i,smax,smin;
	long long temp,sum;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d",&a);
		scanf("%d",&b);
		scanf("%d",&c);
		scanf("%d",&n);
		priority_queue <int ,vector <int> , greater <int> > mi;
		priority_queue <int ,vector <int> , less <int> > ma;		
		if(n==1)
		{
			printf("1\n");
			continue;
		}	
		sum=1;
		mi.push(1);
		smax=ma.size();
		smin=mi.size();
		for(i=1;i<n;i++)
		{
			if(i!=1)
			median=ma.top();
			else median=1;
			temp = (1LL*a*median+1LL*b*(i+1)+c) ;
			if(temp>=1000000007)
				temp = (temp)%1000000007;
			sum+=temp;
			q=mi.top();
			if(temp>=q)
			{
				mi.push(temp);
				smin++;
			}	
			else
			{ 
				ma.push(temp);
				smax++;
			}	
			while(smax>smin+1)
			{
				smax--;
				mi.push(ma.top());
				ma.pop();
				smin++;
			}
			while(smin>smax)
			{
				smin--;
				ma.push(mi.top());
				mi.pop();
				smax++;
			}
	
		}
		printf("%lld\n",sum);
	}
	return 0;
}			
							
				
		
		
		
		
		