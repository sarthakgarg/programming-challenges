#include<stdio.h>
#include"iostream"
#include<deque>
#include<cstdio>
using namespace std;
typedef pair<int,int> p;
typedef pair<p,p> pp;

#define gc getchar_unlocked

void scanint(int &x)
{
  register int c = gc();
  x = 0;
  for(;(c<48 || c>57);c = gc());
  for(;c>47 && c<58;c = gc()) {x = (x<<1) + (x<<3) + c - 48;}
}
int visited[200003][202]={{0}};
int l1[40000000]={0};
int l2[40000000]={0};
deque <pp> bfs;
int word[200005]={0};
int main()
{
  int m,k,n,i,j,q,t,x,y,s,ct,min[200003];
  scanf("%d",&t);
  while(t--)
    {
      for(i=0;i<200003;i++)
	min[i]=1000000000;
      s=0;
      ct=0;
      bfs.erase(bfs.begin(),bfs.end());//ff=position , fs=distance , sf=stage ,ss=word
      int trans[202][202];
      for(i=0;i<202;i++)
	for(j=0;j<202;j++)
	  {
	    if(i==j)
	      trans[i][j]=0;
	    else 
	      trans[i][j]=10000;
	  }
      scanint(m);
      scanint(q);
      scanint(n);
      //  scanf("%d%d%d",&m,&q,&n);
      for(i=0;i<q;i++)
	{
	  scanint(x);
	  scanint(y);
	  //	  scanf("%d%d",&x,&y);
	  trans[x][y]=1;
	  trans[y][x]=1;
	}
      for(i=1;i<=n;i++)
	scanint(word[i]);
      for(k=1;k<=m;k++)
	for(i=1;i<=m;i++)
	  for(j=1;j<=m;j++)
	    {
	      if(trans[i][j]>trans[i][k]+trans[k][j])
		trans[i][j]=trans[i][k]+trans[k][j];
	    }
      for(i=1;i<=m;i++)
	{
	  q=-1;
	  for(j=m;j>=1;j--)
	    {
	      if(trans[i][j]>0&&trans[i][j]<300)
		q=j;
	      trans[i][j]=q;
	    }
	}
      /*             	for(i=1;i<=m;i++)
			{
	  for(j=1;j<=m;j++)
	    printf("%d ",trans[i][j]);
	      printf("\n");
	    }*/
      
      bfs.push_back(pp(p(0,0),p(0,1)));
      visited[0][1]=1;
      l1[ct]=0;
      l2[ct]=1;
      ct++;
      //   list.push(pp(p(0,0),p(0,1)));
      while(!bfs.empty())
	{
	  pp node = bfs.front();
	  bfs.pop_front();
	  x=node.first.second;
	  y=node.first.first;
	  q=node.second.second;
	  
	  if(y==n&&node.second.first==0)
	    {
	      s=1;
	      break;
	    }
	  if(node.second.first==1)
	    {
	      min[y]=trans[word[y]][q];
	      bfs.push_back(pp(p(y,x+1),p(0,q)));
	    }
	  else  
	    {
	      y++;
	      if(trans[word[y]][q]>0&&visited[y][trans[word[y]][q]]==0)
		{
		  if(min[y]<trans[word[y]][q])
		    continue;
		  bfs.push_back(pp(p(y,x+1),p(1,trans[word[y]][q])));
		  l1[ct]=y;
		  l2[ct]=trans[word[y]][q];
		  ct++;
		  visited[y][trans[word[y]][q]]=1;
		}
	      if(word[y]>=q&&visited[y][word[y]]==0)
		{
		  if(min[y]<word[y])
		    continue;
		  min[y]=word[y];
		  bfs.push_back(pp(p(y,x+1),p(0,word[y])));
		  l1[ct]=y;
		  l2[ct]=word[y];
		  ct++;
		  visited[y][word[y]]=1;
		}
	    }
	}
	  if(s==0)
	    printf("-1\n");
	  else 
	    printf("%d\n",x-n);
	  s=0;
      while(ct>0)
	{
	  ct--;
	  visited[l1[ct]][l2[ct]]=0;
	}
      //      printf("%d\n",s);
      
      //  printf("done\n");
    }
  //trans now serves as our adjacency list . 
  return 0;
}
