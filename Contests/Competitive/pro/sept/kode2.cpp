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
#include<cstdio>
using namespace std;
typedef long long ll;
typedef pair<int,int> ii;
#define X first
#define Y second
#define REP(i,a) for(int i=0;i<a;++i)
#define REPP(i,a,b) for(int i=a;i<b;++i)
#define FILL(a,x) memset(a,x,sizeof(a))
#define	foreach( gg,itit )	for(auto itit=gg.begin();itit!=gg.end();itit++ )
#define	mp make_pair
#define	pb push_back
#define sz(a) int((a).size())
#define	debug(ccc)	cout << #ccc << " = " << ccc << endl;
#define present(c,x) ((c).find(x) != (c).end())
#define INF 1e9+7;
const int mod = 1e9+7;
vector<ll> adj[100005];
ll n,m,x,y,z,visit[100005],k,edj[100005],ver[100005],edjv[100005];
void dfs(int i, int color){
	visit[i]=color;
	vector<ll>::iterator it;
	for(it=adj[i].begin();it!=adj[i].end();it++){
		if(visit[*it]==0) dfs(*it, color);
	}
	return;
}
int main(){
	ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
	cin>>n>>k;
	REP(i,k){
		cin>>x>>y;
		adj[x].pb(y);
		adj[y].pb(x);
		edjv[x]++;
		edjv[y]++;
	}
	REPP(i,1,n+1){
		if(visit[i]==0)dfs(i,i);
	}
	REPP(i,1,n+1){
		ver[visit[i]]++;
		edj[visit[i]]+=edjv[i];
	}
	ll ans=1;
	REPP(i,1,n+1){
		if(ver[i]==0) continue;
		ll e = edj[i]/2;
		if(e>ver[i]){ans=0;break;}
		if(e==ver[i])ans=(ans*2)%mod;
		else {ans = (ans*(ver[i]))%mod;}
	}
	cout<<ans<<"\n";
	return 0;
}