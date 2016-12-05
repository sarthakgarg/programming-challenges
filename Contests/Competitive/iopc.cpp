#include<stdio.h>
#include"iostream"
#include<math.h>
#include<queue>
#include<vector>
using namespace std;
typedef long long ll;
vector<ll>::iterator it;
int main()
{
  ll t,c,n,p,m,i,j,x,y,flag,k;
  scanf("%lld",&t);
  while(t--)
    {
      ll visit[205]={0};
      double color[205][205]={{0}};
      queue <ll> bfs;
      vector<ll> adj[205];
      ll edgct[205][2]={{0}};
      scanf("%lld%lld",&c,&p);
      while(p--)
	{
	  scanf("%lld%lld",&x,&y);
	  adj[y].push_back(x);
	  edgct[x][0]++;
	  edgct[x][1]++;
	}
      scanf("%lld%lld",&m,&n);
      while(m--)
	{
	  scanf("%lld%lld",&i,&j);
	  color[i][j]=1;
	  bfs.push(i);
	}
      while(1)
	{
	  while(!bfs.empty())
	    {
	      i=bfs.front();
	      bfs.pop();
	      visit[i]=1;
	      for(it=adj[i].begin();it!=adj[i].end();it++)
		{
		  j=*it;
		  edgct[j][0]--;
		  for(k=1;k<=n;k++)
		    {
		      color[j][k]+=(color[i][k])/edgct[j][1];
		    }
		}
	    }
	  flag=0;
	  for(i=1;i<=c;i++)
	    {
	      if(edgct[i][0]==0&&visit[i]==0)
		{
		  bfs.push(i);
		  flag=1;
		}
	    }
	  if(flag==0)
	    break;
	}
      for(i=1;i<=n;i++)
	{
	  double ans=0;
	  for(j=1;j<=c;j++)
	    ans+=color[j][i];
	  printf("%lf ",ans);
	}
      printf("\n");
    }
  return 0;
}
