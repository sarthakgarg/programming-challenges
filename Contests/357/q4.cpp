#include"iostream"
#include<queue>
#include<map>
#include<string.h>
#include<vector>
#include<stack>
#include<stdio.h>
#include<math.h>
#include<set>
#include<algorithm>
#define N 100005
#define M 150000
#define mod 10000007
#define MIN -1000000000
#define X first
#define Y second 
#define INF 1000000000000000007
#define REP(i, n) for(int i = 0; i < n; i++)
#define REPP(i, a, b) for(int i = a; i < b; i++)
#define foreach(gg, itit) for(auto itit = gg.begin(); itit != gg.end(); itit++)
using namespace std;
typedef long long ll;
typedef pair<ll, ll> pi;
ll visit[N], n, m, x, y, in[N], hi[N], mark[N], st[N], d[N], flg;
vector<ll> adj[N];
vector<pi> give;
void dfs(ll v, ll depth){
    visit[v] = 1;
    d[v] = depth;
    ll mx = N;
    foreach(adj[v], it){
        if(visit[*it] == 0){
            dfs(*it, depth + 1);
            mx = min(mx, hi[*it]);
        }
        else mx = min(mx, d[*it]);
    }
    hi[v] = mx;
    if(mark[v] == 1 && hi[v] < d[v]) flg = 1;
}
int main(){
    cin >> n >> m;
    REP(i, m){
        cin >> x >> y;
        adj[x].push_back(y);
        in[y]++;
    }
    REP(i, n){
        cin >> x;
        adj[i + 1].push_back(x);
        mark[x] = 1;
    }
    REPP(j, 1, n + 1) if(in[j] == 0) dfs(j, 0);
    if(flg) cout << "-1\n";
    else{
        REPP(j, 1, n + 1) if(mark[j] == 1) give.push_back(pi(-d[j], j));
        cout << give.size() << "\n";
        sort(give.begin(), give.end());
        foreach(give, it) cout << it->Y << "\n";
    }
    return 0;
}