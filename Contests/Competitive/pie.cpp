#include<stdio.h>
#include"iostream"
using namespace std;
typedef double d;
typedef long long ll;
d v[100005],pi=3.14159265358979;
ll f,n;
ll predicate(d vol)
{
  ll count=0,i=-1;
  double temp=0;
  while(i<n)
    {
      if(count>=f)
	return 1;
      if(temp<vol)
	{
	  i++;
	  if(i==n)
	    return 0;
	  temp=v[i];
	}
      else 
	{
	  temp-=vol;
	  count++;
	}
    }
  return 0;
}
d binary_search()
{
  d lo=0.00000001,hi=10000000000,mid;
  ll count=0;
  while(count<50)
    {
      mid=lo+(hi-lo)/2;
      if(predicate(mid)==0)
	hi=mid;
      else lo=mid;
      count++;
    }
  return mid;
}
int main()
{
  ll t,i;
  d rad;
  scanf("%lld",&t);
    while(t--)
      {
	scanf("%lld%lld",&n,&f);
	f++;
	for(i=0;i<n;i++)
	  {
	    scanf("%lf",&rad);
	    v[i]=pi*rad*rad;
	  }
	printf("%.4lf\n",binary_search());
      }
  return 0;
}









