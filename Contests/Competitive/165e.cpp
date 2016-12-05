#include<bits/stdc++.h>
using namespace std;
#define REP(i,a) for(int i=0;i<a;++i)
#define REPP(i,a,b) for(int i=a;i<b;++i)
const int mod = 1e9+7;
bool dp[4194307][23],done[4194307][23];
int arr[1000006],n,pres[4194307];
bool find(int n,int k){        // be careful about the recursion depth 
	if(done[n][k]) return dp[n][k];
	if(k==22){if(pres[n])return dp[n][k]=true;else return dp[n][k]=false;}
	done[n][k]=true;
	int j,ans=(1<<k);
	j=n&(ans);
	if(j!=0) return dp[n][k]=find(n-ans,k+1);
	else return dp[n][k]=(find(n+ans,k+1)|find(n,k+1));
}
int track(int n,int k){
	if(k==22) return n;
	int j,ans=(1<<k);
	j=n&(ans);
	if(j!=0) return track(n-ans,k+1);
	else {
		if(dp[n+ans][k+1]) return track(n+ans,k+1);
		else return track(n,k+1);
	}	
}
int main(){
	ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
	cin>>n;
	REP(i,n){cin>>arr[i];pres[arr[i]]=1;}
	REP(i,n){if(find(arr[i],0))cout<<track(arr[i],0);else cout<<"-1";cout<<" ";}
	cout<<"\n";
	return 0;
}