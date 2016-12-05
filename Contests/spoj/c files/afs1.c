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
	int i,j,t,prime[1007]={0},temp,count,prod,n,flag;
	long f[1000001]={0};
	f[0]=0;
	f[1]=0;
	for(i=2;i*i<=1007;i++)
	{
		if(prime[i]==0)
			for(j=2*i;j<=1007;j+=i)
				prime[j]=1;
	}			
	for(temp=2;temp<=1000000;temp++)
	{
		i=temp;
		flag=0;
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
				if(i!=1)
				{
					if(f[i]!=0)
					{
						f[temp]=prod*f[i];
						flag=1;
						break;
					}	
				}
			}
		}	
		if(flag==1)
			continue;
		f[temp]=prod;
		if(i!=1)
			f[temp]+=temp;

	}
	for(i=2;i<=1000000;i++)
		f[i]=f[i]+f[i-1]-i;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d",&n);
		printf("%ld\n",f[n]);
	}		
	return 0;
}					
	
			
			
			
