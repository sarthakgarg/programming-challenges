#include<bits/stdc++.h>
using namespace std;
#define REP(i,a) for(int i=0;i<a;++i)
#define REPP(i,a,b) for(int i=a;i<b;++i)
#define FILL(a,x) memset(a,x,sizeof(a))
const int mod = 1e9+7;
int n,arr[11],dp[103][1027],fact[103];
int modexp(int base,int power){
	if(power==0) return 1;
	int x=modexp(base,power/2);
	x=(1LL*x*x)%mod;
	if(power%2)x=(1LL*x*base)%mod;
	return x;
}
int choose(int n,int r){
	if(n<r||n<0)return 0;
	int ans=fact[n];
	ans=(1LL*ans*modexp(fact[r],mod-2))%mod;
	ans=(1LL*ans*modexp(fact[n-r],mod-2))%mod;
	return ans;
}
int find(int n,int bitnum){
	int numleft=0,digcount=0;
	REPP(i,1,10)if((bitnum&(1<<i))!=0){numleft+=arr[i];digcount++;}
	if(n==0&&numleft==0)return 1;
	if(n==0&&numleft!=0)return 0;
	if(n<0)return 0;
	if(dp[n][bitnum]!=-1)return dp[n][bitnum];
	int a=(1LL*find(n-1,bitnum)*digcount)%mod;
	int b=0;
	REPP(i,1,10){
		if((bitnum&(1<<i))!=0){  
			if(arr[i]!=0)
				b=(b+(1LL*choose(n-1,arr[i]-1)*find(n-arr[i],bitnum-(1<<i)))%mod)%mod; 
		}
	}
	return dp[n][bitnum]=(a+b)%mod;
}
int main(){
	ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
	cin>>n;
	REP(i,10)cin>>arr[i];
	fact[0]=1;
	REPP(i,1,102)fact[i]=(1LL*fact[i-1]*i)%mod;
	FILL(dp,-1);
	int k=0;
	REPP(i,1,n+1)REPP(j,arr[0],i)k=(k+(1LL*choose(i-1,j)*find(i-j,1023))%mod)%mod;
	cout<<k<<"\n";
	return 0;
}	