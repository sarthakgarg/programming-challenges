// Time complexity = min(O(n^2k), O(n^2log(n)))
#include<stdio.h>
#include"iostream"
#include<vector>
#define INF 1000000
using namespace std;
int main(){
  int n, k;
  cin >> n >> k;
  vector<vector<int> > dp(n + 1, vector<int>(k + 1, INF));
  for(int x = 0; x <= n; x++){
    for(int y = 0; y <= k; y++){
      if(x == 0) dp[x][y] = 0;
      else if(y == 0) dp[x][y] = INF;
      else{
        int mn = INF;
        for(int p = 0; p < x; p++) mn = min(mn, 1 + max(dp[x - p - 1][y], dp[p][y - 1]));
        dp[x][y] = mn;
      }
    }
  }
  cout << dp[n][k] << "\n";
  return 0;
}
