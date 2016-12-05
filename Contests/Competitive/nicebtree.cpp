#include<stdio.h>
#include"iostream"
#include<string.h>
using namespace std;
char str[10007];
int max(int a ,int b)
{
  if(a<b)
    return b;
  else return a;
}
int length(int l,int r)
{
  if(l==r)
    return 0;
  int l1,r1,l2,r2,lcount,ncount,i;
  lcount=0;
  ncount=0;
  l1=l+1;
  for(i=l1;;i++)
    {
      if(str[i]=='l')
	lcount++;
      else ncount++;
      if(lcount==ncount+1)
	break;
    }
  r1=i;
  l2=i+1;
  r2=r;
  return 1+max(length(l1,r1),length(l2,r2));
}

int main()
{
  int t,count,i;
  scanf("%d",&t);
  while(t--)
    {
      scanf("%s",str);
      printf("%d\n",length(0,strlen(str)-1));
    }
  return 0;
}
