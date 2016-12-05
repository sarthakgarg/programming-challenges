#include<stdio.h>
#include"iostream"
using namespace std;
typedef long long ll;
ll inv[1000009]={0};
ll combine(ll n,ll r)
{
  ll x;
  int i;
  if(n<r)
    return 0;
  if(r==1)
    return n;
  if(n==r)
    return 1;
  if(r==0)
    return 1;
  x=n;
  for(i=1;i<r;i++)
    {
      x=(x*(n-i))%1000003;
      x=(x*inv[i+1])%1000003;
    }
  return x;
}
void modinv(int a,int n,int arr[2])
{
  int temp[2];
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
  int i,k,arr[2],t,r,l,n,n1,k1;
  ll ans;
  inv[1]=1;
  for(i=2;i<1000003;i++)
    {
      modinv(i,1000003,arr);
      if(arr[0]<0)
	arr[0]+=1000003;
      if(arr[0]==0)
	printf("%d\n",i);
      inv[i]=arr[0];
    }
  scanf("%d",&t);
  while(t--)
    {
      ans=1;
      scanf("%d%d%d",&n,&l,&r);
      n=r-l+1+n;
      k=r-l+1;
      n1=n%1000003;
      k1=k%1000003;
      ans=combine(n1,k1);
      n1=n/1000003;
      k1=k/1000003;
       ans=(ans*combine(n1,k1))%1000003;
      ans--;
      if(ans<0)
	ans+=1000003;
      printf("%lld\n",ans);
    }
  return 0;
}
