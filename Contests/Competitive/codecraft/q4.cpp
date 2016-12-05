#include<stdio.h>
#include"iostream"
#include<vector>
#include<map>
#include<set>
#include<algorithm>
#define N 160
#define K 200
#define MOD 1000000007
#define MX 1000000000000005
using namespace std;
typedef long long ll;
typedef pair<ll, ll> ii;
ll weight[N][N], dp[N][N][K], ct[N][N][K], done[N][N][K];
set<ll> kmap;
map<ll, ll> mymap;
ll n, m, k, u, v, w;
void add(ll k){
  kmap.insert(k);
  if(kmap.find(k/2) == kmap.end()) add(k/2);
  if(k%2 == 1){
    if(kmap.find(k/2 + 1) == kmap.end()) add(k/2 + 1);
  }
}

void fin(ll i, ll j, ll k){
  if(k == 0) {
    dp[i][i][0] = 0;
    return;
  }
  if(k == 1){
    if(i != j)
      dp[i][j][mymap[k]] = min(dp[i][j][mymap[k]], weight[i][j]);
    if(weight[i][j] != MX)
      ct[i][j][mymap[k]] = 1;
    done[i][j][mymap[k]] = 1;
    return;
  }
  ll ind  = mymap[k];
  if(done[i][j][ind]) return;
  ll a = k / 2;
  ll b = k - a;
  for(int p = 1; p <= n; p++){
    fin(i, p, a);
    fin(p, j, b);
    if(dp[i][j][ind] < dp[i][p][mymap[a]] + dp[p][j][mymap[b]]){
      dp[i][j][ind] = dp[i][p][mymap[a]] + dp[p][j][mymap[b]];
    }
  }

  if(dp[i][j][ind] == MX) return;
  for(int p = 1; p <= n; p++){
    if(dp[i][j][ind] == dp[i][p][mymap[a]] + dp[p][j][mymap[b]]){
      ct[i][j][ind] = (ct[i][j][ind] + (ct[i][p][mymap[a]] * ct[p][j][mymap[b]]) % MOD) % MOD;
    }
  }
  done[i][j][ind] = 1;
}

int main(){
  cin >> n >> m >> k;
  for(int i = 0; i < N; i++) for(int j = 0; j < N; j++){
      if(i != j) weight[i][j] = MX;
      else {
        weight[i][j] = 0;
        ct[i][j][0] = 1;
      }
    }
  for(int i = 0; i < N; i++) for(int j = 0; j < N; j++) for(int k = 0; k < K; k++ ){dp[i][j][k] = MX; }
  add(k);

  bool code = false;
  if(code == false){

  }

  for(int i = 0; i < m; i++){
    cin >> u >> v >> w;
    weight[u][v] = w;
    weight[v][u] = w;
  }
  for(int i = 1; i <= n; i++) for(int j = 1; j <= n; j++) fin(i, j, k);

  for(int i = 1; i <= n; i++){
    for(int j = 1; j <= n; j++){
      if(ct[i][j][mymap[k]] == 0) cout << "X 0 ";
      else cout << dp[i][j][mymap[k]] << " " << ct[i][j][mymap[k]] << " ";
    }
    cout << "\n";
  }
  return 0;
}
