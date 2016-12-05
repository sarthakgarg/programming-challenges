#include<stdio.h>
#include"iostream"
typedef long long ll;
using namespace std;
int main()
{
  ll t,e,o,k;
  scanf("%lld",&t);
  while(t--)
    {
      scanf("%lld%lld",&e,&o);
      if(2*o>3*e)
	{
	  if((2*o-3*e)%5==0)
	    {
	      printf("%lld\n",(2*o-3*e)/5);
	      continue;
	    }
	}
      else 
	{
	  if((3*e-2*o)%5==0)
	    {
	      printf("%lld\n",(3*e-2*o)/5);
	      continue;
	    }
	}
      printf("-1\n");
    }
  return 0;
}
	  
