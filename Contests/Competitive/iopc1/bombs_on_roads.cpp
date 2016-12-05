#include<stdio.h>
#include"iostream"
#include<algorithm>
#include<vector>
#include<queue>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> ii;
#define X first
#define Y second
#define REP(i,a) for(int i=0;i<a;++i)
#define REPP(i,a,b) for(int i=a;i<b;++i)
#define	foreach( gg,itit )	for( auto itit=gg.begin();itit!=gg.end();itit++ )
#define	pb push_back
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
ll n,m,w,x,y,p,parents[N],ls[N], s, t, lt[N], parentt[N], layer[N], visited[N], kmx, mark[N], test, wht[N];
vector<ii> adj[N];
vector<ll> tadj[N];
priority_queue<ii,vector<ii>,greater<ii> > dijk;
priority_queue<iii,vector<iii>,greater<iii> > failure;
void dfs(ll v, ll x){
  visited[v] = 1;
  kmx = max(kmx, x);
  layer[v] = x;
  int sz = tadj[v].size();
  for(int i = 0; i < sz; i++){
    if(visited[tadj[v][i]] == 0 && layer[tadj[v][i]] == 0) dfs(tadj[v][i], x);
  }
}
void fill_layer(ll v, ll x){
  int sz = tadj[v].size();
  layer[v] = x;
  for(int i = 0; i < sz; i++){
    if(mark[tadj[v][i]] == 1 && layer[tadj[v][i]] == 0) fill_layer(tadj[v][i], x + 1);
  }
  dfs(v, x);
}
bool cmpfunc(edg l, edg r){
  ii lt = ii(layer[l.x], layer[l.y]);
  ii rt = ii(layer[r.x], layer[r.y]);
  return (lt < rt);
}
int main(){
	ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
  cin >> test;
  while(test--){
  	cin >> n >> m >> s >> t;
    while(!dijk.empty()) dijk.pop();
    while(!failure.empty()) failure.pop();
    for(int i = 0; i < n + 1; i++) {
      adj[i].clear();
      tadj[i].clear();
      mark[i] = visited[i] = layer[i] = parents[i] = parentt[i] = wht[i] = kmx = 0;
    }
  	REPP(i,1,m+1){
  		cin >> e[i - 1].x >> e[i - 1].y >> e[i - 1].w;
      e[i - 1].isshort = 0;
  		adj[x].pb(ii(y,w));
  		adj[y].pb(ii(x,w));
  	}
  	REPP(i,1,n + 1) ls[i] = INF, lt[i] = INF;
  	ls[s]=0; dijk.push(ii(0,s)); parents[s]=s;
  	while(!dijk.empty()){
  		ii v = dijk.top();
  		dijk.pop();
  		if(ls[v.Y] != v.X) continue;
  		foreach(adj[v.Y], it){
  			if(v.X + it->Y < ls[it->X]){
  				ls[it->X] = v.X + it->Y;
  				parents[it->X]=v.Y;
          wht[it->X] = it->Y;
  				dijk.push(ii(ls[it->X], it->X));
  			}
  		}
  	}
  	lt[t]=0; dijk.push(ii(0,t)); parentt[t]=t;
  	while(!dijk.empty()){
  		ii v = dijk.top();
  		dijk.pop();
  		if(lt[v.Y] != v.X) continue;
  		foreach(adj[v.Y], it){
  			if(v.X + it->Y < lt[it->X]){
  				lt[it->X] = v.X+it->Y;
  				parentt[it->X] = v.Y;
  				dijk.push(ii(lt[it->X], it->X));
  			}
  		}
  	}
    for(int i = 1; i <= n; i++){
      if(i != parents[i]){
        tadj[i].push_back(parents[i]);
        tadj[parents[i]].push_back(i);
      }
    }
    int v = t;
    while(parents[v] != v){
      mark[v] = 1;
      v = parents[v];
    }
    fill_layer(s, 1);
    for(int i = 0; i < m; i++) {
      if(layer[e[i].x] > layer[e[i].y]) swap(e[i].x, e[i].y);
      if((parents[e[i].x] == e[i].y && wht[e[i].x] == e[i].w) || (parents[e[i].y] == e[i].x && wht[e[i].y] == e[i].w)) e[i].isshort = 1;
    }
    sort(e, e + m, cmpfunc);
    int ei = 0;
    for(int i = 1; i < kmx; i++){
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
  }
	return 0;
}
