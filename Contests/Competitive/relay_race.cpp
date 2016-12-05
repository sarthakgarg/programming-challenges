//#include<bits/stdc++.h>
//templates
// l(i,n) loop 
// ra(i,a,b) loop in a range 
//fill(a,x) memset
//trv(container,iterator)
//mp make_pair
//pb push_back
//db(x) debug x
//lo long long 
//head headers
#include<stdio.h>
#include"iostream"
#include<stdlib.h>
#include<string.h>
#include<math.h>
#include<algorithm>
#include<complex>
#include<map>
#include<vector>
#include<set>
#include<unordered_map>
#include<unordered_set>
#include<stack>
#include<queue>
#include<deque>
using namespace std;
#define REPP(i,a,b) for(int i=a;i<b;++i)
#define FILL(a,x) memset(a,x,sizeof(a))
#define INF 100000000
int dp[302][302],arr[302][302],n,sum[302][302],s,stat[302][302],row[302][302][2];
int correct(int j,int k,int i){
	if(j==1&&k==1){row[j][k][0]=1;row[j][k][1]=1;stat[j][k]=1;return dp[j][k];}
	int a=-INF,b=-INF,r,c;
	if(stat[j][k]==1) return dp[j][k];
	if(j>1){
		a=correct(j-1,k,i);
		if(row[j-1][k][1]>j)a+=arr[i][j];
		row[j][k][0]=row[j-1][k][0];row[j][k][1]=row[j-1][k][1];
	}	
	if(k>1&&k>j)b=correct(j,k-1,i)+arr[i][k];
	if(b>a){a=b;row[j][k][0]=row[j][k-1][0];row[j][k][1]=row[j][k-1][1];}
	if(dp[j][k]>=a){a=dp[j][k];row[j][k][0]=j;row[j][k][1]=k;}
	stat[j][k]=1;
	return dp[j][k]=a;
}
int main(){
	ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
	FILL(dp,-INF);
	dp[1][1]=0;
	cin>>n;
	REPP(i,1,n+1)REPP(j,1,n+1)cin>>arr[i][j];
	REPP(i,1,n+1){
		REPP(j,1,n+1)REPP(k,j,n+1)dp[j][k]+=(j!=k)?(arr[i][j]+arr[i][k]):arr[i][j];
		FILL(stat,-1);
		REPP(j,1,n+1)REPP(k,j,n+1)s=correct(j,k,i);
	}	
	cout<<dp[n][n]<<"\n";
	return 0;
}	



