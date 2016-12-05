#include<stdio.h>
#include"iostream"
#include<queue>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> llp;
typedef pair<llp,llp> llpp;
ll find(ll index,ll n)
{
  if(index==0)
    return 1;
  ll x;
  x=find(index/2,n);
  x=(x*x)%n;
  if(index%2==1)
    x=(x*10)%n;
  return x;
}
int main()
{
  ll t,n,flag,i,j,k,dfn,index,rem,par,zero1,zero2;
  llpp prefix,node;
  scanf("%lld",&t);
  int parent[200000]={0};
  int ch[200001]={0};
  while(t--)
    {
      zero1=0;
      zero2=0;
      queue<llpp> permute;
      flag=-1;
      scanf("%lld",&n);
      while(n%2==0)
	{
	  zero1++;
	  n/=2;
	}
      while(n%5==0)
	{
	  zero2++;
	  n/=5;
	}
      if(zero1<zero2)
	zero1=zero2;
      int states[20001]={0};
      states[1]=1;
      dfn=0;
      permute.push(llpp(llp(1,0),llp(0,1)));
      parent[0]=0;
      ch[0]=1;
      while(flag==-1&&n!=1)
	{
	  prefix=permute.front();
	  permute.pop();
	  index= (prefix.first).second;
	  index++;
	  dfn++;
	  par = (prefix.second).first;
	  parent[dfn]=par;
	  rem=(prefix.second).second;
	  node = llpp(llp(0,index),llp(dfn,rem));
	  ch[dfn]=0;
	  permute.push(node);
	  dfn++;
	  rem = (rem+find(index,n))%n;
	  ch[dfn]=1;
	  node=llpp(llp(1,index),llp(dfn,rem));
	  parent[dfn]=par;
	  if(rem==0)
	      flag=dfn;
	  if(states[rem]==0)
	    {
	      states[rem]=1;
	      permute.push(node);
	    }
	}
      ll ans[50]={0};
      k=0;
      if(n!=1)
	{
	  dfn=flag;
	  while(dfn!=0)
	    {
	      ans[k]=ch[dfn];
	      k++;
	      dfn=parent[dfn];
	    }
	}
      ans[k]=1;
      for(j=0;j<=k;j++)
	  printf("%lld",ans[j]);
      for(j=0;j<zero1;j++)
	printf("0");
      printf("\n");
    }
  return 0;
}
