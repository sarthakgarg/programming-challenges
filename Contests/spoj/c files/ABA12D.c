#include<stdio.h>
//gandumanvendra
//chutiyamanu
int prime[1035]={0},p[37]={0};
int checkprime(int i)
{
	int j;
	if(((i+1)%6!=0)&&((i-1)%6!=0))
		return 0;
	for(j=2;j*j<=i;j++)
	{
		if(prime[j]==1)
			continue;
		if((i%j)==0)
			return 0;
	}
   	return 1;
}					
int main()
{
	int t,i,j,k=0,a,b,temp,temp1,count;
	for(i=2;i*i<=1030;i++)
	{
		if(prime[i]==0)
		{
			for(j=2*i;j<=1031;j+=i)
				prime[j]=1;
		}
	}
	for(i=2;i<=1000;i++)
	{
		if(prime[i]==0)
		{	
			temp=i*i;
			while(temp<=1000000)
			{
				if(checkprime((temp*i-1)/(i-1))==1)
				{
					p[k]=temp;
					k++;
				}	
				temp*=i;
				
			}
		}
	}		
	p[36]=2;
	scanf("%d",&t);
	while(t--)
	{
		count=0;
		scanf("%d",&a);
		scanf("%d",&b);
		for(i=0;i<37;i++)
			if((a<=p[i])&&(b>=p[i]))
				count++;
		printf("%d\n",count);
	}	
		return 0;
}		
		
