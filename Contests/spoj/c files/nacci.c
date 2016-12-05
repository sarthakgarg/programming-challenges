#include<stdio.h>
#include<math.h>
int dig,n;
long long int arr[50][50],arr1[50][50],mult[50][50];
void multiply(int k)
{
	int i,j,l;
	long long sum;
	if(k==0)
	{
		for(i=0;i<n;i++)
			for(j=0;j<n;j++)
				mult[i][j] = arr[i][j];
		for(i=0;i<n;i++)
		{
			for(j=0;j<n;j++)
			{
				sum=0;
				for(l=0;l<n;l++)
				{
					sum+=(mult[i][l]*mult[l][j])%dig;
					sum= sum%dig;
				}		
				arr[i][j]=sum;
			}
		}
	}
	else 
	{
		for(i=0;i<n;i++)
			for(j=0;j<n;j++)
				mult[i][j] = arr[i][j];
		for(i=0;i<n;i++)
		{
			for(j=0;j<n;j++)
			{
				sum=0;
				for(l=0;l<n;l++)
				{
					sum+=(mult[i][l]*arr1[l][j])%dig;
					sum= sum%dig;
				}	
				arr[i][j]=sum;
			}
		}
	}
								
}
void findfib(int m)
{
	if(m==1)
     return;
    findfib(m/2);
	multiply(0);
	if(m%2!=0)
		multiply(1);
}				
int main()
{
	int i,j,k,l,t;
	long long ans ;
	scanf("%d",&t);
	while(t--)
	{
		ans=0;
		scanf("%d",&n);
		scanf("%d",&k);
		scanf("%d",&l);
		dig = pow(10,k);
		if(l < n)
		{
			printf("%d\n",l%dig);
			continue ;
		}	
		for(i=0;i<n;i++)
		{
			for(j=0;j<n;j++)
			{
				if(i==0)
				{
					arr[i][j]=1;
					arr1[i][j]=1;
				}	
				else if(i==j+1)
				{
						arr[i][j]=1;
						arr1[i][j]=1;
				}		
				else
				{ 
					arr[i][j]=0;
					arr1[i][j]=0;
				}	
			}		
		}			
		findfib(l-n+2);
		for(j=0;j<n;j++)
		{
			ans +=(arr[1][j]*(n-1-j))%dig;
			ans = ans%dig;
		}
		printf("%lld\n",ans);
	}
return 0;
}	
		


