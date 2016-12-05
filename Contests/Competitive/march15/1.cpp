#include<stdio.h>
#include"iostream"
using namespace std;
typedef long long ll;
int main()
{
  ll t,x,y,k,n,p,c,flag;
  scanf("%lld",&t);
  while(t--)
    {
      scanf("%lld%lld%lld%lld",&x,&y,&k,&n);
      flag=0;
      while(n--)
	{
	  scanf("%lld%lld",&p,&c);
	  if(c<=k&&p+y>=x)
	      flag=1;
	}
      if(flag==0)
	printf("UnluckyChef\n");
      else printf("LuckyChef\n");
    }
  return 0;
}
