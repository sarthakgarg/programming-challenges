#include<stdio.h>
#include"iostream"
#include<queue>
using namespace std;
typedef pair<int,int> p;
typedef pair<p,int> pp;
p nbour(int i,int j,int k)
{
  switch(k)
    {
    case 1: return p(i-1,j);
    case 2: return p(i,j+1);
    case 3: return p(i+1,j);
    case 4: return p(i,j-1);
    }
  return p(0,0);
}
int main()
{
  int n,m;
  while(1)
    {
      int es[102][102]={{0}},visited[102][102][16]={{{0}}},key[102][102]={{0}}, wall[102][102]={{0}},startx,starty,i,j,k,door[102][102]={{0}},dist[102][102]={{0}},d;
      char ch;
      int v,v1,flag=0;
      queue <pp> bfs;
      scanf("%d%d",&n,&m);
      pp node;
      if(n==0)
	break;
      scanf("%c",&ch);
      for(i=0;i<n;i++)
	{
	  for(j=0;j<m;j++)
 	    {
	      scanf("%c",&ch);
	      switch(ch)
		{
		case 'X': es[i][j]=1;
		  break;
		case '#': wall[i][j]=1;
		  break;
		case 'R': door[i][j]=1;
		  break;
		case 'G': door[i][j]=2;
	      break;
		case 'B': door[i][j]=4;
		  break;
		case 'Y': door[i][j]=8;
		  break;
		case 'r': key[i][j]=1;
		  break;
		case 'g': key[i][j]=2;
		  break;
		case 'b': key[i][j]=3;
		  break;
		case 'y': key[i][j]=4;
	      break;
		case '*': startx=i;
		  starty=j;
		  break;
		}
	    }
	  scanf("%c",&ch);
	}
      bfs.push(pp(p(startx,starty),0));
      visited[startx][starty][0]=1;
      while(!bfs.empty())
	{
	  node=bfs.front();
	  bfs.pop();
	  v=node.second;
	  d=dist[node.first.first][node.first.second];
	  for(i=1;i<=4;i++)
	    {
	      if(key[node.first.first][node.first.second]==i&&(v>>(i-1))%2==0)
		v+=1<<(i-1);
	      visited[node.first.first][node.first.second][v]=1;
	    }
	  for(k=1;k<=4;k++)
	    {
	      i=nbour(node.first.first,node.first.second,k).first;
	      j=nbour(node.first.first,node.first.second,k).second;
	      if(i>=0&&i<n&&j>=0&&j<m)
		{
		  if(visited[i][j][v]!=1&&wall[i][j]==0&&(door[i][j]==0||(door[i][j]&v)==door[i][j]))
		    {
		      visited[i][j][v]=1;
		      dist[i][j]=d+1;
		      if(es[i][j]==1)
			{
			  printf("Escape possible in %d steps.\n",dist[i][j]);
			  flag=1;
			  break;
			}
		      bfs.push(pp(p(i,j),v));
		    }
		}
	    }
	  if(flag==1)
	    break;
	}
      if(flag==0)
	printf("The poor student is trapped!\n");
    }
  return 0;
}
