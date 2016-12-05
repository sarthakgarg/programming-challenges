#include"iostream"
#include<stdio.h>
using namespace std;
typedef long long ll;
ll modexp(ll base,ll power, ll p)
{
  ll x;
  if(power==0)
    return 1;
  x=modexp(base,power/2,p);
  x=(x*x)%p;
  if(power%2==1)
    x=(x*base)%p;
  return x;
}
int main()
{
  ll pow,t,a,k,n,r1,p=1000000007,i;
  scanf("%lld",&t);
  while(t--)
    {
      scanf("%lld%lld",&k,&n);
      if(n==1)
	{
	  printf("1\n");
	  continue;
	}
      if(n==2)
	{
	  printf("%lld\n",k);
	  continue;
	}
      n-=3;
      pow=modexp(2,n,p-1);
      printf("%lld\n",modexp(k,pow,p));
    }
  return 0;
}
