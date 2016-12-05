#include<stdio.h>
#include"iostream"
using namespace std;
typedef long long ll;
ll i,j,k,temp[4][4],init[4][4],init1[4][4];
void result(ll n)
{
  if(n==1)
    {
      for(i=0;i<4;i++)
	for(j=0;j<4;j++)
	  init[i][j]=init1[i][j];
    return ;
    }
  result(n/2);
  for(i=0;i<4;i++)
    for(j=0;j<4;j++)
      {
	temp[i][j]=0;
	for(k=0;k<4;k++)
	  temp[i][j]+=(init[i][k]*init[k][j])%1000000007;
	temp[i][j]=temp[i][j]%1000000007;
      }
  if(n%2==1)
    {
      for(i=0;i<4;i++)
	for(j=0;j<4;j++)
	  {
	    init[i][j]=0;
	    for(k=0;k<4;k++)
	      init[i][j]+=(temp[i][k]*init1[k][j])%1000000007;
	    init[i][j]=init[i][j]%1000000007;
	  }
    }
  else 
    {
      for(i=0;i<4;i++)
	for(j=0;j<4;j++)
	  init[i][j]=temp[i][j];
    }
  return ;
}
int main()
{
  ll n,res[4][4];
  for(i=0;i<4;i++)
    {
      for(j=0;j<4;j++)
	{
	  if(i==j)
	    init1[i][i]=0;
	  else init1[i][j]=1;
	}
    }
  scanf("%lld",&n);
  result(n);
  printf("%lld\n",init[3][3]);
  return 0;
}
