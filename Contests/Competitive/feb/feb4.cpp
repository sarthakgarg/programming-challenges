#include<stdio.h>
#include"iostream"
using namespace std;
typedef long long ll;
ll x[10000007]={0};
int main()
{
  ll n,m,k,i,j,sum,temp,ans;
  scanf("%lld%lld",&n,&m);
  if(m!=1)
    {
      x[1]=1;
      for(i=2;i<m;i++)
	x[i]=(x[i-1]*i)%m;
    }
  sum=0;
  for(i=0;i<n;i++)
    {
      temp=0;
      ans=1;
      scanf("%lld",&k);
      if(k+1<m)
	temp+=x[k+1];
      if(k%2==0)
	{
	  ans=((k%m)*((k/2)%m))%m;
	  ans=(ans*((k+1)%m))%m;
	}
      else 
	{
	  ans=((k%m)*(k%m))%m;
	  ans=(ans*(((k+1)/2)%m))%m;
	}
      temp=(temp-1+ans);
      sum+=temp;
    }
  sum=sum%m;
  if(sum<0)
    sum+=m;
  printf("%lld\n",sum);
  return 0;
}
