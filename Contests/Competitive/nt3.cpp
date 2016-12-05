#include<stdio.h>
#include"iostream"
#include<vector>
#include<algorithm>
using namespace std;
typedef long long ll;
vector<ll> list[50];
ll  i,j,k,t,a,b,lcount[53]={0},sum,temp,order[53]={0};
ll p[100007]={0};
vector<ll> dig[10];
vector<ll>::iterator it1,it2,it;
int main()
{
  for(i=2;i*i<100007;i++)
    {
      if(p[i]==0)
	{
	  for(j=2*i;j<100007;j+=i)
	    p[j]=1;
	}
    }
  list[0].push_back(1);
  lcount[0]++;
  for(i=2;i<100007;i++)
    {
      if(p[i]==0)
	{
	  for(k=0;k<50;k++)
	    order[k]=lcount[k];
	  for(k=0;k<50;k++)
	    {
	      for(j=0;j<order[k];j++)
		{
		  if((ll)(i*list[k][j])>100007)
		    break;
		  list[k+1].push_back(i*list[k][j]);
		  lcount[k+1]++;
		}
	    }
    	}
    }
  sum=0;
  for(k=0;k<50;k++)
    {
      printf("%lld\n",lcount[k]);
      sum+=lcount[k];
    }
  printf("%lld\n",sum);
  for(k=0;k<50;k++)
    {
      for(i=0;i<lcount[k];i++)
	{
	  temp=list[k][i];
	  ll trick[10]={0};
	  while(temp!=0)
	    {
	      if(trick[temp%10]==0)
		{
		  trick[temp%10]=1;
		  dig[temp%10].push_back(list[k][i]);
		}
	      temp/=10;
	    }
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
