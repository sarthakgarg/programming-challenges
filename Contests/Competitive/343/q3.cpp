#include"iostream"
#include<stdio.h>
#include<vector>
#include<map>
#include<set>
#include<algorithm>
#define N 100004
#define M 2004
#define MOD 1000000007
using namespace std;
typedef long long ll;
ll dp[M][M], n, m, lt, rt, val, x;
char str[N];
int main(){
  cin >> n >> m >> str;
  for(int i = 0; i < M; i++){
    for(int k = 0; k < M; k++){
      if(i < k) dp[i][k] = 0;
      else if(i == k || i == 0) dp[i][k] = 1;
      else dp[i][k] = (dp[i - 1][k + 1] + ((k != 0) ? dp[i - 1][k - 1] : 0)) % MOD;
    }
  }
  for(int i = 0; i < m; i++){
    if(str[i] == '(') lt++;
    else if(str[i] == ')'){
      if(lt != 0) lt--;
      else rt++;
    }
  }
  for(int i = 0; i <= n - m; i++){
    for(int k = 0; k <= n - m; k++){
      if(lt > k) continue;
      val = val + (dp[n - m - i][k - lt + rt] * dp[i][k]) % MOD;
      val = val % MOD;
    }
  }
  cout << val << "\n";
  return 0;
}
