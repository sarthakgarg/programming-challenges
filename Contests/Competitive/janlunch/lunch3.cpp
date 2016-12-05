#include<stdio.h>
#include"iostream"
using namespace std;
typedef long long ll;
ll modexp(ll a,ll b,ll p)
{
  //  printf(" y %lld %lld\n",a,b);
  ll x;
  if(b==0)
    return 1;
  x=modexp(a,b/2,p);
  x=(x*x)%p;
  if(b%2==1)
    x=(x*a)%p;
  return x;
}
int main()
{
  ll i,t,m,a,b,prod;
  char str[100000],ch;
  scanf("%lld",&t);
  while(t--)
    {
      scanf("%lld",&m);
      prod=1;
      scanf("%c",&ch);
      //      printf("%lld   %c",m,ch);
      while(ch!='\n')
	{
	  //	  printf("k");
	  scanf("%lld**%lld",&a,&b);
	  //	  printf("%lld %lld",a,b);
	  prod=(prod*modexp(a,b,m))%m;
	  //	  printf("%lld %lld ",a,b);
	  scanf("%c",&ch);
	}
      printf("%lld\n",prod);
    }
  return 0;
}
