#include<stdio.h>
#include"iostream"
using namespace std;
typedef long long ll;
ll arr[600000];
int main()
{
  ll n,mult=0,i;
  ll sum=0,ans=0;
  scanf("%lld",&n);
  for(i=0;i<n;i++)
    {
      scanf("%lld",&arr[i]);
      sum+=arr[i];
      arr[i]=sum;
    }
  if(sum%3!=0)
    {
      printf("0\n");
      return 0;
    }
  else 
    sum/=3;
  for(i=0;i<n-1;i++)
    {
      if(arr[i]==2*sum)
	ans+=mult;
      if(arr[i]==sum)
	mult+=1;
    }
  printf("%lld\n",ans);
}
