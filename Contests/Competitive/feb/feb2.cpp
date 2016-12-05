#include<stdio.h>
#include"iostream"
using namespace std;
typedef long long ll;
ll inp[120000];
int main()
{
  ll i,j,t,n;
  scanf("%lld",&t);
  while(t--)
    {
      ll num[100006]={0};
      scanf("%lld",&n);
      for(i=0;i<n;i++)
	{
	  scanf("%lld",&j);
	  num[j]++;
	}
      j=-1;
      for(i=0;i<100001;i++)
	{
	  if(j<num[i])
	    j=num[i];
	}
      printf("%lld\n",n-j);
    }
  return 0;
}
