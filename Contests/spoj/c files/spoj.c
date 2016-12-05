#include<stdio.h>
typedef struct segn1{
				int i;
				int j;
				int val;
			}segn;	
/*void showtree(segn seg[],int n)
{
	int i;
		printf("\ntree ->"); 	
	for(i=1;i<=2*(n);i++)
		printf(" %d   ",seg[i].val);
	printf("\n");
}*/
int max(int a,int b)
{
	if(a>b)
		return a;
		else 
		return b;
}
int min(int a,int b)
{
	if(a<b)
		return a;
	else return b;
}							
segn merge1(int arr[], int beg,int mid ,int end,segn temp1 ,segn temp2 )
{
		int val1=0,max=-1000000000,sum=0,t=mid+1,i,j;
		segn ti;
		while(t<=end)
		{
			sum+=arr[t];
			if(sum>max)
			{
				max = sum;
				j=t;
			}
			t++;
		}
		val1+=max;
		sum = 0;
		max = -1000000000;
		t=mid;
		while(t>=beg)
		{
			sum += arr[t];
			if(sum>max)
			{
				max = sum;
				i=t;
			}
			t--;
		}		
		val1+=max;		
		if(temp1.val>=val1 && temp1.val>=temp2.val )
			return temp1;
		else if(temp2.val>=val1 && temp2.val>=temp1.val)
			return temp2;
		else{
				ti.i = i;
				ti.j = j;
				ti.val = val1;
				return ti;
			}	
}
segn preproc(segn seg[],int arr[] , int beg , int end ,int node)
{
	int mid,val1 ;
	segn temp1,temp2;
	mid = (beg+end)/2 ;
	if(beg ==end)
	{
		seg[node].i = beg;
		seg[node].j = beg;
		seg[node].val = arr[beg];
		return seg[node];
	}	
	else 	
	{
		temp1 = preproc(seg , arr , beg , mid , node*2);
		temp2 = preproc(seg , arr , mid+1 , end , 2*node+1);
		seg[node] = merge1(arr,beg,mid,end ,temp1,temp2);  	
		return seg[node] ;
	}	
}

segn query(segn seg[] ,int arr[] , int x,int y,int beg,int end ,int node)
{
	int mid = (beg+end)/2 ;
	segn n={-1,-1,-1};
	segn t1,t2;
	
	if(y<beg||x>end)
		return n;
	
	else if(x<=beg && y>=end)
		return seg[node] ;
	else 
	{
		t1 = query(seg , arr , x, y , beg , mid , 2*node);
		t2 = query(seg , arr , x, y , mid+1 , end , 2*node+1) ;
		if(t1.i==-1)
			return t2;
		if(t2.i==-1)
			return t1;
		return merge1(arr,max(beg,x), mid ,min(y,end), t1 , t2);
	}
}
segn upd(segn seg[] ,int arr[] ,int idx ,int val, int beg ,int end ,int node)
{
	int mid,val1 ;
	segn temp1,temp2;
	mid = (beg+end)/2 ;
	if(beg == end && beg == idx)
	{
		seg[node].i = beg;
		seg[node].j = beg;
		seg[node].val = val;
		return seg[node];
	}	
	else if(idx>=beg && idx<=end)	
	{
		temp1 = upd(seg , arr ,idx,val, beg , mid , node*2);
		temp2 = upd(seg , arr ,idx,val,mid+1, end , 2*node+1);
		seg[node] = merge1(arr ,beg, mid ,end,temp1,temp2);  	
	}
	return seg[node];	
}
			
int main()
{
	int n, x , y ,idx,t,i,v,val,arr[50001],cs ;
	segn seg[200000] = {{0,0,0}} , tk,tk1;
	scanf("%d",&n);
	if(n==0)
		return 0;
	 for(i=1;i<=n;i++)
	 	scanf("%d",&arr[i]);
	 	
	 scanf("%d",&t);
	 	tk1 = preproc(seg ,arr, 1 , n , 1 );	 
//	 showtree(seg,n);	
	 while(t--)
	 {

//	 	printf("check\n");	
	 	scanf("%d",&cs);
	 	switch(cs)
	 	{
	 		case 1:
	 					scanf("%d",&x);
	 					scanf("%d",&y);
	 					tk = query(seg,arr,x,y,1,n,1);
	 					printf("%d\n",tk.val);
	 					break;
	 		case 0 :		scanf("%d",&idx);
	 					scanf("%d",&val);
	 					arr[idx] = val;				
	 					tk = upd(seg ,arr,idx,val,1,n,1); 
	 					break;
	 	}
	 }
	 return 0;
} 					
	 					


