#include<stdio.h>
#include"iostream"
typedef long long ll;
using namespace std;
int main()
{
  ll t,n,temp,count,k;
  scanf("%lld",&t);
  while(t--)
    {
      scanf("%lld%lld",&n,&k);
      count=0;
      if(k==1)
	{
	  printf("%lld\n",n);
	  continue;
	}
      while(n!=0)
	{
	  count+=n%k;
	  n/=k;
	}
      printf("%lld\n",count);
    }
  return 0;
}
