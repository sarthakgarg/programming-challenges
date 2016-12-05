#include<stdio.h>
#include"iostream"
#include<vector>
#define X first
#define Y second
using namespace std;
#define N 203
typedef long long ll;
typedef pair<int, int> ii;
vector<ii> lt, rt;
int dp[N][N][N], n, m, arr[N][N], t;
ll ans;
int gcd(int a, int b){
  if(b == 0) return a;
  else return gcd(b, a % b);
}
ll solve(int i, int j, int l, int r){
    if(l == r){
      lt.clear();
      rt.clear();
      lt.push_back(ii(dp[i][j][l], 1));
      rt.push_back(ii(dp[i][j][r], 1));
      return dp[i][j][l];
    }
    int mid = (l + r) / 2;
    ll lmax = -1;
    lmax = max(lmax, solve(i, j, l, mid));
    vector<ii> rc = rt;
    lmax = max(lmax, solve(i, j, mid + 1, r));
    vector<ii> lc = lt;
    int ls = lc.size();
    int rs = rc.size();
    for(int i = 0; i < ls; i++){
      for(int j = 0; j < rs; j++){
        lmax = max(lmax, 1LL * (lc[i].Y + rc[j].Y) * gcd(lc[i].X, rc[j].X));
      }
    }
    lt.clear();
    rt.clear();
    int num = 1;
    int range = dp[i][j][l];
    for(int k = l + 1; k <= r; k++){
      num++;
      if(range == gcd(range, dp[i][j][k])) continue;
      else{
        lt.push_back(ii(range, num - 1));
        range = gcd(range, dp[i][j][k]);
      }
    }
    lt.push_back(ii(range, num));
    num = 1;
    range = dp[i][j][r];
    for(int k = r - 1; k >= l ; k--){
      num++;
      if(range == gcd(range, dp[i][j][k])) continue;
      else{
        rt.push_back(ii(range, num - 1));
        range = gcd(range, dp[i][j][k]);
      }
    }
    rt.push_back(ii(range, num));
    return lmax;
}
int main(){
  ios_base::sync_with_stdio(false); cin.tie(NULL);
  cin >> t;
  while(t--){
    cin >> n >> m;
    for(int i = 0; i < n; i++){
      for(int j = 0; j < m; j++){
        cin >> arr[i][j];
      }
    }
    if(n > m){
      for(int i = 0; i < n; i++){
        for(int j = 0; j < i; j++){
          swap(arr[i][j], arr[j][i]);
        }
      }
      swap(n, m);
    }
    for(int k = 0; k < m; k++){
      for(int l = 1; l <= n; l++){
        for(int s = 0; s < n; s++){
          int i = s;
          int j = s + l - 1;
          if(j >= n) continue;
          if(l == 1) dp[i][j][k] = arr[i][k];
          else{
            dp[i][j][k] = gcd(dp[i][(i + j) / 2][k], dp[(i + j) / 2 + 1][j][k]);
          }
        }
      }
    }
    ans = -1;
    for(int i = 0; i < n; i++){
      for(int j = i; j < n; j++){
        int width = (j - i + 1);
        ll val = solve(i, j, 0, m - 1);
        ans = max(ans, 1LL * width * val);
      }
    }
    cout << ans << "\n";
  }
  return 0;
}
