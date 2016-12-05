#include<stdio.h>
#include<stdlib.h>

#define gc getchar_unlocked
int value[2000] ,opt[2001][2001];
 inline int getn() 
 {
    int n=0;
    int ch=gc();
    while( ch < '0' || ch > '9' ){ch=gc();}

    while(  ch >= '0' && ch <= '9' )
            n = (n<<3)+(n<<1) + ch-'0', ch=gc();
    
    return n ;
  }   

 inline int max(int i,int j)
{
	if(i>j)
		return i;
	else return j;	
}	
int main()
{
	int n,j,age;

 int i;
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
		   
	
