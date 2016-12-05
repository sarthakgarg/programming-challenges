#include<stdio.h>
#include"iostream"
using namespace std;
typedef long long ll;
int main()
{
  ll i,pow=1,ans=0;
  scanf("%lld",&i);
  while(i!=0)
    {
      if(i%10==4)
	ans+=pow;
      else ans+=2*pow;
      pow*=2;
      i/=10;
    }
  printf("%lld\n",ans);
  return 0;
}
