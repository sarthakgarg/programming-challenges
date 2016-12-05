#include<stdio.h>
long long k;
long long choosemin(long long a,long long b)
{
	if(a<=b)
		return a;
	else return b;
}		
long long sequence[102]={0};
long long minima[102]={0};
long long final[102]={0};
long long getmin(long long last,long long new,long long temp)
{
	long long a,b;
	if(last==1)
	{
		final[temp]=(final[last]+new)%100;
		return new*sequence[last];
	}	
	a=minima[last]+final[last]*new;
	b=new*sequence[last]+getmin(last-1,(sequence[last]+new)%100,temp);
	if(a<=b)
	{
		final[temp]=(final[last]+new)%100;
		return a;
	}
	else return b;
}		

void findmin(long long last,long long new)              //last=1
{
	if(last==k)
		return;
	else
	{	
		minima[last+1]=choosemin(minima[last]+final[last]*new,new*sequence[last]+getmin(last-1,(sequence[last]+new)%100,last+1));
		findmin(last+1,sequence[last+2]);
	}	
}		
int main()
{
	long long i,j,temp,swap;
	while(scanf("%lld",&k)!=EOF)
	{
		for(i=1;i<=k;i++)
			scanf("%lld",&sequence[i]);
		if(k==1)
		{
			printf("0\n");
			continue;
		}
		final[1]=sequence[1];
		final[2]=(sequence[1]+sequence[2])%100;
		minima[2]=(sequence[1]*sequence[2]);
		if(k==2)
		{
			printf("%lld\n",minima[2]);
			continue;
		}
		findmin(2,sequence[3]);
		temp=minima[k];
		for(i=1;i<=k/2;i++)
		{
			swap=sequence[i];
			sequence[i]=sequence[k+1-i];
			sequence[k+1-i]=swap;
		}
		final[1]=sequence[1];
		final[2]=(sequence[1]+sequence[2])%100;
		minima[2]=(sequence[1]*sequence[2]);
		findmin(2,sequence[3]);	
		printf("%lld\n",choosemin(temp,minima[k]));
	}
	return 0;
}		
