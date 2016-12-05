#include<stdio.h>
#include"iostream"
using namespace std;
typedef long long ll;
ll p(ll a,ll b)
{
  ll temp=1;
  while(b>0)
    {
      temp*=a;
      b--;
    }
  return temp;
}
ll divide(ll node)
{
  ll count=0;
  while(node!=0)
    {
      node/=2;
      count++;
    }
  return count-1;
}
int main()
{
  ll left,right,status,node,n,h,i,height,num,count;
  scanf("%I64d%I64d",&h,&n);
  n+=p(2,h)-1;
  node=1;
  status=0;
  count=0;
  while(node!=n)
    {
      //   printf("%lld %lld\n",node,count);
      height=h-divide(node);
      left=node*p(2,height);
      right=left+p(2,height)-1;
      if(n<left||n>right)
	{
	  count+=(p(2,height+1)-1);
	  if(node%2==1)
	    {
	      node/=2;
	      status=0;
	    }
	  else 
	    {
	      node/=2;
	      status=1;
	    }
	  count--;
	}
      else 
	{
	  count++;
	  if(status==0)
	    node*=2;
	  else 
	    node=2*node+1;
	  if(status==0)
	    status=1;
	  else status=0;
	}
    }
  printf("%I64d\n",count);
  return 0;
}
