#include<stdio.h>
int cost[102],fun[102];
typedef struct a{
	int maxfun;
	int maxcost;
	}pair;
int min(int a,int b)
{
	if(a<b)
		return a;
	else return b;
}			
int compare(int a,int b)
{
	if(a>b)
		return 1;
	else if(a==b)
		return 0;
	else return -1;	
}		
int getfun(int n,int w,pair opt[102][550])
{
	int dec,a,b;
	if(opt[n][w].maxfun!=0||n==1)
	{
		return opt[n][w].maxfun;
	}	
	if(cost[n]>w)
	{
		opt[n][w].maxfun=getfun(n-1,w,opt);
		opt[n][w].maxcost=opt[n-1][w].maxcost;		
		return opt[n][w].maxfun;
	}	
	a=getfun(n-1,w,opt);
	b=getfun(n-1,w-cost[n],opt)+fun[n];
	dec=compare(a,b);
	switch(dec)
	{
		case 0:	opt[n][w].maxfun=a;
				opt[n][w].maxcost=min(opt[n-1][w].maxcost,opt[n-1][w-cost[n]].maxcost+cost[n]);
				return a;
		case 1: opt[n][w].maxfun=a;
				opt[n][w].maxcost=opt[n-1][w].maxcost;
				return a;
		case -1:opt[n][w].maxfun=b;
				opt[n][w].maxcost=opt[n-1][w-cost[n]].maxcost+cost[n];
				return b;
	}					

}	
			
int main()
{
	int t,i,j,k,n,budg,pos,exp;
	while(1)
	{
		pair opt[102][550]={0,0};
		scanf("%d",&budg);
		scanf("%d",&n);
		if(budg==0&&n==0)
			return 0;	
		for(i=1;i<=n;i++)
		{
			scanf("%d",&cost[i]);
			scanf("%d",&fun[i]);
		}
		for(i=0;i<cost[1];i++)
		{
			opt[1][i].maxfun=0;
			opt[1][i].maxcost=0;
		}  	
		for(i=cost[1];i<=budg;i++)
		{
			opt[1][i].maxfun=fun[1];
			if(fun[1]!=0)
				opt[1][i].maxcost=cost[1];
		}	
		t=getfun(n,budg,opt);
		printf("%d %d\n",opt[n][budg].maxcost,opt[n][budg].maxfun);
	}
	return 0;
}								
