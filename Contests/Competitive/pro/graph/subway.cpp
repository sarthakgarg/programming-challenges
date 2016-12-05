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
#define INF 1e9
const int mod = 1e9+7;
int n,m,x,y,visit[3002],hpt[3002],iscyc[3002],dist[3002],timer,dfn[3002],parent[3002];
vector<int> adj[3002];
void dfs(int v){
	visit[v]=1;
	dfn[v]=timer;
	timer++;
	int high=INF;
	foreach(adj[v],it){
		if(visit[*it]==0){parent[*it]=v; dfs(*it);high=min(high,hpt[*it]);}
		else if(parent[v]!=*it) high=min(high,dfn[*it]);
	}
	hpt[v]=high;
	if(hpt[v]<=dfn[v]) iscyc[v]=1; // if high point of a vertex is less then its dfn number then it is part of some cycle.
}
void comp(int v,int d){
	visit[v]=1;
	dist[v]=d;
	foreach(adj[v],it){
		if(visit[*it]==1) continue;
		if(iscyc[*it]==1) comp(*it,0);
		else comp(*it,d+1);
	}
}
int main(){
	ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
	cin>>n;
	REP(i,n){cin>>x>>y;adj[x].pb(y);adj[y].pb(x);}
	parent[1]=1;
	dfs(1);
	REPP(i,1,n+1){visit[i]=0;if(iscyc[i]==1)x=i;}
	comp(x,0);
	REPP(i,1,n+1) cout<<dist[i]<<" ";
	cout<<"\n";
	return 0;
}	
