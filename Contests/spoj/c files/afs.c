#include<stdio.h>
int power(int a,int b)
{
	int temp;
	if(b==0)
		return 1;
	temp=power(a,b/2);
	temp=temp*temp;
	if(b%2!=0)
		temp*=a;
	return temp;
}		
int main()
{
	int i,j,t,prime[1007]={0},temp,count,arr[1000001],prod,n;
	arr[0]=0;
	arr[1]=0;
	for(i=2;i*i<=1007;i++)
	{
		if(prime[i]==0)
			for(j=2*i;j<=1007;j+=i)
				prime[j]=1;
	}			
	for(temp=2;temp<=1000000;temp++)
	{
		i=temp;
		prod=1;
		for(j=2;j*j<=i;j++)
		{
			if(prime[j]==0)
			{
				count=0;
				while(i%j==0 && i!=1)
				{
					i/=j;
					count++;
				}
				
				prod*=((power(j,count+1)-1)/(j-1))	;
			}
		}
		arr[temp	]=arr[temp-1]+prod;
		if(i==1)
			arr[temp]-=temp;
	}
	
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d",&n);
		printf("%d\n",arr[n]);
	}	
	return 0;
}					
	
			
			
			
