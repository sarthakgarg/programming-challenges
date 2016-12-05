#include<stdio.h>
#include<iostream>
#include<string>
typedef long long ll;
using namespace std ;
int main()
{
  ll flag,i,j,n,k,b,t,num,count,ans,x[100],v[100],test;
  scanf("%lld",&test);
  for(j=1;j<=test;j++)
    {
      num=0;
      count=0;
      flag=0;
      ans=0;
      scanf("%lld%lld%lld%lld",&n,&k,&b,&t);
      for(i=0;i<n;i++)
	scanf("%lld",&x[i]);
      for(i=0;i<n;i++)
	scanf("%lld",&v[i]);
      i--;
      while(num<k)
	{
	  if(i==-1)
	    {
	      flag=1;
	      break;
	    }
	  if(x[i]+v[i]*t>=b)
	    {
	      num++;
	      ans+=count;
	    }
	  else 
	    count++;
	  i--;
	}
      if(flag==1)
	printf("Case #%lld: IMPOSSIBLE\n",j);
      else 
	printf("Case #%lld: %lld\n",j,ans);
    }
  return 0;
}










 
