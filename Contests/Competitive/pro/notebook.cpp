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
// DIJKSTRA
const int MAXN = 100005;
int n,m,w,x,y,l[MAXN],parent[MAXN],s,d;
vector<ii> adj[MAXN];
priority_queue<ii, vector<ii>, greater<ii> > dijk;
void print(int v){
	if(parent[v]==v) { cout<<v<<" "; return;}
	print(parent[v]);
	cout<<v<<" ";
}
int main(){
	ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
	cin>>n>>m;
	REP(i,m){cin>>x>>y>>w;adj[x].pb(ii(y,w));adj[y].pb(ii(x,w));}
	cin>>s>>d;
	REPP(i,1,n+1) l[i]=INF;
	parent[s]=s;dijk.push(ii(0,s));l[s]=0;
	while(!dijk.empty()){
		ii v = dijk.top();
		dijk.pop();
		if(v.X!=l[v.Y]) continue;
		foreach(adj[v.Y],it){
			if(v.X+it->Y<l[it->X]){
				l[it->X]=v.X+it->Y;
				dijk.push(ii(l[it->X],it->X));
				parent[it->X]=v.Y;
			}
		}
	}
	cout<<"shortest distance is "<<l[d]<<"\n";
	cout<<"shortest path is "<<"\n";
	print(d);
	cout<<"\n";
	return 0;
}
//END DIJKSTRA

//HIGH-PT
int parent[MAXN],hpt[MAXN],visit[MAXN],timer,dfn[MAXN],iscyc[MAXN];
vector<int> adj[MAXN];
void dfs(int v){
	visit[v]=1;
	dfn[v]=timer;
	timer++;
	int high=INF;
	foreach(adj[v],it){
		if(visit[*it]==0){parent[*it]=v;dfs(*it);high=min(high,hpt[*it]);}
		else if(parent[v]!=*it) high=min(high,dfn[*it]);
	}
	hpt[v]=high;
	if(hpt[v]<=dfn[v]) iscyc[v]=1;
}
//END HIGH-PT

// Binary search pseudocode


binary_search(lo, hi, p):
   while lo < hi:
      mid = lo + (hi-lo)/2
      if p(mid) == true:
         hi = mid
      else:
         lo = mid+1

   if p(lo) == false:
      complain                // p(x) is false for all x in S!

   return lo         // lo is the least x for which p(x) is true

binary_search(lo, hi, p):
   while lo < hi:
      mid = lo + (hi-lo+1)/2
      if p(mid) == true:
         hi = mid-1
      else:
         lo = mid

   if p(lo) == true:
      complain                // p(x) is true for all x in S!

   return lo         // lo is the greatest x for which p(x) is false

// End Binary search pseudocode.
