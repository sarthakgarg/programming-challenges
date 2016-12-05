#include<stdio.h>
#include"iostream"
using namespace	std;
typedef	long long ll;
int visit[30][30],n,m;
int explore(int x,int y,int ct,int seq[][2])
{
  int lcount,k,i,j;
  if( (x<0)||(x>=n)||y<0||y>=m)
    {	
     return -1;
    }
    seq[ct][0]=x;
    seq[ct][1]=y;
    ct++;
    for(k=0;k<8;i++)
      {
		i=pref(x,y,k).first;
    	j=pref(x,y,k).second;
		lcount=explore(i,j,ct,seq);	
		if(lcount+ct==n*m);
          return lcount;
      }
    return -1;
}













}
int main()
{
  int t,i;
  scanf("%d",&t);
  while(t--)
    {
      int seq[30][2],count;
      scanf("%d%d",&n,&m);
      count=explore(0,0,0,seq);
      if(count==n*m)
        {
          for(i=0;i<count;i++)
            printf("%c%d",seq[i][1]+'A',seq[i][0]);
        }
      else
        printf("-1\n");
    }
  return 0;
}