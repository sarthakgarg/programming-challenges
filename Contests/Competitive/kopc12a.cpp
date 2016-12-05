#include<stdio.h>
#include"iostream"
#include<vector>
#include<algorithm>
using namespace std;
typedef long long ll ;
ll n,j;
vector< pair<ll,ll> > pre,fin;
vector< pair<ll,ll> > ::iterator it1,it2;
ll mod(ll a)
{
  if(a<0)
    return -a;
  else return a;
}
int predicate(ll k)
{
  ll sum1=0,sum2=0,i; 
  for(i=0;i<j;i++)
    {
      sum1+=((fin[i].second)*mod(fin[i].first-k));
      sum2+=((fin[i].second)*mod(fin[i].first-k-1));
    }
  if(sum1>sum2)
    return 0;
  else return 1;
}
ll binary_search()
{
  ll lo=0,hi=j-1,mid,i,sum=0;
  while(lo<hi)
    {
      mid=lo+(hi-lo)/2;
      if(predicate(fin[mid].first)==0)
	  lo=mid+1;
      else hi=mid;
    }
  for(i=0;i<j;i++)
      sum+=((fin[i].second)*mod(fin[i].first-fin[lo].first));
  return sum;
}
int main()
{
  ll t,i,temp,sum;
  scanf("%lld",&t);
  while(t--)
    {
      scanf("%lld",&n);
      for(i=0;i<n;i++)
	{
	  scanf("%lld",&temp);
	  pre.push_back(pair<ll,ll>(temp,0));
	}
      for(i=0;i<n;i++)
	scanf("%lld",&pre[i].second);
      sort(pre.begin(),pre.end());
      j=0;
      sum=pre[0].second;
      temp=pre[0].first;
      for(i=1;i<n;i++)
	{
	  if(pre[i].first==temp)
	      sum+=pre[i].second;
	  else
	    {
	      fin.push_back(pair<ll,ll>(temp,sum));
	      j++;
	      temp=pre[i].first;
	      sum=pre[i].second;
	    }
	}
      fin.push_back(pair<ll,ll>(temp,sum));
      j++;
      printf("%lld\n",binary_search());
      pre.erase(pre.begin(),pre.end());
      fin.erase(fin.begin(),fin.end());
    }
  return 0;
}
