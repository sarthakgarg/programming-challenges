#include<stdio.h>
#include"iostream"
#include<math.h>
using namespace std;
typedef long long ll;
int p[1000007]={0};
ll gcd(ll a ,ll b)
{
  if(a==0)
    return b;
  else return gcd(b%a,a);
}
ll modify(ll x,ll y,ll n)
{
  ll temp=y;
  ll temp1=x;
  ll sum=0;
  ll pow=1;
  while(temp!=0)
    {
      sum=(sum+temp1*(temp%2))%n;
      temp/=2;
      temp1=(temp1*2)%n;
    }
  return sum;
}
ll mod(ll base,ll exp,ll m)
{
  ll x;
  if(exp==0)
    return 1;
  x=mod(base,exp/2,m);
  x=modify(x,x,m);
  if(exp%2==1)
    x=modify(x,base,m);
  return x;
}
ll base[10]={2,3,5,7,11,13,17,19,23,31};
ll prime(ll n)
{
  if(n%2==0)
    return 0;
  ll  i,temp,s=0,j,flag;
  //  printf("check");
  ll x ;
  temp=(n-1);
  while(temp%2==0)
    {
      s++;
      temp/=2;
    }
  for(i=0;i<9;i++)
    {
      x=mod(base[i],temp,n);
      flag=0;
      //    printf("%lld %lld \n",i,x);
      if(x==1||x==n-1)
        continue;
      for(j=1;j<s;j++)
        {
          x=modify(x,x,n);
          if(x==n-1)
            {
              flag=1;
              break;
            }
        }
      if(flag==1)
        continue;
      return 0;
    }
  return 1;
}
int main()
{
  ll gc,temp,temp2,i,j,k,u,n,ct,t,e1[1000009],num,flag,fac1,fac2;
  unsigned long long sqr,phi;
  for(i=2;i*i<1000009;i++)
    {
      if(p[i]==0)
	for(j=2*i;j<1000009;j+=i)
	  p[j]=1;
    }
  temp=1LL*67867979*67867979;
  temp2=1LL*67867978*67867979-67867979;
  //   printf("%lld %lld\n",temp,temp2);
  k=0;
  for(i=2;i<1000009;i++)
    {
      if(p[i]==0)
	{
	  e1[k]=i;
	  k++;
	}
    }
  scanf("%lld",&t);
  while(t--)
    {
      scanf("%lld%llu",&num,&phi);
      for(i=0;i<k;i++)
	{
	  //      printf("%lld\n",i);
	  flag=0;
	      while(num%e1[i]==0)
		{
		  num/=e1[i];
		  phi/=e1[i];
		  flag=1;
		  printf("%lld ",e1[i]);
		}
	      if(flag==1)
		{
		  phi*=e1[i];
		  phi/=(e1[i]-1);
		}
	    }
      //  printf("%lld",num);
      if(num==1)
	printf("\n");
      //  printf("done\n");
      if(num>1000000)
	{
	  if(prime(num)==1)
	    {
	      printf("%lld\n",num);
	      continue;
	    }
	  //	  printf("done again");
	  gc=gcd(phi,num);
	  if(gc*gc==num&&prime(gc)==1)
	    {
	      printf("%llu %llu\n",gc,gc);
	      continue;
	    }
	  phi=num-phi+1;
	  sqr=1ULL*phi*phi-4*num;
	  printf("%llu %llu\n",(unsigned long long )((phi-sqrt(sqr))/2),(unsigned long long )((phi+sqrt(sqr))/2));
	}
    }
  return 0;
}
