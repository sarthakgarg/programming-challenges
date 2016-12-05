// For finding centroid of a subtree, it is enough to find the smallest subsubtree of the tree whose size is > 1/2 size of the subtree. To find this
//construct the euler tour of the graph and then construct a segtree on top of it. The simple query operation is to apply binary search on a segment of an array
#include<stdio.h>
#include"iostream"
#include<string.h>
#include<vector>
#include<stack>
#include<queue>
#include<map>
#include<set>
#include<algorithm>
#define N 300005
#define mod 1000000007
#define X first
#define Y second 
#define INF 1000000000007
#define REP(i, n) for(int i = 0; i < n; i++)
#define REPP(i, a, b) for(int i = a; i < b; i++)
#define foreach(gg, itit) for(auto itit = gg.begin(); itit != gg.end(); itit++)
using namespace std;
typedef long long ll;
typedef pair<ll, int> pi;
typedef vector<pi> node;
node t[4 * N];
vector<int> adj[N];
int n, p, x, y, visit[N], tour[4 * N], st[N], en[N], timer;
ll sum[N];
pi mn(pi a, pi b){
    if (a < b) return a;
    else return b;
}
void build(int v, int tl, int tr, int arr[]){
    if(tl == tr){
        t[v].push_back(pi(sum[arr[tl]], arr[tl]));
        return;
    }
    int mid = (tl + tr) / 2;
    build(2 * v, tl, mid, arr);
    build(2 * v + 1, mid + 1, tr, arr);
    t[v].resize(t[2 * v].size() + t[2 * v + 1].size());
    merge(t[2 * v].begin(), t[2 * v].end(), t[2 * v + 1].begin(), t[2 * v + 1].end(), t[v].begin());
}
pi query(int v, int tl, int tr, int l, int r, int x){
    if(l > r) return pi(1LL * INF, -1);
    if(l == tl && r == tr){
        auto it = lower_bound(t[v].begin(), t[v].end(), pi(x, -1));
        if(it != t[v].end()) return *it;
        else return pi(1LL * INF, -1);
    }
    int mid = (tl + tr) / 2;
    return mn(query(2 * v, tl, mid, l, min(mid, r), x), query(2 * v + 1, mid + 1, tr, max(mid + 1, l), r, x));
}
void euler(int v){
    visit[v] = 1;
    st[v] = timer;
    tour[timer++] = v;
    ll s = 0;
    foreach(adj[v], it){
        if(visit[*it] == 0){
            euler(*it);
            s += sum[*it];
        }
    }
    en[v] = timer - 1;
    sum[v] = 2 + s;
}
int main(){
    cin >> n >> p;
    REPP(i, 2, n + 1){
        cin >> x;
        adj[x].push_back(i);
        adj[i].push_back(x);
    }
    euler(1);
    build(1, 0, timer, tour);
    REP(i, p){
        cin >> x;
        cout << query(1, 0, timer, st[x], en[x], sum[x] / 2).Y << "\n";
    }
    return 0;
}