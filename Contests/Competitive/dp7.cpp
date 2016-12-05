#include<stdio.h>
#include"iostream"
#include<string.h>
int k,ans[1050][1050];
int max(int a,int b)
{
  if (a>b)
    return a;
  else return  b;
}
int an(int a,int b)
{
  if(a>=0&&b>=0)
    return ans[a][b];
  else return 0;
}
using namespace std ;
char str1[1050],str2[1050];
void lcs(int i,int j) 
{
  int count=0;
  while(i-count>=0&&j-count>=0&&str1[i-count]==str2[j-count]&&count<k)
    count++;
  if(count==k)
    ans[i][j]=count+(an(i-count,j-count));
  else
    ans[i][j]=max(an(i-1,j),an(i,j-1));
  return;
}
int main()
{
  int n,i,j;
  char ch;
  while(scanf("%d",&k))
    {
      scanf("%c",&ch);
      scanf("%s",str1);
      scanf("%s",str2);
      i=0;
      for(i=0;i<strlen(str1);i++)
        for(j=0;j<strlen(str2);j++)
          lcs(i,j);
      printf("%d\n",ans[i-1][j-1]);
    }
  return 0;
}
