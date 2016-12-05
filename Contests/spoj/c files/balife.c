#include<stdio.h>
int arr[9500]={0};

int max(int a,int b)
{
	if(a>b)
		return a;
	else return b;
}		
int divide(int first,int last)
{
	printf("%d %d\n",first,last);
	if(first==last)
		return 0;
	int sum1=0,sum2=0,time1,time2,mid,i;
	mid=(first+last)/2;
	for(i=first;i<=mid;i++)
		sum1+=arr[i];
	for(i=mid+1;i<=last;i++)
		sum2+=arr[i];	
	time1=divide(first,mid);
	time2=divide(mid+1,last);
	if(sum1>=sum2)
		return ( max( time2,(sum1-sum2)/2 ) );
	else return ( max( time1,(sum2-sum1)/2));
}				
	
int main()
{
	int n,i,time;
	while(1)
	{
		scanf("%d",&n);
		if(n==-1)
			return 0;
		for(	i=0;i<n;i++)
			scanf("%d",&arr[i]);
		time=divide(0,n-1);
		printf("%d\n",time);
	}
	return 0;
}		
		
