#include<stdio.h>
int flag,count;
int max(a,b)
{
	if(a>b)
		return a;
	else return b;
}		
int main()
{
	int i,j,arr[9005],n,sum,avg,small[9005]={0},big[9005]={0},tempb,temps,a,b;
	while(1)
	{
		sum=0;	
		scanf("%d",&n);
		if(n==-1)
			return 0;
		for(i=0;i<n;i++)
		{
			scanf("%d",&arr[i]);
			sum+=arr[i];
		}
		if(sum % n!=0)
		{
			printf("-1\n");
			continue;
		}
		avg=sum/n;
		j=0;
		sum=0;
		for(i=0;i<n;i++)
		{
			if(arr[i]>=avg)
				sum+=arr[i];
			if(arr[i]<avg)
			{
				big[j]=sum;
				sum=0;
				small[j]=arr[i]	;
				j++;
			}
		}
		if(sum!=0)
		{
			tempb=j;
			big[j]=sum;
			temps=j-1;
		}
		else
		{ 
			tempb=j-1;
			temps=j-1;
		}
		flag=0;
		count=0;
		//big[j] indicated big between small[j] & small[j-1];
		while(flag==0)
		{	
			flag=1;
			for(i=0;i<=temps;i++)
			{
					
				if(small[i]<avg)
				{
					flag=0;
					if(big[i]>avg)
					{
						big[i]--;
						small[i]++;
					}
				}
				if(small[i]<avg)
				{
					flag=0;
					if(i+1<=tempb&&big[i+1]>avg)
					{
						big[i+1]--;
						small[i]++;
					}
				}

			}
			if(flag==0)
				count++;	
			a=0;
			b=0;			
			for(i=0;i<=temps;i++)
			{
				if(small[i]==avg)
				{
					big[i]=big[i]+big[i+1]+avg;
					if(i+1<=tempb)
						big[i+1]=big[i];
					small[i]=avg+1;	
				}		
			}			

			for(i=0;i<=tempb;i++)
				printf("%d ",big[i]);
			printf("\n");
			for(i=0;i<=temps;i++)
				printf("%d ",small[i]);
			printf("\n\n");				
					
		}	
		printf("%d\n",count);
	}
	return 0;
}							
