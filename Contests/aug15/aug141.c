#include<stdio.h>
int main()
{
	int n,t,arr[101],k,i,j;
	scanf("%d",&t);
	while(t--)
	{
		j=0;
		scanf("%d",&n);
		scanf("%d",&k);		
		for(i=1;i<=n;i++)
		{	
			scanf("%d",&arr[i]);
			if(arr[i]%2==0)
					j++;
		}
		if(j>=k)
			printf("YES\n");
		else printf("NO\n");
	}
	return 0;
}								
