#include<stdio.h>
#include"iostream"
using namespace std;
typedef long long ll;
int min(int a,int b)
{
  if(a<b)
    return a;
  else return b;
}
int b[1007];
int main()
{
  ll x,xl,k;
  int i, n,t;
  scanf("%d",&t);
  while(t--)
    {
      scanf("%d",&n);
      for(i=0;i<n;i++)
	scanf("%d",&b[i]);
      x=1;
      xl=1;
      for(i=0;i<n-1;i++)
	{
	  x=(x+min(xl,b[i]-1))%1000000009;
	  xl=(1+min(xl,b[i]-1))%1000000009;
	}
      printf("%lld\n",x);
    }
  return 0;
}
