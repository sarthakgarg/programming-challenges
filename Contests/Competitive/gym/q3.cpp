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
#define REP(i,a) for(ll i=0;i<a;++i)
#define REPP(i,a,b) for(ll i=a;i<b;++i)
#define FILL(a,x) memset(a,x,sizeof(a))
#define foreach( gg,itit )  for( auto itit=gg.begin();itit!=gg.end();itit++ )
#define mp make_pair
#define pb push_back
#define sz(a) ll((a).size())
#define debug(ccc)  cout << #ccc << " = " << ccc << endl;
#define present(c,x) ((c).find(x) != (c).end())
const ll INF = 1000000005;
const ll MAXV = 100007;
vector<ii> adj[100009];
ll t[8*(MAXV+2)], p[8*(MAXV+2)], dep[2*(MAXV+2)], x, y, z, timer1, visited1[MAXV + 2], ind[MAXV + 2], vertex[8*(MAXV+2)];
ll timer, visited[100004], parent[100004], s[100005], f[100005], n, r, m, w, u, v, depth[100004], q;
ll mn, mx, back, from, backweight;
void build(ll v, ll tl, ll tr){
    if(tl == tr){
        t[v] = dep[tl];
        p[v] = tl;
    }
    else{
        ll tm = (tl+tr)/2;
        build(2*v, tl, tm);
        build(2*v+1, tm+1, tr);
        t[v] = min(t[2*v], t[2*v+1]);
        if(t[v]==t[2*v]) p[v] = p[2*v];
        else p[v] = p[2*v+1];
    }
}
ii query(ll v, ll tl, ll tr, ll l, ll r){
    if(l>r) return ii(INF, 0);
    if(l==tl && r==tr) return ii(t[v], p[v]);
    ll tm = (tl+tr)/2;
    ii left, right;
    left = query(2*v, tl, tm, l, min(r, tm));
    right = query(2*v+1, tm+1, tr, max(tm+1, l), r);
    if(left.X<right.X) return ii(min(left.X, right.X), left.Y);
    else return ii(min(left.X, right.X), right.Y);
}
void dfs1(ll v, ll d){
    visited1[v] = 1;
    dep[timer1] = d;
    vertex[timer1] = v;
    ind[v] = timer1;
    timer1++;
    foreach(adj[v], it){
        if(visited1[it->X]==0){
            dfs1(it->X, d+1);
            dep[timer1] = d;
            vertex[timer1] = v;
            timer1++;
        }
    }
}
ll lca(ll u, ll v){
    ii r = query(1, 0, timer-1, min(ind[u], ind[v]), max(ind[u], ind[v]));
    return vertex[r.Y];
}

void dfs(ll v, ll d, ll par){
    timer++;
    s[v] = timer;
    parent[v] = par;
    visited[v] = 1;
    depth[v] = d;
    foreach(adj[v], it){
        if(visited[it->X] == 0){
            dfs(it->X,it->Y + d, v);
            timer++;
        }
        else{
            if(it->X != parent[v]){
                // found a backedge
                back = v;
                from = it->X;
                backweight = it->Y;
            }
        }
    }
    f[v] = timer;
}
ll mod(ll x){
    if(x<0) return -x;
    else return x;
}
ll dist(ll u, ll v){
    ll l = lca(u, v);
    return mod(depth[l] - depth[u]) + mod(depth[l] - depth[v]);
}
int main(){
    ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
    cin >> n;
    while(n != 0){
        parent[1] = 1;
        mn = INF;
        REP(i, n){
            cin >> u >> v >> w;
            u++;
            v++;
            adj[u].pb(ii(v, w));
            adj[v].pb(ii(u, w));
        }   
        dfs(1, 0, 1);
        if(depth[back] < depth[from]) swap(back, from);
        dfs1(1, 0);
        build(1, 0, timer1-1);
        cin >> q;
        REP(i, q){
        	mn = INF;
            cin >> u >> v;
            u++;
            v++;
            if(u == v) {
                cout<<"0\n";
                continue;
            }
            mn = min(mn, dist(u, v));
            mn = min(mn, dist(u, back) + backweight + dist(from, v));
            mn = min(mn, dist(v, back) + backweight + dist(from, u));
            cout << mn<<"\n";
        }
        REPP(i, 1, n + 1)
        {
            adj[i].clear();
            visited[i] = 0;
            visited1[i] = 0;
            p[i] = 0;
            ind[i] = 0;
            t[i] = 0;
            vertex[i] = 0;
            depth[i] = 0;
            dep[i] = 0;
            parent[i] = 0;
            s[i] =0;
            f[i] = 0;
            ind[i] = 0;
        }
        timer1 = 0;
        timer = 0;
        parent[1] = 1;
        cin >> n;
    }
    return 0;
}