#include<stdio.h>
#include"iostream"
using namespace std;
typedef long long ll;
ll gc(ll a,ll b)
{
  if(a==0)
    return b;
  else return gc(b%a,a);
}
ll gcd(ll a,ll b)
{
  if(a<b)
    return gc(a,b);
  else return gc(b,a);
}
ll po(ll a,ll b)
{
  ll temp=1;
  while(b)
    {
      temp*=a;
      b--;
    }
  return temp;
}
int main()
{
  ll i,j,n,k,x[17],sum=0,prod,temp,count,num;
  scanf("%lld%lld",&n,&k);
  for(i=0;i<k;i++)
    scanf("%lld",&x[i]);
  for(i=0;i<po(2,k);i++)
    {
      temp=i;
      count=0;
      num=0;
      prod=1;
      while(temp)
	{
	  if(temp%2==1)
	    {
	      count++;
	      prod=(prod*x[num])/gcd(prod,x[num]);
	    }
	  temp/=2;
	  num++;
	}
      if(count%2==0)
	sum+=n/prod;
      else sum-=n/prod;
    }
  printf("%lld\n",sum);
  return 0;
}
      




