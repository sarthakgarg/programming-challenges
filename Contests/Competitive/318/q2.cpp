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
#define INF 1e18+7
ll know[4002][4002],in[4002],n,p,q,x,y,m,sum,mx;
vector<ll> adj[4002];
int main(){
	ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
	cin>>n>>m;
	REPP(i,1,m+1){
		cin>>x>>y;
		adj[x].pb(y);
		adj[y].pb(x);
		know[x][y]=1;
		know[y][x]=1;
		in[x]++;
		in[y]++;
	}
	mx = INF;
	REPP(i,1,n+1){
		p = adj[i].size();
		sum=INF;
		REP(j,p){
			REPP(k,j+1,p){
				if(know[adj[i][j]][adj[i][k]]==1){
					sum = min(sum, in[adj[i][j]]+in[adj[i][k]]);
				}
			}
		}
		if(sum==INF) continue;
		mx = min(mx,in[i]+sum);
	}
	if(mx==INF) cout<<"-1\n";
	else cout<<mx-6<<"\n";
	return 0;
}