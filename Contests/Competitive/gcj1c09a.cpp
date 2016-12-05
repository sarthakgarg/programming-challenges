#include<stdio.h>
#include"iostream"
#include<string>
using namespace std;
typedef long long ll;
int main()
{
  ll i,j,t,arr[150]={0},mult,count,num,ans;
  char place[100];
  char s[100];
  scanf("%lld",&t);
  for(j=1;j<=t;j++)
    {
      ans=0;
      mult=1;
      for(i=0;i<150;i++)
	arr[i]=-1;
      count=0;
      num=1;
      scanf("%s",s);
      for(i=0;s[i]!='\0';i++)
	{
	  if(arr[s[i]]==-1)
	    {
	      place[i]=num;
	      count++;
	      arr[s[i]]=num;
	      if(num==1)
		num=0;
	      else if(num==0)
		num=2;
	      else num++;
	    }
	  else 
	    place[i]=arr[s[i]];
	}
      if(count==1)
	count=2;
      for(i--;i>=0;i--)
	{
	  ans+=place[i]*mult;
	  mult*=count;
	}
      printf("Case #%lld: %lld\n",j,ans);
    }
      return 0;
}
