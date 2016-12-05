#include<stdio.h>
#include"iostream"
#include<math.h>
using namespace std;
typedef long long ll;
ll p;
ll r[9]={0};
ll predicate(ll t)
{
  ll sum=0,i,j,l;
  for(i=0;i<8;i++)
    {
      l=t/(i+1);
      sum+=r[i]*(ll)((sqrt(1+8*l)-1)/2);
    }
  if(sum<p)
    return 0;
  else return 1;
}
ll binary()
{
  ll lo=0,hi=1000000000,mid;
  while(lo<hi)
    {
      mid=lo+(hi-lo)/2;
      if(predicate(mid)==0)
	lo=mid+1;
      else 
	hi=mid;
    }      
  return lo+(hi-lo)/2;
}
int main()
{
  ll t,i,j,n;
  scanf("%lld",&t);
  while(t--)
    {
      for(i=0;i<8;i++)
	r[i]=0;
      scanf("%lld%lld",&p,&n);
      while(n--)
	{
	  scanf("%lld",&j);
	  r[j-1]++;
	}
      printf("%lld\n",binary());
    }
  return 0;
}
