#include"stdio.h"
#include"iostream"
using namespace std;
typedef long long ll;
ll matrix[2002][2002]={0};
int main()
{
  ll i,j,n,temp,k;
  for(i=1;i<=2000;i++)
    matrix[1][i]=1;
  for(i=1;i<2000;i++)
    {
      for(j=1;j<=2000;j++)
	{
	  matrix[i][j]=matrix[i][j]%1000000007;
	  for(k=1;j*k<=2000;k++)
	    {
	      matrix[i+1][j*k]+=matrix[i][j];
	    }
	}
    }
  scanf("%lld",&n);
  scanf("%lld",&k);
  j=0;
  for(i=1;i<=n;i++)
    j+=matrix[k][i];
  j=j%1000000007;
  printf("%lld\n",j);
  return 0;
}
