#include<stdio.h>
int max(int a,int b)
{
	if(a>b)
	return a;
	else return b;
}


int preproc(int seg[],int arr[] , int beg , int end ,int node)
{
	int temp1,temp2,mid ;
	mid = (beg+end)/2 ;
	if(beg ==end)
		seg[node] = arr[beg];
	else 	
	{
		temp1 = preproc(seg , arr , beg , mid , node*2);
		temp2 = preproc(seg , arr , mid+1 , end , 2*node+1);
		seg[node] =max(temp1,temp2);
	}
	return seg[node] ;
}


		  
int merge(int seg[] ,int arr[] , int x,int y,int beg,int end ,int node)
{
	int t1,t2, mid = (beg+end)/2 ;
	
	if(y<beg||x>end)
		return -100000;
	else if(x>=beg && y<=end	)
		return seg[node] ;
	else 
	{
		t1 = merge(seg , arr , x, y , beg , mid , 2*node);
		t2 = merge(seg , arr , x, y , mid+1 , end , 2*node+1) ; 
		return max(t1 , t2);
	}
}


int update(int seg[] ,int arr[] ,int idx ,int val, int beg ,int end ,int node)
{
	int mid = (beg+end)/2,temp ; 
	if(beg == idx && end==idx)
	{
		seg[node] = val ;
		return seg[node] ;
	}
	else if(idx<=mid)
	{
		temp = update(seg , arr , idx , val , beg , mid , 2*node);
		seg[node] = max(seg[node] , temp );
		return seg[node] ;
	}
	else 
	{
		temp = update(seg,arr,idx,val,mid+1,end,2*node+1);
		seg[node] = max(seg[node],temp);
		return seg[node];
	}
}
			
int main()
{
	int seg[200000]={0} ,min, n, x , y ,idx,t,i,val,arr[50001] ;
	char ch ;
	scanf("%d",&n);
	 for(i=0;i<n;i++)
	 	scanf("%d",&arr[i]);
	 scanf("%d",&t);
	 scanf("%c",&ch);
	 while(t--)
	 {
	 	min = preproc(seg ,arr, 0 , n-1 , 1 );
	 	printf("check\n");	
	 	scanf("%c",&ch);
	 	switch(ch)
	 	{
	 		case '1':
	 					scanf("%d",&x);
	 					scanf("%d",&y);
	 					scanf("%c",&ch);
	 					printf("%d\n",merge(seg,arr,x-1,y-1,0,n-1,1));
	 					break;
	 		case '0' :	scanf("%d",&idx);
	 					scanf("%d",&val);
	 					scanf("%c",&ch);
	 					min = update(seg ,arr , idx-1 , val , 0 , n-1 , 1);
	 					break;
	 	}
	 }
	 return 0;
} 					
	 					
