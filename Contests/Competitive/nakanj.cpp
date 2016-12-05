#include<stdio.h>
#include"iostream"
using namespace std;
int check(int x,int y)
{
  if(x<0||x>=8||y<0||y>=8)
     return -1;
     else return 8*x+y;
}
int nbour(int a,int ind)
{
  int r,c;
  r=a/8;
  c=a%8;
  switch(ind)
    {
    case 0: return check(r-1,c-2);
	break;
    case 1: return check(r+1,c-2);
      break;
    case 2: return check(r+2,c-1);
	break;
    case 3: return check(r+2,c+1);
	break;
    case 4: return check(r+1,c+2);
	break;
    case 5: return check(r-1,c+2);
	break;
    case 6: return check(r-2,c+1);
      break;
    case 7: return check(r-2,c-1);
      break;
    }
  return 1;
} 

  
int main()
{
  int i,j,k,n,t,w[70][70]={{0}},l[70][70],w1[70][70]={{0}};
  char ch1,ch2;
  for(i=0;i<64;i++)
    {
      for(k=0;k<8;k++)
	{
	  j=nbour(i,k);
	  if(j==-1)
	    continue;
	  w[i][j]=1;
	}
      for(j=0;j<64;j++)
	{
	  if(i==j)
	    continue;
	  if(w[i][j]==0)
	  w[i][j]=2000000;
	}
    }
  /* for(i=0;i<10;i++)
    {
      for(j=0;j<10;j++)
	printf("%d ",w[i][j]);
      printf("\n");
      }*/
  
  for(k=0;k<64;k++)
    {
      for(i=0;i<64;i++)
	for(j=0;j<64;j++)
	  w[i][j]=min(w[i][j],w[i][k]+w[k][j]);
      //    for(i=0;i<64;i++)
      //	for(j=0;j<64;j++)
      //	  w[i][j]=w1[i][j];
    }
  /*  for(i=0;i<10;i++)
    {
      for(j=0;j<10;j++)
	printf("%d ",w[i][j]);
      printf("\n");
      }*/
  scanf("%d",&t);
  while(t--)
    {
      scanf("%c",&ch1);
      scanf("%c%d %c%d",&ch1,&i,&ch2,&k);
      //  printf("input (%c %d %c %d)\n",ch1,i,ch2,k);
      j=ch1-'a';
      n=ch2-'a';
      i=8*j+i-1;
      k=8*n+k-1;
      printf("%d\n",w[i][k]);
    }
}
