#include<stdio.h>
#include<map>
#include"iostream"
#include<string.h>
using namespace std;
typedef long long ll;
map<ll,ll> m;
map<ll,ll>::iterator it;
int main()
{
  ll i,j,n,val,eltcount=0,mapcount=0;
  char str[10];
  scanf("%lld",&n);
  while(n--)
    {
      scanf("%s",str);
      scanf("%lld",&val);
      it=m.find(val);
      if(strcmp(str,"insert")==0)
	{
	  if(it==m.end())
	    {
	      m.insert(pair<ll,ll>(val,1));
	      mapcount++;
	    }
	  else 
	    m[val]++;
	  eltcount++;
	}
      else 
	{
	  if(it!=m.end())
	    {
	      eltcount--;
	      if(it->second>1)
		it->second--;
	      else
		{
		  m.erase(it);
		  mapcount--;
		}
	    }
	}
      if(eltcount<2)
	printf("neither\n");
      else if(mapcount<eltcount && mapcount>1)
	printf("both\n");
      else if(mapcount<eltcount)
	printf("homo\n");
      else if(mapcount>1)
	printf("hetero\n");
    }
  return 0;
}
	  
