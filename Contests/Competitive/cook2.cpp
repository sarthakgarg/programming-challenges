#include<stdio.h>
#include"iostream"
using namespace std;
typedef double du;
int main()
{
  du sum,p1,p2;
  int t,n,m,i,j,k;
  scanf("%d",&t);
  while(t--)
    {
            sum=0;
      scanf("%d%d",&n,&m);
      /* du prob[1007][1007];
      prob[0][0]=1;
      for(i=1;i<m;i++)
	{
	  prob[0][i]=prob[0][i-1]/(du)2;
	  if(n==1)
	    prob[0][i]*=2;
	}
      for(i=1;i<n;i++)
	{
	  prob[i][0]=prob[i-1][0]/(du)2;
	  if(m==1)
	    prob[i][0]*=2;
	}
      for(i=1;i<m;i++)
	prob[n-1][i]=prob[n-1][i-1];
      for(i=1;i<n;i++)
	prob[i][n-1]=prob[i-1][n-1];
      for(i=1;i<n;i++)
	{
	  for(j=1;j<m;j++)
	    {
	      if(i==n-1)
		p1=prob[i][j-1];
	      else p1=prob[i][j-1]/2;
	      if(j==m-1)
		p2=prob[i-1][j];
	      else p2=prob[i-1][j]/2;
	      prob[i][j]=p1+p2;
	    }
	}
      for(i=0;i<n;i++)
	{
	  for(j=0;j<m;j++)
	    {
	      sum+=prob[i][j];
	    }
	}*/
      printf("%lf\n",(du)(n+m-1));
    }
return 0;
}

