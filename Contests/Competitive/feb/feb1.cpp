#include<stdio.h>
#include"iostream"
using namespace std;
typedef long long ll;
ll odd,even,oddplus,oddminus,evenplus,evenminus,t,i,j;
char ch ,str[150000];
int main()
{
  scanf("%lld",&t);
  while(t--)
    {
      scanf("%s",str);
      oddplus=0;
      oddminus=0;
      evenplus=0;
      evenminus=0;
      odd=0;
      even=0;
      for(i=0;str[i]!='\0';i++)
	{
	  if(i%2==0)
	    {
	      even++;
	      if(str[i]=='+')
		evenplus++;
	      else evenminus++;
	    }
	  else 
	    {
	      odd++;
	      if(str[i]=='+')
		oddplus++;
	      else oddminus++;
	    }
	}
      if(oddminus+evenplus<=oddplus+evenminus)
	printf("%lld\n",oddminus+evenplus);
      else printf("%lld\n",oddplus+evenminus);
    }
  return 0;
}
