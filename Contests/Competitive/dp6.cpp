#include<stdio.h>
#include"iostream"
#include<string.h>
short int k,ans[1050][1050],ct[1050][1050];
inline short int max(short int a,short int b)
{
  if (a>b)
    return a; 
  else return  b;
}
inline short int an(short int a,short int b)
{
  if(a>=0&&b>=0)
    return ans[a][b];
  else return 0;
}
inline short int cn(short int a,short int b)
{
  if(a>=0&&b>=0)
    return ct[a][b];
  else return 0;
}
using namespace std ;
char str1[1050],str2[1050];
inline void lcs(short int i,short int j)               //using bottom up dp !!
{
  short int count=0;
  if(str1[i]==str2[j])
    count=1+cn(i-1,j-1);
  else 
    count=0;
  ct[i][j]=count;
  if(count>=k)
    ans[i][j]=k+(an(i-k,j-k));
  else 
    ans[i][j]=max(an(i-1,j),an(i,j-1));
  return; 
}
int main()
{
  short int n,i,j;
  char ch;
  while(1)
    {
      scanf("%hd",&k);
      if(k==0)
	break;
      scanf("%c",&ch);
      scanf("%s",str1);
      scanf("%s",str2);
      i=0;
      for(i=0;str1[i]!='\0';i++)
	for(j=0;str2[j]!='\0';j++)
	  lcs(i,j);
      printf("%hd\n",ans[i-1][j-1]);
    }
  return 0;
}
