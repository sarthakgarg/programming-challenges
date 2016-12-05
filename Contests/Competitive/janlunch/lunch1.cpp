#include<stdio.h>
#include"iostream"
#include<string.h>
using namespace std;
typedef long long ll;
int main()
{
  ll t,i,j,len,flag;
  char ch,str[100];
  scanf("%lld",&t);
  while(t--)
    {
      flag=1;
      ll count[27]={0};
      scanf("%s",str);
      len=strlen(str);
      for(i=0;i<len;i++)
	  count[str[i]-'a']++;
      for(i=0;i<='z'-'a';i++)
	{
	  if(count[i]==len-count[i])
	    {
	      printf("YES\n");
	      flag=0;
	      break;
	    }
	}
	  if(flag==0)
	    continue;
	  printf("NO\n");
    }
  return 0;
}
