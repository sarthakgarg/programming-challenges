#include<stdio.h>
int k,l,m,n,i,prod;
int arr[1000001];
int main()
{

	scanf("%d",&k);
	scanf("%d",&l);
	scanf("%d",&m);
	arr[k]=1;
	arr[l]=1;
	arr[1]=1;
	arr[0]=0;
	for(i=2;i<=1000000;i++)
	{
		prod=1;
		if(i-1>=0)
			prod=prod && arr[i-1];
		if(i-k>=0)
			prod=prod && arr[i-k];
		if(i-l>=0)
			prod=prod && arr[i-l];
		arr[i]=!prod;
	}							
	while(m--)
	{
		
		scanf("%d",&n);
		if(arr[n]==1)
			printf("A");
		else printf("B");
	}
	printf("\n");
	return 0;
}			
