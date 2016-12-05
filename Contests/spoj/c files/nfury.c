#include<stdio.h>
int main()
{
	int i,t,k,squares[102],min[10002];
	for(i=1;i<101;i++)
		squares[i]=i*i;
	for(	i=0;i<=10000;i++)
		min[i]=i;
	for(k=2;k<=100;k++)
	{
		i=0;
		while(squares[k]+i<=10000)
		{
			if(min[squares[k]+i]>min[i]+1)
				min[squares[k]+i]=min[i]+1;
			i++;
		}
	}
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d",&i);
		printf("%d\n",min[i]);
	}	
	return 0;
}					
			
			
					
		
				
