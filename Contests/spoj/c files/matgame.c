#include<stdio.h>
int main()
{
	int i,j,t,arr[60][60],grundy[60],temp,n,m;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d",&n);
		scanf("%d",&m);
		for(i=0;i<n;i++)
			for(j=0;j<m;j++)
				scanf("%d",&arr[i][j]);
		for(i=0;i<n;i++)
		{
			temp=0;
			for(j=m-1;j>=0;j--)
			{
				if(arr[i][j]<=temp)
					temp=arr[i][j]-1;
				else temp=arr[i][j];
			}
			grundy[i]=temp;
		}
		temp=grundy[0];
		for(i=1;i<n;i++)
			temp=temp^grundy[i];
		if(temp!=0)
			printf("FIRST\n");
		else printf("SECOND\n");
	}
	return 0;
}									
