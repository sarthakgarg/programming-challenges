#include<stdio.h>
#include"iostream"
using namespace std;
typedef long long ll;
ll a,b,n,l,t,m,i,j;
ll f(ll x)
{
  ll p = (x-l+1)*(2*a+(x+l-2)*b)/2;
  if(t<a+(x-1)*b)
    return 1;
  if(p<=t*min(m,x-l+1))
    return 0;
  else return 1;
}
ll binary(ll lo,ll hi)
{
  ll mid,pred;
  mid=lo + (hi-lo+1)/2;
  while(lo<hi)
    {
      //    printf("%lld %lld %lld\n",mid,lo,hi);
      mid=lo+(hi-lo+1)/2;
      pred=f(mid);
      if(pred==0)
	{
	  lo=mid;
	}
      else 
	hi=mid-1;
    }
  return lo;
}
int main()
{
  scanf("%lld%lld%lld",&a,&b,&n);
  for(i=0;i<n;i++)
    {
      scanf("%lld%lld%lld",&l,&t,&m);
      if(t<a+(l-1))
	{
	  printf("-1\n");
	  continue;
	}
      printf("%lld\n",binary(l,100000000));
    }
  return 0;
}
