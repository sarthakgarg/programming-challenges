#include<stdio.h>
#include"iostream"
#include<vector>
#include<algorithm>
using namespace std;
typedef long long ll;
ll list[100007];
ll mat[100007]={0};
ll  i,j,t,a,b,lcount=0,temp;
ll p[400]={0};
vector<ll> dig[10];
vector<ll>::iterator it1,it2,it;
int main()
{
  for(i=2;i*i<400;i++)
    {
      if(p[i]==0)
	{
	  for(j=2*i;j<400;j+=i)
	    p[j]=1;
	}
    }
  //  printf("done1\n");
  for(i=2;i<400;i++)
    if(p[i]==0&&i*i<100007)
      mat[i*i]=1;
  for(i=1;i<100007;i++)
    {
      //    printf("%lld\n",i);
      if(mat[i]==1)
	{
	  for(j=2*i;j<100007;j+=i)
	    mat[j]=2;
	}
    }
  //  printf("done2\n");
  for(i=1;i<100007;i++)
    {
      if(mat[i]==0)
	{
	  list[lcount]=i;
	  lcount++;
	}
    }
  //  printf("%lld\n",lcount);
  // return 0;
  for(i=0;i<lcount;i++)
    {
      temp=list[i];
      ll trick[10]={0};
      while(temp!=0)
	{
	  if(trick[temp%10]==0)
	    {
	      trick[temp%10]=1;
	      dig[temp%10].push_back(list[i]);
	    }
	  temp/=10;
	}
    }
  for(i=0;i<10;i++)
    sort(dig[i].begin(),dig[i].end());
  scanf("%lld",&t);
  while(t--)
    {
      scanf("%lld%lld%lld",&a,&b,&temp);
      /*      it1=lower_bound(dig[temp].begin(),dig[temp].end(),a);
      it2=upper_bound(dig[temp].begin(),dig[temp].end(),b);
      for(it=it1;it!=it2;it++)
      printf("%lld ",*it);
      printf("\n");*/
      printf("%ld\n",upper_bound(dig[temp].begin(),dig[temp].end(),b)-lower_bound(dig[temp].begin(),dig[temp].end(),a));
    }
  return 0;
}

