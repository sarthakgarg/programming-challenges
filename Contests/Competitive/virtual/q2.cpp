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
using namespace std;
typedef long long ll;
typedef pair<int,int> ii;
#define X first
#define Y second
#define REP(i,a) for(int i=0;i<a;++i)
#define REPP(i,a,b) for(int i=a;i<b;++i)
#define FILL(a,x) memset(a,x,sizeof(a))
#define	foreach( gg,itit )	for( auto itit=gg.begin();itit!=gg.end();itit++ )
#define	mp make_pair
#define	pb push_back
#define sz(a) int((a).size())
#define	debug(ccc)	cout << #ccc << " = " << ccc << endl;
#define present(c,x) ((c).find(x) != (c).end())
const int mod = 1e9+7;
int b,p,k,s,dp[350][100000],fact[100005];
int modexp(int base,int power){
	if(power==0) return 1;
	int x=modexp(base,power/2);
	x=(1LL*x*x)%mod;
	if(power%2)x=(1LL*x*base)%mod;
	return x;
}
int choose(int n,int r){
	if(n==r) return 1;
	if(r==0) return 1;
	int ans=fact[n];
//	cout<<ans<<" ";
	ans=(1LL*ans*modexp(r,mod-2))%mod;
//	cout<<ans<<" ";
	ans=(1LL*ans*modexp(n-r,mod-2))%mod;
//	cout<<ans<<" ";
//	cout<<"\n";
	return ans;
}
int main(){
	ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
	cin>>b>>p>>k>>s;
	int ct=0;
	fact[0]=1;
	REPP(i,1,100005)fact[i]=(1LL*fact[i-1]*i)%mod;	
	int corr = choose(p,b);
	int incorr=(modexp(2,p)-corr)%mod;
//	printf("corr and incorr are %d %d\n",corr,incorr);
	incorr=(incorr+mod)%mod;
	dp[1][1]=corr;
	REPP(i,1,s){
		REPP(j,1,min(k,340)+1){
			if(j==k){
				dp[i+k][k]+=(1LL*(dp[i][k])*(corr+incorr))%mod;
				dp[i+k][k]%=mod;
			}
			else{
				dp[i+j+1][j+1]+=(1LL*dp[i][j]*corr)%mod;
				dp[i+j][j]+=(1LL*dp[i][j]*incorr)%mod;
				dp[i+j+1][j+1]%=mod;
				dp[i+j][j]%=mod;
			}
		}
	}
	REPP(i,1,min(k,340)+3)ct+=dp[s][i];
	cout<<ct<<"\n";
	return 0;
}	


