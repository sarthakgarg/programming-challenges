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
typedef pair<ll,ll> ii;
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
#define INF 1e18
#define N 10004
#define W 1003
ll n,m,w,x,y,p,parent[N],l[N], t, fun[N], cost[N], ans, dp[N][W], D;
vector<ii> adj[N];
priority_queue<ii,vector<ii>,greater<ii> > dijk;
void print(ll v){
	if(parent[v]==v){ cout<<v<<" ";return ;}
	print(parent[v]);
	cout<<v<<" ";
}
int main(){
	ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
	cin >> t;
	while(t--){
		cin >> n >> m >> D;
		for(int i = 0; i < N; i++){
			adj[i].clear();
			parent[i] = 0;
			l[i] = 0;
		}
		REPP(i, 1, m+1){
			cin >> x >> y >> w;
			x++;
			y++;
			adj[x].pb(ii(y,w));
			adj[y].pb(ii(x,w));
		}
		REPP(i,1,N) l[i]=INF;
		l[1]=0;dijk.push(ii(0,1));parent[1]=1;
		while(!dijk.empty()){
			ii v =dijk.top();
			dijk.pop();
			if(l[v.Y]!=v.X) continue;
			foreach(adj[v.Y],it){
				if(v.X+it->Y<l[it->X]){
					l[it->X]=v.X+it->Y;
					parent[it->X]=v.Y;
					dijk.push(ii(l[it->X],it->X));
				}
			}
		}
		for(int i = 0; i < n - 1; i++){
			cin >> fun[i];
			cost[i] = 2 * l[i + 2];
		}
			for(int i = 0; i < n - 1; i++){
			for(int j = 0; j <= W; j++){
				dp[i][j] = 0;
			}
		}
		ans = -1;
		for(int i = 0; i < n - 1; i++){
			for(int j = 0; j <= D; j++){
				dp[i][j] = max((i > 0) ? dp[i - 1][j] : 0, (cost[i] <= j) ? (fun[i] + ((i > 0) ? (dp[i - 1][j - cost[i]]) : 0)) : 0);
				ans = max(ans, dp[i][j]);
			}
		}
		cout << ans << "\n";
	}
	return 0;
}
