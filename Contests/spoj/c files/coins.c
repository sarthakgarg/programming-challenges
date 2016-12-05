#include<stdio.h>
#include<stdlib.h>
int arr[10000]={0};
inline unsigned int find(int n)
{
	if(n<10000)
		return arr[n] ;
	else return (find(n>>1)+find(n/3)+find(n>>2));       //3 recursive calls , can be reduced to 2
}		
inline int max(int a,int b)
{
	if(a>b)
		return a;
	else return b;
}		
int main()
{
	int i,n;
	arr[1] = 1;
	arr[2] = 2 ;
	arr[3] = 3;
	for(i=4;i<10000;i++)
		arr[i] = max(i , arr[i>>1] + arr[i/3] +arr[i>>2]) ;
	while(scanf("%d",&n)!=EOF)
		printf("%u\n",find(n));	
	return 0;
}		


