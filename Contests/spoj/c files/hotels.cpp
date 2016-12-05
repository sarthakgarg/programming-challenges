#include<stdio.h>
#include"iostream"
#include<stdlib.h>
using namespace std;
#define gc getchar_unlocked

 inline int getn() 
 {
    int n=0;
    int ch=gc();
    while( ch < '0' || ch > '9' ){ch=gc();}

    while(  ch >= '0' && ch <= '9' )
            n = (n<<3)+(n<<1) + ch-'0', ch=gc();
    
    return n ;
  }   
 
int main()
{	
	unsigned long temp;
	unsigned long *sum;

	int j,n,m,index=0,max=0,arr,l1,l2,binary,mid,flag;
	n = getn();
	m =getn();
	sum = (unsigned long int *)calloc(1000002,sizeof(unsigned long int ));
	sum[0]=0;	
	for(j=1;j<=n;j++)
	{
	    arr=getn();
		sum[j]=sum[j-1]+arr;
	 	if(sum[j]==m)
	 	{
	 		printf("%d\n",m);
	 		free(sum);
	 		return 0;
	 	}
	 	if(sum[j]>m) break;
	 }	

	 	for(;j<n;j++)
	 	{
	 		sum[j]=sum[j-1]+arr;

	 		
	 		l1 = j;
	 		l2 = sum[j] -m ;
	 flag=0;		
	while(index<=l1)
	{
		mid=(index+l1)>>1;
		if(sum[mid]==l2)
		{
			index=mid;
			binary = l2;
			flag=1;
			break;
		}
		else if(sum[mid]<l2)
			index=mid+1;
		else l1=mid-1;
	}
	if(flag==0)
	{
		index=(l1+index)>>1;
		if(sum[index]<l2)
		index++;
		binary = sum[index];
	}		


	 		temp=sum[j]-binary;
			if(max<temp)
	 			max=temp;
		 	if(max==m)
		 	{
		 		printf("%d\n",m);
		 		free(sum);
		 		return 0;
		 	}

		 	arr=getn();
			
		}
		sum[j]=sum[j-1]+arr;
			
	 		l1 = j;
	 		l2 = sum[j] -m ;
	 flag=0;		
	while(index<=l1)
	{
		mid=(index+l1)>>1;
		if(sum[mid]==l2)
		{
			index=mid;
			binary = l2;
			flag=1;
			break;
		}
		else if(sum[mid]<l2)
			index=mid+1;
		else l1=mid-1;
	}
	if(flag==0)
	{
		index=(l1+index)>>1;
		if(sum[index]<l2)
		index++;
		binary = sum[index];
	}		

	 		temp=sum[j]-binary;
			if(max<temp)
	 			max=temp;
		 	if(max==m)
		 	{
		 		printf("%d\n",m);
		 		free(sum);
		 		return 0;
		 	}
	


	if(sum[j-1]<=m)
		max = sum[j-1];
	free(sum);
	printf("%d\n",max);
	return 0;
}




