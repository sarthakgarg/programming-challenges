#include<cstdio>
#include<stdlib.h>
#include<iostream>
using namespace std;
#define gc getchar_unlocked

 int getn() 
 {
    register int n=0;
    register int ch=gc();
    while( ch < '0' || ch > '9' ){ch=gc();}

    while(  ch >= '0' && ch <= '9' )
            n = (n<<3)+(n<<1) + ch-'0', ch=gc();
    
    return n ;
  }   

 int max(int i,int j)
{
	if(i>j)
		return i;
	else return j;	
}	
int main()
{
	register int n,j,age;
	int value[2000] ,opt[2001][2001];
	register int i;
	n = getn();
	for(i=0;i<n;i++)
		value[i]=getn();
	for(i=0;i<n;i++)
		opt[i][i] = n*value[i];
	age=n-1;
	for(j=1;j<n;j++)
	{
		for(i=j;i<n;i++)
			opt[i][i-j] = max(opt[i-1][i-j] + value[i]*age , opt[i][i-j+1] + value[i-j]*age);
		age --;
	}		
	printf("%d\n",opt[n-1][0]);
	return 0;
}					
		   
	
