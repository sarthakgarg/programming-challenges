#include<stdio.h>
#include"iostream"
#include<string.h>
#include<vector>
#include<stack>
#include<queue>
#include<map>
#include<set>
#include<algorithm>
#define N 103
#define M 10004
#define mod 1000000007
#define X first
#define Y second
#define INF 1000000007
#define REP(i, n) for(int i = 0; i < n; i++)
#define REPP(i, a, b) for(int i = a; i < b; i++)
#define foreach(gg, itit) for(auto itit = gg.begin(); itit != gg.end(); itit++)
using namespace std;
typedef long long ll;
int u[M], v[M], c[M], dp[N][N], n, m, x, y, w, t;
int main(){
    cin >> t;
    REPP(i, 1, t + 1){
        cout << "Case #" << i << ":\n";
        cin >> n >> m;
        REP(p, n) REP(q, n) dp[p][q] = (p == q) ? (0) : INF;
        REP(j, m){
            cin >> x >> y >> w;
            u[j] = x;
            v[j] = y;
            c[j] = w;
            dp[x][y] = min(dp[x][y], w);
            dp[y][x] = min(dp[y][x], w);
        }
        REP(k, n){
            REP(a, n){
                REP(b, n){
                    if(dp[a][b] > dp[a][k] + dp[k][b]) dp[a][b] = dp[a][k] + dp[k][b];
                }
            }
        }
        REP(j, m){
            if(c[j] > dp[u[j]][v[j]]) cout << j << "\n";   
        }
    }
    return 0;
}