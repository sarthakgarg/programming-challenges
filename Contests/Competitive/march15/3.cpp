#include<stdio.h>
#include"iostream"
using namespace std;
typedef long long ll;
ll mo(ll a,ll b)
{
  if(a>b)
    return a-b;
  else 
    return b-a;
}
ll power(ll base ,ll exp)
{
  ll x=1;
  while(exp--)
    {
      x*=base;
    }
  return x;
}
int main()
{
  ll i,t,odd[100005],even[100005],p,b,g,min,oddct,evenct,min1;
  char str[100005],ch;
  scanf("%lld",&t);
  while(t--)
    {
      scanf("%lld",&p);
      if(p==2)
	p=1;
      scanf("%s",str);
      b=0;
      g=0;
      for(i=0;str[i]!='\0';i++)
	{
	  if(str[i]=='B')
	    b++;
	  else g++;
	}
      if(mo(b,g)>1)
	{
	  printf("-1\n");
	  continue;
	}
      if(b==g)
	{
	  oddct=0;
	  evenct=0;
	  for(i=0;str[i]!='\0';i++)
	    {
	      if(i%2==0&&str[i]=='B')
		{
		  even[evenct]=i;
		  evenct++;
		}
	      if(i%2==1&&str[i]=='G')
		{
		  odd[oddct]=i;
		  oddct++;
		}
	    }
	  min=0;
	  for(i=0;i<oddct;i++)
	    min+=power(mo(odd[i],even[i]),p);
	  oddct=0;
	  evenct=0;
	  for(i=0;str[i]!='\0';i++)
	    {
	      if(i%2==0&&str[i]=='G')
		{
		  even[evenct]=i;
		  evenct++;
		}
	      if(i%2==1&&str[i]=='B')
		{
		  odd[oddct]=i;
		  oddct++;
		}
	    }
	  //	  printf("%lld%lld\n",min,min1);
	  min1=0;
	  for(i=0;i<oddct;i++)
	    min1+=power(mo(odd[i],even[i]),p);
	  //	  printf("%lld%lld\n",min,min1);
	  if(min1<min)
	    min=min1;
	  //	  printf("%lld\n",min);
	}
      else if(b==g+1)
	{
	  oddct=0;
	  evenct=0;
	  for(i=0;str[i]!='\0';i++)
	    {
	      if(i%2==0&&str[i]=='G')
		{
		  even[evenct]=i;
		  evenct++;
		}
	      if(i%2==1&&str[i]=='B')
		{
		  odd[oddct]=i;
		  oddct++;
		}
	    }
	  min=0;
	  for(i=0;i<oddct;i++)
	    min+=power(mo(odd[i],even[i]),p);
	}
      else 
	{
	  oddct=0;
	  evenct=0;
	  for(i=0;str[i]!='\0';i++)
	    {
	      if(i%2==0&&str[i]=='B')
		{
		  even[evenct]=i;
		  evenct++;
		}
	      if(i%2==1&&str[i]=='G')
		{
		  odd[oddct]=i;
		  oddct++;
		}
	    }
	  min=0;
	  for(i=0;i<oddct;i++)
	    min+=power(mo(odd[i],even[i]),p);
	}
      printf("%lld\n",min);
    }
  return 0;
}
