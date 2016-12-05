#include<stdio.h>
#include"iostream"
using namespace std;
typedef long long ll;
ll arr[1000009],n,i,j,k,l,t;
int main()
{
  for(i=2;i<1000009;i++)
    arr[i]=1;
  for(i=2;i*i<1000009;i++)
    {
      for(j=2*i;j<1000009;j+=i)
	{
	  arr[j]+=i;
	  if((j/i)*(j/i)>=1000009)
	    arr[j]+=j/i;
	}
    }
  arr[0]=0;
  arr[1]=0;
  for(i=2;i<1000009;i++)
    arr[i]+=arr[i-1];
  scanf("%lld",&t);
  while(t--)
    {
      scanf("%lld",&n);
      printf("%lld\n",arr[n]);
    }
  return 0;
}
