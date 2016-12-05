#include<stdio.h>
#include"iostream"
#include<queue>
#include<map>
#include<string.h>
#include<math.h>
#include<set>
#include<algorithm>
#define N 400006
#define mod 1000000007
#define X first
#define Y second 
#define INF 1000000000007
#define REP(i, n) for(int i = 0; i < n; i++)
#define REPP(i, a, b) for(int i = a; i < b; i++)
#define foreach(gg, itit) for(auto itit = gg.begin(); itit != gg.end(); itit++)
using namespace std;
typedef long long ll;
vector<int> adj[N];
int visit[N], n, mx[N], fl[N], x, y, ct[N], st[N], feed[N];
void dfs(int v){
    visit[v] = 1;
    int c = 1, m = 1;
    foreach(adj[v], it){
        if(visit[*it] == 0){
            dfs(*it);
            m = max(m, mx[*it]);
            c += ct[*it];
            if(ct[*it] > n / 2 && ct[*it] - mx[*it] > n / 2) fl[v] = 1;
        }
    }
    ct[v] = c;
    if(c <= n / 2) m = c;
    mx[v] = m;
}
void dfs2(int v, int k){
    visit[v] = 1;
    st[v] = k;
    int l = 0;
    foreach(adj[v], it){
        if(visit[*it] == 0){
            feed[*it] = max(feed[*it], l);
            l = max(l, mx[*it]);
        }
    }
    int r = 0;
    for(auto it = adj[v].end() - 1; it + 1 != adj[v].begin(); it--){
        if(visit[*it] == 0){
            feed[*it] = max(feed[*it], r);
            r = max(r, mx[*it]);
        }
    }
    foreach(adj[v], it){
        if(visit[*it] == 0){
            if(n - ct[*it] <= n / 2) feed[*it] = max(feed[*it], n - ct[*it]);
            dfs2(*it, max(st[v], feed[*it]));
        }
    }
}
int main(){
    cin >> n;
    REP(i, n - 1){
        cin >> x >> y;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }
    dfs(1);
    REPP(i, 1, n + 1) visit[i] = 0;
    dfs2(1, 0);
    REPP(i, 1, n + 1){
        if(n - ct[i] > n / 2 && n - ct[i] - st[i] > n / 2) fl[i] = 1;
        if(fl[i] == 1) cout << "0 ";
        else cout << "1 ";
    }
    cout << "\n";
    return 0;
}