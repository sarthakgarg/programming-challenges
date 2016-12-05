#include<stdio.h>
#include"iostream"
#include<vector>
#include<algorithm>
using namespace std;
typedef long long ll;
ll n,c;
vector <ll> x;
ll predicate(ll d)
{
  ll count=1,i=0,j,curr;
  while(i<n)
    {
      if(count>=c)
	return 1;
      curr=x[i];
      while(x[i]<curr+d)
	{
	  i++;
	  if(i>=n)
	    return 0;
	}
      count++;
    }
  return 0;
}
ll binary_search()
{
  ll lo=1,hi=1000000002,mid; 
  while(lo<hi)
    {
      mid=lo + (hi-lo+1)/2;
      if(predicate(mid)==0)
	hi=mid-1;
      else 
	lo=mid;
    }
  return lo;
}
int main()
{
  ll t,i,temp;
  scanf("%lld",&t);
  while(t--)
    {
      scanf("%lld%lld",&n,&c);
      for(i=0;i<n;i++)
	{
	  scanf("%lld",&temp);
	  x.push_back(temp);
	}
      sort(x.begin(),x.end());
      printf("%lld\n",binary_search());
      x.erase(x.begin(),x.end());
    }
  return 0;
}
