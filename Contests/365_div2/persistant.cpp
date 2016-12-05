#include<stdio.h>
#include"iostream"
#include<vector>
#define N 1005
#define M 100005
#define REP(i, n) for(int i = 0; i < n; i++)
#define REPP(i, a, b) for(int i = a; i < b; i++)
#define foreach(gg, itit) for(auto itit = gg.begin(); itit != gg.end(); itit++)
using namespace std;
typedef long long ll;
int d[N][N], x[M], y[M], t[M], a[M], n, m, p, q, r, l, c;
vector<int> adj[M];
void dfs(int z, int o){
    int b = d[x[z]][y[z]];
    a[z] = o;
    if(t[z] == 1 || t[z] == 2){
        if(t[z] == 1 && b == 0) a[z]++;
        else if(t[z] == 2 && b == 1) a[z]--;
        d[x[z]][y[z]] = ((t[z] == 1) ? 1 : 0);
        foreach(adj[z], it) dfs(*it, a[z]);
        d[x[z]][y[z]] = b;
    }
    else if(t[z] == 3){
        REP(i, m){
            if(d[x[z]][i] == 0){
                d[x[z]][i] = 1;
                a[z]++;
            }
            else{
                d[x[z]][i] = 0;
                a[z]--;
            }
        }
        foreach(adj[z], it) dfs(*it, a[z]);
        REP(i, m) d[x[z]][i] = ((d[x[z]][i] == 0) ? 1 : 0);
    }
    else foreach(adj[z], it) dfs(*it, a[z]);
}
int main(){
    cin >> n >> m >> q;
    t[0] = 2;
    REPP(i, 1, q + 1){
        cin >> p;
        if(p == 1 || p == 2){
            cin >> l >> r;
            x[i] = l - 1, y[i] = r - 1;
            adj[i - 1].push_back(i);
        }
        else if(p == 3){
            cin >> l;
            x[i] = l - 1;
            adj[i - 1].push_back(i);
        }
        else{
            cin >> l;
            adj[l].push_back(i);
        }
        t[i] = p;
    }
    dfs(0, 0);
    REPP(i, 1, q + 1) cout << a[i] << "\n";
    return 0;
}