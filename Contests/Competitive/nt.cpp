#include<stdio.h>
#include"iostream"
using namespace std;
typedef long long ll;
int main()
{
  ll ans,temp,k,num[1006],lis[100009]={0},i,j,t,n;
  scanf("%lld",&t);
  while(t--)
    {
      j=0;
      ans=0;
      int sum[100009]={0};
	sum[0]=1;
	lis[0]=0;
	j++;
      scanf("%lld",&n);
      for(i=0;i<n;i++)
	{
	  scanf("%lld",&num[i]);
	  temp=j;
	  for(k=0;k<temp;k++)
	    {
	      if(sum[lis[k]+num[i]]==0)
		{
		  sum[lis[k]+num[i]]=1;
		  lis[j]=lis[k]+num[i];
		  j++;
		}
	    }
	}
      for(i=0;i<j;i++)
	ans+=lis[i];
      printf("%lld\n",ans);
    }
  return 0;
}
  
