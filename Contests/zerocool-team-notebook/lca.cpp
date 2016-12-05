/*The following is the implementation of the lca, O(nlogn) solution by converting to rmq*/
#include"iostream"
#include<stdio.h>
#include<algorithm>
#include<complex>
#include<map>
#include<vector>
#include<set>
#include<stack>
#include<queue>
#include<deque>
#include<unordered_map>
using namespace std;
typedef long long ll;
typedef pair<ll, ll> ii;
#define X first
#define Y second
#define REP(i,a) for(int i=0;i<a;++i)
#define REPP(i,a,b) for(int i=a;i<b;++i)
#define FILL(a,x) memset(a,x,sizeof(a))
#define mp make_pair
#define pb push_back
#define foreach(gg, itit) for(auto itit = gg.begin(); itit != gg.end(); itit++)
#define sz(a) int((a).size())
#define debug(ccc)  cout << #ccc << " = " << ccc << endl;
#define present(c,x) ((c).find(x) != (c).end())
#define INF 1e9
const int MAXV = 100000;
const int mod = 1e9+7;
vector<int> adj[100005];
int t[8*(MAXV+2)], p[8*(MAXV+2)], depth[2*(MAXV+2)], x, y, z, q, r, timer, visited[MAXV + 2], ind[MAXV + 2], vertex[8*(MAXV+2)], root, n, k;
//segtree to return the index of the maximum depth in a given range
void build(int v, int tl, int tr){
    if(tl == tr){
        t[v] = depth[tl];
        p[v] = tl;
    }
    else{
        int tm = (tl+tr)/2;
        build(2*v, tl, tm);
        build(2*v+1, tm+1, tr);
        t[v] = min(t[2*v], t[2*v+1]);
        if(t[v]==t[2*v]) p[v] = p[2*v];
        else p[v] = p[2*v+1];
    }
}
ii query(int v, int tl, int tr, int l, int r){
    if(l>r) return ii(INF, 0);
    if(l==tl && r==tr) return ii(t[v], p[v]);
    int tm = (tl+tr)/2;
    ii left, right;
    left = query(2*v, tl, tm, l, min(r, tm));
    right = query(2*v+1, tm+1, tr, max(tm+1, l), r);
    if(left.X<right.X) return ii(min(left.X, right.X), left.Y);
    else return ii(min(left.X, right.X), right.Y);
}
// dfs to produce the euler tour and to build the array, depth and index
void dfs(int v, int d){
    visited[v] = 1;
    depth[timer] = d;
    vertex[timer] = v;
    ind[v] = timer;
    timer++;
    foreach(adj[v], it){
        if(visited[*it]==0){
            dfs(*it, d+1);
            depth[timer] = d;
            vertex[timer] = v;
            timer++;
        }
    }
}
// depth array constructed.
int lca(int u, int v){
    ii r = query(1, 0, timer-1, min(ind[u], ind[v]), max(ind[u], ind[v]));
    return vertex[r.Y];
}
int main(){
    ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
    cin>>n;
    REP(i, n-1){
        cin>>x>>y;
        adj[x].pb(y);
        adj[y].pb(x);
    }
    cin>>root;
    dfs(root, 0);
    build(1, 0, timer-1);
    cin>>k;
    while(k--){
        cin>>x>>y;
        cout<<lca(x, y)<<"\n";
    }
    return 0;
}