#include<stdio.h>
#include"iostream"
#include<vector>
#include<map>
#include<algorithm>
using namespace std;
typedef long long ll;
ll p=1000000007,m;
typedef pair<ll,ll> llp;
map <llp,ll> vert; 
vector<pair<llp,llp> > edm;
vector<pair<llp,llp> >::iterator edm1,edm2;
map <llp,ll>::iterator mit,mit1;
vector<ll> pos,cumul;
vector<ll>::iterator it,it1,it2,it3;
ll modexp(ll a ,ll b)
{
  ll x;
  if(b==0)
    return 1;
  x=modexp(a,b/2);
  x=(x*x)%p;
  if(b%2==1)
    x=(x*a)%p;
  return x;
}
ll calc(llp st)
{
  ll val=0,layer=st.first,ct;
  if(layer==0)
    val++;
  else 
    val+=modexp(m,layer-1);
  if(vert.find(st)!=vert.end())
    val=(val+vert[st])%p;
  if(pos.begin()!=pos.end())
    {
      it=upper_bound(pos.begin(),pos.end(),layer);
      if(it!=pos.begin())
	{
	  ct=it-pos.begin();
	  ct--;
	  val=(val+(cumul[ct]*modexp(m,layer-pos[ct]))%p)%p;
	}
    }
  return val;
}
int main()
{
  ll n,k,i,l1,v1,l2,v2,val=0,ct=-1,layer,flag=0,num=1;
  scanf("%lld%lld%lld",&n,&m,&k);
  for(i=0;i<k;i++)
    {
      scanf("%lld%lld%lld%lld",&l1,&v1,&l2,&v2);
      edm.push_back(pair<llp,llp>(llp(l2,v2),llp(l1,v1)));
    }
  sort(edm.begin(),edm.end());
  edm2=edm.end();
  for(edm1=edm.begin();edm1!=edm2;edm1++)
    {
      val=calc(edm1->second);
      num++;
      if(vert.find(edm1->first)!=vert.end())
	vert[edm1->first]=(vert[edm1->first]+val)%p;
      else vert[edm1->first]=val;
      layer=(edm1->first).first+1;
      if(ct!=-1)
	{
	  if(pos[ct]==layer)
	    cumul[ct]=(cumul[ct]+val)%p;
	  else 
	    {
	      ct++;
	      pos.push_back(layer);
	      cumul.push_back((val+(cumul[ct-1]*modexp(m,pos[ct]-pos[ct-1]))%p)%p);
	    }
	}
      else 
	{
	  ct++;
	  pos.push_back(layer);
	  cumul.push_back(val);
	}
    }
    printf("%lld\n",calc(llp(n+1,0)));
  return 0;
}
