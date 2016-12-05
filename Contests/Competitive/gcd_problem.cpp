#include<stdio.h>
#include<stdlib.h>
#include"iostream"
#include<sstream>
#include<string>
using namespace std;
typedef long long ll;
ll gcd(ll a ,ll b)
{
  if(b==0)
    return a;
  else return gcd(b,a%b);
}
int main()
{
  ll t,i,j,deci;
  scanf("%lld",&t);
  while(t--)
    {
      deci=0;
      scanf("%lld.%lld",&deci,&deci);
      i=1;
      while(deci/i!=0)
	i*=10;
      printf("%lld\n",i/gcd(i,deci));
    }
  return 0;
}
