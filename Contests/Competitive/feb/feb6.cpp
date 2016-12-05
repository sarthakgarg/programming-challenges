#include<stdio.h>
#include"iostream"
#include<string.h>
using namespace std;
typedef long long ll;
inline int m(char ch)
{
    if(ch=='c')
        return 0;
    else if(ch=='h')
        return 1;
    else if(ch=='e')
        return 2;
    else return 3;
}
int freq[4][1000009];
ll prod[4][4][1000009];
char ch,str[1000007];
int main()
{
    int i,j,k,n,l,r;
    char chl,chr;
    scanf("%s",str);
    for (i=0; str[i]!='\0'; i++)
    {
      for(j=0;j<4;j++)
	{
	  if(j==m(str[i]))
	    freq[j][i+1]=freq[j][i]+1;
	  else 
	    freq[j][i+1]=freq[j][i];
	}
        for(j=0;j<4;j++)
	  for(k=0;k<4;k++)
	    {
	      if(j!=k)
		{
		  if(k==m(str[i]))
		    prod[j][k][i+1]=prod[j][k][i]+freq[j][i+1];
		  else prod[j][k][i+1]=prod[j][k][i];
		}
	    }
    }
    scanf("%d",&n);
    for(i=0;i<n;i++)
    {
        scanf("%c",&ch);
        scanf("%c",&chl);
        scanf("%c",&ch);
        scanf("%c",&chr);
        scanf("%d%d",&l,&r);
	//	printf("%c %c\n",chl,chr);
        printf("%lld\n",prod[m(chl)][m(chr)][r]-prod[m(chl)][m(chr)][l-1]-(1LL)*freq[m(chl)][l-1]*(freq[m(chr)][r]-freq[m(chr)][l-1]));
    }
    return 0;
}
