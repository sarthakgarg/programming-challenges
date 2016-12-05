
#include<stdio.h>
#include"iostream"
using namespace std;
int main()
{
  int i,j,k;
  printf("10\n");
  for(i=0;i<10;i++)
    {
      printf("50 49 20000\n");
      for(j=1;j<50;j++)
	printf("%d %d\n",j,j+1);
      for(j=1;j<=20000;j++)
	printf("%d\n",j%50+1);
    }
  return 0;
}
