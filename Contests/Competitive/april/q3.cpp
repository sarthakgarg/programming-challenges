#include<stdio.h>
#include"iostream"
using namespace std;
typedef long long ll;
int main()
{
  ll t,n,i,j,sum,ct;
  char str[1000];
  scanf("%lld",&t);
  while(t--)
    {
      sum=0;
      scanf("%s",str);
      scanf("%lld",&n);
      n*=12;
      n--;
      ct=0;
      for(i=0;str[i]!='\0';i++)
	{
	  if(str[i]=='T')
	    ct+=2;
	  else 
	    ct++;
	}
      j=(n/ct-1);
      sum+=ct*j*(j+1)/2;
      //   printf("%lld\n",sum);
      sum+=(n/ct)*(n-(n/ct)*ct+1);
      //   printf("%lld\n",sum);
      printf("%lld\n",sum);
    }
  return 0;
}
