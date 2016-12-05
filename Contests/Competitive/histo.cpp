#include<stdio.h>
#include"iostream"
#include<stack>
#include<vector>
using namespace std;
typedef long long ll;
stack<pair<ll,ll> > st;
vector<pair<ll,ll> > ::iterator it,it2;
using namespace std;
int main()
{
  ll n,i,j,max,val,count,sum;
  while(1)
    {
      max=-1;
      scanf("%lld",&n);
      if(n==0)
	return 0;
      for(i=0;i<=n;i++)
	{
	  if(i<n)
	    scanf("%lld",&val);
	  else val=-1;
	  count=1;
	  vector<pair<ll,ll> > vi;
	  if(!st.empty())
	    {
	      while((st.top()).first>val)
		{
		  count+=(st.top()).second;
		  vi.push_back(st.top());
		  st.pop();
		  if(st.empty())
		    break;
		}
	      sum=0;
	      if(!vi.empty())
		{
		  for(it=vi.begin();it!=vi.end();it++)
		    {
		      sum+=it->second;
		      if(max<(it->first)*sum)
			max=(it->first)*sum;
		    }
		}
	    }
	  st.push(pair<ll,ll>(val,count));
	}
      printf("%lld\n",max);
    }
  return 0;
} 
