#include<stdio.h>
#include"iostream"
#include<vector>
#include<algorithm>
using namespace std;
typedef long long ll;
int main()
{
  ll j,count,i,n,k,temp,sum=0;
  vector<pair<ll,ll> >vi;
  scanf("%I64d%I64d",&n,&k);
  for(i=0;i<n;i++)
    {
      scanf("%I64d",&temp);
      vi.push_back(pair<ll,ll>(temp,i));
    }
  count=0;
  sort(vi.begin(),vi.end());
  for(i=0;i<n;i++)
    {
      sum+=vi[i].first;
      if(sum<=k)
	count++;
      else break;
    }
  printf("%I64d\n",count);
  for(j=0;j<i;j++)
    {
      printf("%I64d\n",(vi[j].second)+1);
    }
  return 0;
}

