#include<stdio.h>
int main()
{
	int m,arr[10],a,b,i;
	scanf("%d",&m);
	while(m--)
	{
		a=0;
		for(i=0;i<10;i++)
		{
			scanf("%d",&arr[i]);
			if(arr[i]!=0)
				a++;
		}
		if(arr[1]>1)
		{
			if(arr[0]==a)
				printf("W\n");
			else printf("L\n");
		}
		else 
		{
			if(arr[0]==a)
				printf("L\n");
			else printf("W\n");
		}
	}
	return 0;
}	
										
	
