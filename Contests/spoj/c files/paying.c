#include<stdio.h>
int main()
{
	int i,j,k,t,start,carry,temp,temp1,decimal[1005],binary[3500];
	long long count;
	char ch;
	scanf("%d",&t);
	scanf("%c",&ch);
	while(t--)
	{
		i=0;
		do
		{
			scanf("%c",&ch);
			decimal[i]=ch-'0';
			i++;
		}while(ch!='\n');
		i--;                //access from 0 to i-1 only
		start=0;
		k=0;
		while(1)
		{
			temp=0;
			for(j=start;j<i;j++)
			{
				temp1=decimal[j];
				decimal[j]/=2;
				if((temp%2)!=0)
					decimal[j]+=5;
				temp=temp1;
			}
			if(decimal[start]==0)
				start++;
			binary[k]=temp%2;
			k++;
			if(start>i-1)
				break;
		}
		count=0;
		for(j=0;j<k;)
		{
			if(binary[j]==1)
			{
				
				temp=j+1;
				count++;
				j--;
				while((binary[j]==0)&&j>=0)
				{
					binary[temp-1]=0;
					count++;
					binary[j]=1;
					j--;
				}
				j=temp;
			}
			else j++;
		}	
		printf("%lld\n",count);
	}
	return 0;
}						
			
			
					
