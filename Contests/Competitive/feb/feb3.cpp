#include<stdio.h>
#include"iostream"
using namespace std;
typedef long long ll;
int main()
{
  ll n,s,t,i;
  scanf("%lld",&t);
  while(t--)
    {
      scanf("%lld%lld",&n,&s);
      for(i=n;i>0;i--)
	{
	  if(i*(i+1)>2*s)
	    continue;
	  if(i*(i-1)>2*(s-n))
	    continue;
	  break;
	}
      printf("%lld\n",n-i);
    }
  return 0;
}
