#include<stdio.h>
#include"iostream"
using namespace std ;
int visit[30][30]={{0}};
int seq[30][2]={{0}};
int r,c;
int explore(int count,int x,int y)
{
  int flag=0;
  if(!(visit[x][y]==0&&x<=r&&x>=1&&y<=c&&y>=1))
    return -1;
  visit[x][y]=count; 
  seq[count][0]=x;
  seq[count][1]=y;
  if(count==r*c)
    return 1;
  if(explore(count+1,x-2,y-1)==1)
    return 1;
  else 
    {
      if(x>2&&y>1&&visit[x-2][y-1]==count+1)
	  visit[x-2][y-1]=0;
      if(explore(count+1,x-2,y+1)==1)
	return 1;
      else 
	{
	  if(x>2&&visit[x-2][y+1]==count+1)
	      visit[x-2][y+1]=0;
	  if(explore(count+1,x-1,y-2)==1)
	    return 1;
	  else
	    {
	      if(x>1&&y>2&&visit[x-1][y-2]==count+1)
		  visit[x-1][y-2]=0;
	      if (explore(count+1,x-1,y+2)==1)
		return 1;
	      else
		{
		  if(x>1&&visit[x-1][y+2]==count+1)
		      visit[x-1][y+2]=0;
		}
		  if(explore(count+1,x+1,y-2)==1)
		    return 1;
		  else 
		    {
		      if(y>2&&visit[x+1][y-2]==count+1)
			  visit[x+1][y-2]=0;
		      if(explore(count+1,x+1,y+2)==1)
			return 1;
		      else
			{
			  if(visit[x+1][y+2]==count+1)
			    visit[x+1][y+2]=0;
			  if(explore(count+1,x+2,y-1)==1)
			    return 1;
			  else 
			    {
			      if(y>1&&visit[x+2][y-1]==count+1)
				  visit[x+2][y-1]=0;
			      if(explore(count+1,x+2,y+1)==1)
				return 1;
			      else
				{ 
				  if(visit[x+2][y+1]==count+1)
				    visit[x+2][y+1]=0;
				  return -1;
				}
			    }
			}
		    }
		}
	    }
	}
    }
}
int main()
{
  int i,j,t;
  scanf("%d",&t);
  while(t--)
    {
      for(i=0;i<30;i++)
	for(j=0;j<30;j++)
	  visit[i][j]=0;
      scanf("%d%d",&c,&r);
      j=explore(1,1,1);
      if(j==-1)
	{
	  printf("-1\n");
	  continue;
	}
      for(i=1;i<=r*c;i++)
	printf("%c%d",seq[i][0]+'A' -1,seq[i][1]);
      printf("\n");
    }
  return 0;
}
