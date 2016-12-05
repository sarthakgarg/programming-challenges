#include<stdio.h>
#include"iostream"
using namespace std;
typedef long long ll;
ll sum=0;
void pow(ll p,ll a)
{
  ll x=1,i;
  for(i=0;i<a+1;i++)
    x*=p;
  x--;
  x=x/(p-1);
  sum*=x;
}
int main()
{
  ll ct,t,s[40000]={0},i,j,k,n,p[10000];
  for(i=2;i*i<40000;i++)
    {
      if(s[i]==0)
	{
	  for(j=2*i;j<40000;j+=i)
	    s[j]=1;
	}
    }
  k=0;
  for(i=2;i<40000;i++)
    {
      if(s[i]==0)
	{
	  p[k]=i;
	  k++;
	}
    }
  //  printf("%lld\n",k);
  // for(i=0;i<5;i++)
  // printf("%lld\n",p[i]);
  scanf("%lld",&t);
  while(t--)
    {
      scanf("%lld",&n);
      sum=1;
      for(i=0;i<k;i++)
	{
	  ct=0;
	  while(n%p[i]==0)
	    {
	      ct++;
	      n/=p[i];
	    }
	  if(ct!=0)
	    pow(p[i],ct);
	}
      if(n!=1)
	pow(n,1);
      printf("%lld\n",sum);
    }
  return 0;
}
