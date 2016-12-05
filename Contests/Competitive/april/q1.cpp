#include<stdio.h>
#include"iostream"
using namespace std;
typedef long long ll;
int main()
{
  ll ar[100007],t,i,ct,n;
  scanf("%lld",&t);
  while(t--)
    {
      ll mark[100007]={0};
      ct=0;
      scanf("%lld",&n);
      for(i=0;i<n;i++)
	scanf("%lld",&ar[i]);
      for(i=0;i<n-1;i++)
	if(ar[i]!=ar[i+1])
	  {
	    mark[i]=1;
	    mark[i+1]=1;
	  }
      for(i=0;i<n;i++)
	if(mark[i]==1)
	  ct++;
      printf("%lld\n",ct);
    }
  return 0;
}
