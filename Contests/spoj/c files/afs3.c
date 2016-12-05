#include<stdio.h>
int main()
{
	int i,j,n,t;
	long long int arr[1000005]={0};
	for(i=2;i*i<=1000002;i++)
	{
		arr[i*i]+=i;
		for(j=i*i+i;j<=1000002;j+=i)
			arr[j]=arr[j]+i+j/i;
	}
	for(i=2;i<=1000005;i++)
	{
		arr[i]=arr[i-1]+arr[i]+1;
	}
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d",&n);
		printf("%lld\n",arr[n]);
	}		
	return 0;
}			
	
	
