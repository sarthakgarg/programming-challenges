#include<stdio.h>
int main()
{
	int a,b,n,i,j,temp,prime[31631]={0},count=0,primecount,indicount;
	for(i=2;i*i<=31360;i++)
	{
		if(prime[i]==0)
			for(j=2*i;j<=31360;j+=i)
				prime[j]=1;
	}
	scanf("%d%d%d",&a,&b,&n);
	for(temp=a;temp<=b;temp++)
	{
		i=temp;
		primecount=1;
		for(j=2;j*j<=i;j++)
		{
			indicount=0;
			if(prime[j]==0)
			{
				while(i%j==0 && i!=1)
				{
					i/=j;
					indicount++;
				}
			}
			primecount*=(indicount+1);
		}	
			if(i!=1)
				primecount*=2;
			if(primecount==n)
				count++;
	}
	printf("%d\n",count);
	return 0;
}				
							
							
							
