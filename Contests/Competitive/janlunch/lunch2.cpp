#include<stdio.h>
#include"iostream"
using namespace std;
typedef unsigned long long ull ;
ull po(ull a,ull b)
{
  ull temp=1;
  while(b)
    {
      temp*=a;
      b--;
    }
  return temp;
}
ull d,n;
ull eval(ull x)
{
  ull sum1=0;
  long long sum2=-1;
  ull temp=x;
  while(temp)
    {
      sum1+=temp%d;
      if(sum2==-1)
	sum2=temp%d;
      else sum2=sum2^(temp%d);
      temp/=d;
    }
  return sum1*sum2;
}
ull arr[100000000];
void find()
{
  arr[0]=0;
  ull temp,count=0,i,j;
  for(i=1;i<po(d,n);i++)
    {
      count=0;
      temp=i;
      while(temp!=0)
	{
	  temp/=d;
	  count++;
	}
      ull min=1000000000000000000;
      for(j=0;j<count;j++)
	{
	  if(arr[i-po(d,j)]<min)
	    min=arr[i-po(d,j)];
	}
	  min+=eval(i);
	  arr[i]=min;
    }
}
int main()
{
  ull t,i,j;
  scanf("%llu",&t);
  while(t--)
    {
      scanf("%llu%llu",&n,&d);
      find();
      //    for(i=0;i<po(d,n);i++)
      //	printf(" %llu %llu\n",i,arr[i]);
      printf("%llu\n",arr[po(d,n)-1]);
    }
  return 0;
}
      
