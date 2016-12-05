#include<stdio.h>
#include"iostream"
using namespace std;
int p[10009]={0};
int main()
{
  int temp,i,j,k,u,n,ct,p1[10009],e1[10009];
  for(i=2;i*i<10009;i++)
    {
      if(p[i]==0)
	for(j=2*i;j<10009;j+=i)
	  p[j]=1;
    }
  while(scanf("%d",&n)!=EOF)
    {
      k=0;
      for(i=2;i<=n;i++)
	{
	  ct=0;
	  temp=1;
	  if(p[i]!=0)
	    continue;
	  temp*=i;
	  while(n/temp!=0)
	    {
	      ct+=n/temp;
	      temp*=i;
	    }
	  p1[k]=i;
	  e1[k]=ct;
	  k++;
	}
      printf("%d^%d",p1[0],e1[0]);
      for(i=1;i<k;i++)
	  printf(" * %d^%d",p1[i],e1[i]);
      printf("\n");
    }
  return 0;
}
