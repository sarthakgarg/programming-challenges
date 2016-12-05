#include<stdio.h>
#include"iostream"
using namespace std;
typedef long long ll;
ll gcd(ll a ,ll b)
{
  if(b==0)
    return a;
  return gcd(b,a%b);
}
ll arr[20008]={0};
int predicate(ll x)
{
  while(x!=0)
    {
      if(x%10!=0&&x%10!=1)
	return 0;
      x/=10;
    }
  return 1;
}
int main()
{
  ll i,j,k,temp,add;
  for(i=1;i<20001;i++)
    {
      printf("%lld  ",i);
      for(temp=1;temp<=4096*512;temp++)
	{
	  k=0;
	  add=1;
	  j=temp;
	  while(j!=0)
	    {
	      add*=10;
	      if(j%2==1)
		k+=add/10;
	      j/=2;
	    }
	  if(k>=i)
	    {
	      if(gcd(k,i)==i)
		{   
		  arr[i]=k;
		  printf("%lld\n",arr[i]);
		  break;
		}
	    }
	}
      if(arr[i]==0)
	{
	  printf("fail\n");
	  break;
	}
    }
  return 0;
}
