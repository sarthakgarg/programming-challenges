#include<stdio.h>
#include"iostream"
using namespace std;
typedef long long ll;
ll ch[100005]={0};
ll chev[100005]={0};
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
ll modexp(ll base,ll power, ll p)
{
  ll x;
  if(power==0)
    return 1;
  x=modexp(base,power/2,p);
  x=(x*x)%p;
  if(power%2==1)
    x=(x*base)%p;
  return x;
}
ll seperate(ll &i)
{
  ll count=0;
  while(i%2==0)
    {
      count++;
      i/=2;
    }
  return count;
}
ll separate41(ll &i)
{
  ll count=0;
  while(i%41==0)
    {
      count++;
      i/=41;
    }
  return count;
}
int main()
{
  ll flag=0,crt1,crt2,arr[2],pow,t,a,b,n,r1,p=500000002,i,temp1,temp,pow2,pow41,temp2;
  ch[0]=1;
  chev[0]=1;
  pow2=0;
  pow41=0;
  for(i=1;i<=100000;i++)
    {
      temp=i;
      temp2=2*i-1;
      pow2=pow2+1-seperate(temp);
      pow41=pow41-separate41(temp)+separate41(temp2);
      ch[i]=(temp2*ch[i-1])%(p);
      modinv(temp,p,arr);
      if(arr[0]<0)
	arr[0]+=p;
      ch[i]=(ch[i]*arr[0])%(p);
      chev[i]=(ch[i]*modexp(2,pow2,p))%(p);
      chev[i]=(chev[i]*modexp(41,pow41,p))%p;
    }
  scanf("%lld",&t);
  while(t--)
    {
      scanf("%lld%lld%lld",&a,&b,&n);
      if(a!=0&&b!=0)
	{
	  crt2=modexp(b,chev[n],p+1);
	  crt1=b%2;
	  modinv(2,p+1,arr);
	  if(arr[0]<0)
	    arr[0]+=p+1;
	  crt2=(crt2*2*arr[0])%(2*(p+1));
	  crt1=(crt1*(p+1))%(2*(p+1));
	  crt1=(crt1+crt2)%(2*(p+1));
	  pow=modexp(a,crt1,2*(p+1)+1);
	  printf("%lld\n",pow);
	}
      else if(a==0&&b==0)
	printf("1\n");
      else if(a!=0&&b==0)
	printf("1\n");
      else if(a==0&&b!=0)
	printf("0\n");
    }    
  return 0;
}
