#include <stdio.h>
#include "iostream"
#include <vector>
#include <stack>
#include <set>
#include <map>
#include <unordered_set>
#include <unordered_map>
#include <string.h>
#include <algorithm>
using namespace std;
#define REP(i, n) for(int i = 0; i < n; i++)
#define REPP(i, a, b) for(int i = a; i < b; i++)
#define pb push_back;
#define foreach(gg, itit) for(auto itit = gg.begin(); itit != gg.end(); itit++)
int gcd(int a, int b){(b == 0) ? a : gcd(b, a % b);}
typedef long long ll;
typedef pair<int, int> ii;
int dp[1000005], ind[1000005], power[1000005], x, y, z, b, a, n, mx, ans, temp, mark[1000005];
int main(){
  cin >> n;
  temp = n;
  x = 1;
  mx = 0;
  ans = 0;
  while(n--){
    cin >> a >> b;
    a++;
    power[a] = min(a, b);
    mark[a] = 1;
    mx = max(mx, a);
  }

  REPP(i, 1, mx + 1){
    if(mark[i] != 0){
      dp[i] = 1 + dp[(i != power[i])? (i - power[i] - 1) : 0];
      ans = max(ans, dp[i]);
    }
    else dp[i] = dp[i - 1];
  }
  cout << temp - ans << "\n";
  return 0;
}
