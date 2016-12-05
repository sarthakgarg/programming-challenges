#include<stdio.h>
#include"iostream"
using namespace std;
typedef long long ll;
int main()
{
  ll l,r,i,j;
  scanf("%lld%lld",&l,&r);
  for(i=l;i<=r;i++)
    {
      for(j=l;j<=r;j++)
	{
	  printf("%lld     ",i^j);
	}
      printf("\n");
    }
  return 0;
}
