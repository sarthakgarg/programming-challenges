#include<stdio.h>
#include"iostream"
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
ll modify(ll x,ll y,ll n)
{
  ll temp=y;
  ll temp1=x;
  ll sum=0;
  ll pow=1;
  while(temp!=0)
    {
      sum=(sum+temp1*(temp%2))%n;
      temp/=2;
      temp1=(temp1*2)%n;
    }
  return sum;
}
ll mod(ll base,ll exp,ll m)
{
  ll x;
  if(exp==0)
    return 1;
  x=mod(base,exp/2,m);
  x=modify(x,x,m);
  if(exp%2==1)
    x=modify(x,base,m);
  return x;

}
ll base[10]={2,3,5,7,11,13,17,19,23,31};
ll prime(ll n)
{
  if(n%2==0)
    return 0;
  ll  i,temp,s=0,j,flag;
  //  printf("check");
  ll x ;
  temp=(n-1);
  while(temp%2==0)
    {
      s++;
      temp/=2;
    }
  for(i=0;i<9;i++)
    {
      x=mod(base[i],temp,n);
      flag=0;
      //    printf("%lld %lld \n",i,x);
      if(x==1||x==n-1)
	continue;
      for(j=1;j<s;j++)
	{
	  x=modify(x,x,n);
	  if(x==n-1)
	    {
	      flag=1;
	      break;
	    }
	}
      if(flag==1)
	continue;
      return 0;
    }
  return 1;
}

int main()
{
  ll t;
  ll temp,i,j,n;
    scanf("%lld",&t);
    //  t=500;
  while(t--)
    {
         scanf("%lld",&n);
	 //  n=1000000000000000000;
	 if(n<29)
	   {
	     i=0;
	     while(n>=base[i])
	       i++;
	     printf("%lld\n",base[i-1]);
		    continue;
	   }
      for(i=n;i>=1;i--)
	{
	  //	  printf("%lld\n",i);
	  if(i%6==1||i%6==5)
	    {
	      if(prime(i)==1)
		{
		  printf("%lld\n",i);
		  break;
		}
	    }
	}
    }
  return 0;
}
