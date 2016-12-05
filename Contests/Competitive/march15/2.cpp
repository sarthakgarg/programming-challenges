#include<stdio.h>
#include"iostream"
#include<math.h>
using namespace std;
typedef long long ll;
int main()
{
  ll t,s,c,i,j,k;
  scanf("%lld",&t);
  while(t--)
    {
      scanf("%lld%lld",&s,&c);
      ll sin[103]={0},cos[60]={0};
      if(s!=0)
	{
	  i=pow(2,s-1);
	  for(j=1;j<s;j++)
	    {
	      sin[j]=i;
	      i/=2;
	    }
	  k=min(s,c+1);
	  for(j=1;j<k;j++)
	    {
	      sin[s-j+1]=sin[s-j];
	      sin[s-j]=0;
	    }
	  sin[s]+=3;
	  for(j=s;j<=c;j++)
	    sin[1]+=pow(2,j);
	}
      else if(c!=0) 
	  sin[1]=2*(pow(2,c)-1);
      else sin[1]=0;
      scanf("%lld",&k);
      i=0;
      for(j=k;j<=100;j++)
	i+=sin[j];
      printf("%lld\n",i);
    }
  return 0;
}
