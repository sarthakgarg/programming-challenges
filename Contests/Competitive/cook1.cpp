#include<stdio.h>
#include"iostream"
#include<vector>
#include<algorithm>
using namespace std;
typedef long long ll ;
int main()
{
  ll i,temp,t,n,co;
  scanf("%lld",&t);
  while(t--)
    {
      vector<ll> cost;
      scanf("%lld",&n);
      for(i=0;i<n;i++)
	{
	  scanf("%lld",&temp);
	  cost.push_back(temp);
	}
      co=0;
      sort(cost.begin(),cost.end());
	for(i=n-1;i>=3;i-=4)
	  co+=cost[i]+cost[i-1];
      if(n%4==1)
	co+=cost[0];
      else if(n%4==2)
	co+=cost[0]+cost[1];
      else if(n%4==3)
	co+=cost[1]+cost[2];
      printf("%lld\n",co);
    }
  return 0;
}
