#include<stdio.h>
#include"iostream"
#include<vector>
#include<algorithm>
using namespace std ;
typedef long long ll;
ll tree1[100008]={0};
ll tree2[100008]={0};
ll n;
void up1(ll idx ,ll val)
{
  while (idx <= 100007)
    {
      tree1[idx] += val;
      idx += (idx & -idx);
    }
}
void up2(ll idx ,ll val)
{
  while (idx <= 100007)
    {
      tree2[idx] += val;
      idx += (idx & -idx);
    }
}
void update(ll x,ll y,ll val)
{
  up1(x,val);
  up1(y+1,-val);
}

ll query1(ll idx)
{
  ll sum = 0;
  while (idx > 0)
    {
      sum += tree1[idx];
      idx -= (idx & -idx);
    }
  return sum;
}
ll query2(ll idx)
{
  ll sum = 0;
  while (idx > 0)
    {
      sum += tree2[idx];
      idx -= (idx & -idx);
    }
  return sum;
}
typedef long long ll;
typedef pair<ll,ll> p;
vector<p> srt;
vector<p> ::iterator it;
int main()
{
  ll i,j,pre[100007],q,nd,l,r,flag=0,sum,ans[100007],pos[100007]={0};
  scanf("%lld",&n);
  for(i=1;i<=n;i++)
    {
      scanf("%lld",&pre[i]);
      pos[pre[i]]=i;
    }
  scanf("%lld",&q);
  while(q--)
    {
      scanf("%lld%lld%lld",&nd,&l,&r);
      if((nd==1&&r!=n)||(pos[nd]<l)||(pos[nd]>r))
	{
	  printf("0\n");
	  return 0;
	}
      srt.push_back(p(l,r));
    }
  sort(srt.begin(),srt.end());
  for(it=srt.begin();it!=srt.end();it++)
    {
      l=(*it).first;
      r=(*it).second;
      sum=query2(r-1)-query2(l-1);
      if(sum!=0)
	{
	  flag=1;
	  break;
	}
      up2(r,1);
    }
  if(flag==1)
    {
      printf("0\n");
      return 0;
    }
  update(1,n,1);
  for(it=srt.begin();it!=srt.end();it++)
    {
      l=(*it).first;
      r=(*it).second;
      i=query1(l);
      if(i>=l&&i<=r)
	{
	  flag=1;
	}
      update(l,r,pos[nd]-i);
      update(pos[nd],pos[nd],i-pos[nd]);
    }
  if(flag==1)
    {
      printf("0\n");
      return 0;
    }
  for(i=1;i<=n;i++)
    {
      ans[i]=query1(i);
    }
  printf("1\n");
  for(i=2;i<=n;i++)
    {
      printf("%lld %lld\n",pre[ans[i]],pre[i]);
    }
  return 0;
}
