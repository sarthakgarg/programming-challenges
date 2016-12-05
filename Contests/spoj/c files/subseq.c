#include<stdio.h>
#define getcx getchar_unlocked
int inp( )//fast input function
{
   int n=0;
   int ch=getcx();int sign=1;
   while( ch < '0' || ch > '9' ){if(ch=='-')sign=-1; ch=getcx();}

   while(  ch >= '0' && ch <= '9' )
           n = (n<<3)+(n<<1) + ch-'0', ch=getcx();
   n=n*sign;
   return n;
}
int arr[6000000];
int temp[6000000];
int merge1(int arr[],int low,int mid,int high)
{

	int i,m,k,l,c1=0,temp1,temp2,ct1,ct2;
	l=low;
    i=low;
    m=mid+1;
	while((l<=mid)&&(m<=high))  
	{
		ct1=0;
		ct2=0;
		if(arr[m]-arr[l]>47)
			l++;
		else if(arr[m]-arr[l]<47)
			m++;
		else 
		{
			temp1=arr[l];
			temp2=arr[m];
			while(l<=mid&&arr[l]==temp1)
			{
				l++;
				ct1++;
			}
			while(m<=high&&arr[m]==temp2)
			{
				m++;
				ct2++;
			}
			c1+=ct1*ct2;
							
		}			
	}	
	l=low;
    m=mid+1;  
	while((l<=mid)&&(m<=high))
	{
         if(arr[l]<=arr[m])
         {
             temp[i]=arr[l];
             l++;
         }
         else
         {
             temp[i]=arr[m];
             m++;
         }
         i++;
    }

    if(m<=high)
    {
         for(k=m;k<=high;k++)
         {
             temp[i]=arr[k];
             i++;
         }
    }
    if(l<=mid)
    {
         for(k=l;k<=mid;k++)
         {
             temp[i]=arr[k];
             i++;
         }
    }
   
    for(k=low;k<=high;k++)
    {
         arr[k]=temp[k];
    }
	return c1;
}

int mergesort(int arr[],int low,int high)
{

    int mid,c1=0,c2=0,c3=0;
	if(low<high)
    {
         mid=(low+high)/2;
     	c1 = mergesort(arr,low,mid);
        c2 = mergesort(arr,mid+1,high);
        c3 = merge1(arr,low,mid,high);
    }
    return c1+c2+c3;
}


int main()
{
   int t,n,sum,x,i,c;
   t=inp();
   while(t--)
   {
   		c=0;
   		sum=0;
   		n=inp();
   		for(i=0;i<n;i++)
   		{
   			x=inp();
   			sum+=x;
   			arr[i]=sum;
   			if(arr[i]==47)
   				c++;
   		}

   		c+=mergesort(arr,0,n-1);
   		printf("%d\n",c);
   	}		
 return 0;
}




