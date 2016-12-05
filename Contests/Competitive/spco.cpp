#include<stdio.h>
#include"iostream"
using namespace std;
typedef unsigned long long ull;
ull p[67]={0};
ull gc(ull a,ull b)
{
  if(a==0)
    return b;
  else return gc(b%a,a);
}
ull gcd(ull a,ull b)
{
  if(a<b)
    return gc(a,b);
  else return gc(b,a);
}
ull ncr[70][70]={0};
void choose(ull n,ull r)
{
  ull x,a,b,c;
  if(r==0)
    {
      ncr[n][r]=1;
      return;
    }
  x=gcd(n-r+1,r);
  a=(n-r+1)/x;
  b=r/x;
  ncr[n][r]=ncr[n][r-1]/b;
  ncr[n][r]*=a;
  return ;
}
ull ct(ull n)
{
  if(n==0||n==1||n==2)
    return 0;
  ull b=__builtin_popcount(n),sum=0,i,k=-1,set=0;
  printf("b=%llu , n=%llu\n",b,n);
  if(p[b]==0)
    sum++;
  while(n)
    {
      k++;
      if(n%2==1)
	{
	  set++;
	  for(i=0;i<=k;i++)
	    {
	      if(p[b-set+i]==0)
		{
		  sum+=ncr[k][i];
		    printf("choose(%lld ,%lld,%lld)=%lld\n",k,i,b-set+i,ncr[k][i]);
		}
	    }
	}
      n/=2;
    }
  return sum;
}
int main()
{
  ull i,j,t,a,b;
  p[0]=1;
  p[1]=1;
  for(i=2;i*i<70;i++)
    {
      if(p[i]==0)
	for(j=2*i;j<70;j+=i)
	  p[j]=1;
    }
  for(i=0;i<70;i++)
    if(p[i]==0)
      printf("%llu ,",i);
  printf("\n");
  for(i=0;i<70;i++)
    {
      for(j=0;j<=i;j++)
	choose(i,j);
    }
  scanf("%llu",&t);
  while(t--)
    {
      scanf("%llu%llu",&a,&b);
      printf("%llu\n",ct(b)-ct(a-1));
    }
  return 0;
}
