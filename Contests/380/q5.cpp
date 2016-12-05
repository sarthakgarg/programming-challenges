#include<stdio.h>
#include"iostream"
#include<string.h>
#include<vector>
#include<stack>
#include<queue>
#include<map>
#include<set>
#include<algorithm>
#include<assert.h>
#define N 200005
#define mod 1000000007
#define X first
#define Y second 
#define INF 1000000000007
#define REP(i, n) for(int i = 0; i < n; i++)
#define REPP(i, a, b) for(int i = a; i < b; i++)
#define foreach(gg, itit) for(auto itit = gg.begin(); itit != gg.end(); itit++)
using namespace std;
typedef long long ll;
typedef pair<ll, ll> pl;
ll a[N], mark[N], ans[N];
vector<ll> adj[N];
ll n, m, w, x, y;
pl parent[N], dp[N][19];
void dfs(int v){
  ll sum = 0;
  for(ll k : adj[v]){
    dfs(k);
    sum += ans[k];
  }
  ans[v] = sum + mark[v];
}
int main(){
  cin >> n;
  REP(i, n) scanf("%I64d", &a[i]);
  REP(i, n - 1){
    scanf("%I64d%I64d", &x, &w);
    x--;
    adj[x].push_back(i + 1);
    parent[i + 1] = pl(x, w);
  }
  parent[0] = pl(0, 0);
  REP(i, 19){
    REP(j, n){
      if(i == 0) dp[j][i] = parent[j];
      else dp[j][i] = pl(dp[dp[j][i - 1].X][i - 1].X, dp[j][i - 1].Y + dp[dp[j][i - 1].X][i - 1].Y);
    }
  }
  REP(i, n){
    mark[i]++;
    ll lft = a[i];
    int v = i;
    for(ll j = 18; j >= 0; j--){
      if(lft - dp[v][j].Y >= 0){
        lft -= dp[v][j].Y;
        v = dp[v][j].X;
      }
    }
    if(parent[v].X != v) mark[parent[v].X]--;
  }
  dfs(0);
  REP(i, n) cout << ans[i] - 1 << " ";
  cout << "\n";
  return 0;
}
