#include<stdio.h>
#include"iostream"
using namespace std;
typedef long long ll;
short int tree[107][107][30]={0};
short int init[107][107];
short int give_num(char ch)
{
  if(ch=='N')
    return 0;
  else if(ch=='E')
    return 1;
  else if(ch=='S')
    return 2;
  else if(ch=='W')
    return 3;
}
void updatey(short int x,short int y,short int val,int alpha)
{
  while(y<106)
    {
      tree[x][y][alpha]+=val;
      y+=y&-y;
    }
}

void update(short int x,short int y,short int val,int alpha)
{
  while(x<106)
    {
      updatey(x,y,val,alpha);
      x+=x&-x;
    }
}
short int csumy(short int x,short int y,int alpha)
{
  short int sum=0;
  while(y>0)
    {
      sum+=tree[x][y][alpha];
      y-=y&-y;
    }
  return sum;
}

short int csum(short int x,short int y,int alpa)
{
  short int sum=0;
  while(x>0)
    {
      sum+=csumy(x,y,alpha);
      x-=x&-x;
    }
  return sum;
}
char charac(short int x)
{
  x=x%4;
  if(x<0)
    x+=4;
  if(x==0)
    return 'N';
  else if(x==1)
    return 'E';
  else if(x==2)
    return 'S';
  else return 'W';
}
int main()
{
  short int c,i,j,k,m,n,x1,x2,y1,y2,d;
  char str[1007],ch;
  scanf("%hd",&n);
  for(i=0;i<n;i++)
    {
      for(j=0;
 while(c--)
    {
      scanf("%c",&ch);
      scanf("%c",&ch);
      if(ch=='C')
	{
	  scanf("%hd%hd%hd%hd%hd",&x1,&y1,&x2,&y2,&d);
	  if(d==0)
	    d=1;
	  else d=-1;
	  update(x1,y1,d);
	  update(x2+1,y1,-d);
	  update(x1,y2+1,-d);
	  update(x2+1,y2+1,d);
	}
      else if(ch=='D')
	{
	  scanf("%hd%hd",&x1,&y1);
	  printf("%c\n",charac(csum(x1,y1)+init[x1][y1]));    
	}

    }
  return 0;
}

