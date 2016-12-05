#include<stdio.h>
#include"iostream"
using namespace std;
typedef long long ll;
ll mod(ll a,ll b)
{
  if(a>b)
    return a-b;
  else 
    return b-a;
}
int main()
{
  ll res,arr[20000],n,m,d,ans1=0,ans2=0,i,j,med[20000]={0};
  scanf("%lld%lld%lld",&n,&m,&d);
  for(i=0;i<n*m;i++)
      scanf("%lld",&arr[i]);
  res=arr[0]%d;
  for(i=0;i<n*m;i++)
    {
      if(arr[i]%d!=res)
	{
	  printf("-1\n");
	  return 0;
	}
      arr[i]-=res;
      arr[i]/=d;
      med[arr[i]]++;
    }
  i=0;
  while(1)
    {
      ans1+=med[i];
      if(ans1>n*m-ans1)
	break;
      else i++;
    }
  ans1=i;
  for(i=0;i<n*m;i++)
    ans2+=mod(arr[i],ans1);
  printf("%lld\n",ans2);
  return 0;
}
