#include<stdio.h>
#include"iostream"
using namespace std;
  int visit[20][20]={{0}};

int main()
{
  int x,y,ct=0;
  scanf("%d %d",&x,&y);
  while(visit[x][y]==0)
    {
      visit[x][y]=1;
      printf("%d %d\n",min(x,y),max(x,y));
      ct++;
      x=(x+7)%19;
      y=(y+11)%20;
    }
  printf("%d\n",ct);
  return 0;
}
