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
#define N 105
#define M 150000
#define mod 10000007
#define X first
#define Y second 
#define INF 1000000000000000007
#define REP(i, n) for(int i = 0; i < n; i++)
#define REPP(i, a, b) for(int i = a; i < b; i++)
#define foreach(gg, itit) for(auto itit = gg.begin(); itit != gg.end(); itit++)
using namespace std;
typedef long long ll;
ll k1, n, m, c[N], p[N][N], dp[N][N][N];
bool isbase(ll i, ll j, ll k){
    if(i == 1 && k == 1){
        if(c[i] == 0) dp[i][j][k] = p[i][j];
        else if(c[i] != j) dp[i][j][k] = INF;
        else dp[i][j][k] = 0;
        return true;
    }
    return false;
}
ll isvalid(ll i, ll j, ll k){
    if(i >= 1 && k >= 1 && k <= i) return dp[i][j][k];
    else return INF;
}
int main(){
    cin >> n >> m >> k1;
    REPP(i, 1, n + 1) cin >> c[i];
    REPP(i, 1, n + 1){
        REPP(j, 1, m + 1) cin >> p[i][j];
    }
    REPP(i, 1, n + 1){
        REPP(j, 1, m + 1){
            REPP(k, 1, i + 1){
                if(isbase(i, j, k));
                else{
                    ll mn = INF, cost;
                    if(c[i] == 0) cost = p[i][j];
                    else if(c[i] != j) cost = INF;
                    else cost = 0;
                    REPP(r, 1, m + 1){
                        ll seg = ((r == j) ? (k) : (k - 1));
                        mn = min(mn, cost + isvalid(i - 1, r, seg));
                    }
                    dp[i][j][k] = mn;
                }
            }
        }
    }
    ll mn = INF;
    REPP(i, 1, m + 1) mn = min(mn, dp[n][i][k1]);
    if(mn != INF) cout << mn << "\n";
    else cout << "-1\n";
    return 0;
}