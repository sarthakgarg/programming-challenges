#include"iostream"
#include<stdio.h>
#include<vector>
#include<map>
#include<set>
#include<algorithm>
#define N 100004
#define pb push_back
using namespace std;
typedef long long ll;
vector<int> adj[N];
int n, m, x, y, p[N], c[N], dp[N][LN], l[N], val, flag, child;
ll f[N], sum[N], ans, ways;
void dfs(int v, int u){
  p[v] = u;
  l[v] = (v == u) ? 0 : l[u] + 1;
  int sz = adj[v].size();
  for(int i = 0; i < sz; i++){
    if(adj[v][i] == u) continue;
    dfs(adj[v][i], v);
    c[v] += c[adj[v][i]];
    f[v] += (f[adj[v][i]] + c[adj[v][i]]);
  }
  c[v]++;
}

int find(int x, int y){
  int res = 0;
  for(int i = LN - 1; i >= 0; i--){
    if(l[dp[x][i]] > l[y]){
      res += (1 << i);
      x = dp[x][i];
    }
  }
  if(l[x] > l[y]){
    if(p[x] == y) child = x;
    x = p[x];
    res++;
  }
  if(x == y){
    flag = 1;
    return res;
  }
  for(int i = LN - 1; i >= 0; i--){
    if(dp[x][i] != dp[y][i]){
      x = dp[x][i];
      y = dp[y][i];
      res += (1 << (i + 1));
    }
  }
  return res + 2;
}

void findsum(int v, int u){
  if(v == u) sum[v] = f[v];
  else sum[v] = sum[u] + n - 2 * c[v];
  int sz = adj[v].size();
  for(int i = 0; i < sz; i++)
    if(adj[v][i] != u) findsum(adj[v][i], v);
}

int main(){
  cin >> n >> m;
  for(int i = 0; i < n - 1; i++){
    scanf("%d%d", &x, &y);
    adj[x].pb(y);
    adj[y].pb(x);
  }
  dfs(1, 1);
  findsum(1, 1);
  for(int i = 0; i < LN; i++)
    for(int j = 1; j <= n; j++)
      dp[j][i] = (i == 0) ? p[j] : dp[dp[j][i - 1]][i - 1];

  for(int i = 0; i < m; i++){
    cin >> x >> y;
    flag = 0;
    if(l[y] > l[x]) swap(x, y);
    val = find(x, y);
    val++;
    if(flag == 0){
      ans = 1LL * val * c[x] * c[y] + 1LL * c[x] * f[y] + 1LL * c[y] * f[x];
      ways = 1LL * c[x] * c[y];
    }
    else{
      ans = 1LL * val * c[x] * (n - c[child]) + 1LL * f[x] * (n - c[child]) + 1LL * c[x] * (sum[y] - f[child] - c[child]);
      ways = 1LL * c[x] * (n - c[child]);
    }
    printf("%.14lf\n", ((double)(ans)) / ways);
  }
  return 0;
}
