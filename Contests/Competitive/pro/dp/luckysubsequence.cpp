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
ll modexp(ll a, ll pow){
	if(pow==0) return 1;
	ll x = modexp(a,pow/2);
	x = (x*x)%mod;
	if(pow%2) x = (x*a)%mod;
	return x;
}
ll check(ll x){
	ll flag=1;
	while(x!=0){
		if(x%10!=4&&x%10!=7) flag=0;
		x/=10;
	}
	return flag;
}
bool done[3004][3004];
ll n,k,unluck,fact[100008],x,y,p,q,r,s,t,dp[3000][3000];
map<ll,ll> freq;
vector<ll> d;
ll find(ll n,ll k){
	if(n<k) return 0;
	if(k==0) return dp[n][k] = 1;
	if(done[n][k]==true) return dp[n][k];
	done[n][k]=true;
	return dp[n][k] = (find(n-1,k) + (find(n-1,k-1)*d[n-1])%mod)%mod;
}
int main(){
	ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
	cin>>n>>k;
	fact[0]=1;
	REPP(i,1,100006) fact[i] = (fact[i-1]*i)%mod;
	REP(i,n){
		cin>>x;
		if(check(x))freq[x]++;
		else unluck++;
	}
	n=0;
	foreach(freq,it){
		d.pb(it->Y);
		n++;
	}  
	ll ans=0;
	REPP(i,0,min(unluck,k)+1){
		if(i+n<k) continue;
		 p = (((((fact[unluck]*modexp(fact[i],mod-2))%mod)*modexp(fact[unluck-i],mod-2))%mod)*find(n,k-i))%mod;
		 ans = (ans+p)%mod;
	}	
	cout<<ans<<"\n";
	return 0;
}	

		
