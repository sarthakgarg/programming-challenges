#include<stdio.h>
#include"iostream"
using namespace std;
typedef  long long ll;
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
  ll pow,t,n,m,p=1000000007,i;
  scanf("%lld",&t);
  while(t--)
    {
      scanf("%lld%lld",&n,&m);
      if(n==1)
	{
	  printf("%lld\n",m);
	  continue;
	}
      if(n==2)
	{
	  printf("%lld\n",(m*(m-1))%p);
	  continue;
	}
      if(m==1||m==2)
	{
	  printf("0\n");
	  continue;
	}
      pow=modexp(m-2,n-2,p);
      pow=(pow*m)%p;
      pow=(pow*(m-1))%p;
      printf("%lld\n",pow);
    }
  return 0;
}
