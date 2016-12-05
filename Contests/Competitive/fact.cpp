#include<stdio.h>
#include"iostream"
using namespace std;
typedef long long ll;
void modinv(ll a,ll n,ll arr[2])
{
  ll temp[2];
  if(a==0)
    {
      arr[0]=0;
      arr[1]=1;
      return ;
    }
  modinv(n%a,a,temp);
  arr[0]=(temp[1]-(n/a)*temp[0]);
  arr[1]=temp[0];
  return ;
}
int main()
{
  ll temp, t,i,j,n,p,prev,arr[2];
  scanf("%lld",&t);
  while(t--)
    {
      scanf("%lld%lld",&n,&p);
      if(n>=p)
	{
	  printf("0\n");
	  continue;
	}
      prev=-1;
      temp=p-1;
      while(temp!=n)
	{
	  modinv(temp,p,arr);
	  prev=(prev*arr[0])%p;
	  temp--;
	}
      if(prev<0)
	prev+=p;
      printf("%lld\n",prev);
    }
  return 0;
}

      

