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
#define N 100005
typedef struct edge{
  ll x;
  ll y;
  ll w;
  ll isshort;
}edg;
edg e[2 * N];
typedef pair<ll, ii> iii;
ll n,m,w,x,y,p,parents[N],ls[N], s, t, lt[N], parentt[N], layer[N], visited[N], kmx;
vector<ii> adj[N];
vector<ll> tadj[N];
vector<ii> shortest_path;
priority_queue<ii,vector<ii>,greater<ii> > dijk;
priority_queue<iii,vector<iii>,greater<iii> > failure;

const int mod = 1e9+7;

void dfs(ll v, ll n){
  visited[v] = 1;
  kmx = max(kmx, n);
  layer[v] = n;
  int sz = tadj[v].size();
  for(int i = 0; i < sz; i++){
    if(visited[tadj[v][i]] != 0) dfs(tadj[v][i], n);
  }
}

void fill_layer(ll v, ll n){
  int sz = tadj[v].size();
  for(int i = 0; i < sz; i++){
    if(parents[tadj[v][i]] == v) fill_layer(tadj[v][i], n + 1);
  }
  dfs(v, n);
}

bool cmpfunc(edg l, edg r){
  ii lt = ii(layer[l.x], layer[l.y]);
  ii rt = ii(layer[r.x], layer[r.y]);
  return (lt < rt);
}

int main(){
	ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
	cin>>n>>m >> s >> t;
	REPP(i,1,m+1){
		cin>>x>>y>>w;
    e[i - 1].x = x;
    e[i - 1].y = y;
    e[i - 1].w = w;
    e[i - 1].isshort = 0;
		adj[x].pb(ii(y,w));
		adj[y].pb(ii(x,w));
	}

	REPP(i,1,N) ls[i]=INF, lt[i] = INF;
	ls[s]=0;dijk.push(ii(0,s));parents[s]=s;
	while(!dijk.empty()){
		ii v =dijk.top();
		dijk.pop();
		if(ls[v.Y]!=v.X) continue;
		foreach(adj[v.Y],it){
			if(v.X+it->Y<ls[it->X]){
				ls[it->X]=v.X+it->Y;
				parents[it->X]=v.Y;
				dijk.push(ii(ls[it->X],it->X));
			}
		}
	}

	lt[t]=0;dijk.push(ii(0,t));parentt[t]=t;
	while(!dijk.empty()){
		ii v =dijk.top();
		dijk.pop();
		if(lt[v.Y]!=v.X) continue;
		foreach(adj[v.Y],it){
			if(v.X+it->Y<lt[it->X]){
				lt[it->X]=v.X+it->Y;
				parentt[it->X]=v.Y;
				dijk.push(ii(lt[it->X],it->X));
			}
		}
	}
// both dijkstra's prepared, collect shortest path
/*  int v = t;
  while(parents[v] != v){
    shortest_path.push_back(ii(v, parents[v]));
    v = parents[v];
  }
*/

  // label vertices by layer number
  for(int i = 1; i <= n; i++) tadj[i].push_back(parents[i]), tadj[parents[i]].push_back(i);
  fill_layer(s, 1);


  // label edges by layer numbers
  for(int i = 0; i < m; i++) {
    if(layer[e[i].x] > layer[e[i].y]) swap(e[i].x, e[i].y);
    if(parents[e[i].x] == e[i].y || parents[e[i].y] == e[i].x) e[i].isshort = 1;
  }

  sort(e, e + m, cmpfunc);

  // emulate the binary heap
  int ei = 0;
  for(int i = 1; i <= kmx; i++){
    while(ei < m && layer[e[ei].x] <= i){
      if(layer[e[ei].x] == layer[e[ei].y] || e[ei].isshort == 1){
        ei++;
        continue;
      }
      failure.push(iii(ls[e[ei].x] + lt[e[ei].y] + e[ei].w, ii(layer[e[ei].x], layer[e[ei].y])));
      ei++;
    }
    int flag = 0;
    while(!failure.empty()){
      iii tp = failure.top();
      if(tp.Y.Y <= i) failure.pop();
      else{
        flag = 1;
        cout << tp.X << "\n";
        break;
      }
    }
    if(flag == 0) cout << "-1\n";
  }
	return 0;
}
