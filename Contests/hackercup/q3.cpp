#include <stdio.h>
#include "iostream"
#include <stack>
#include <queue>
#include <vector>
#include <map>
#include <set>
#include <unordered_map>
#include <unordered_set>
#define REP(i, n) for(int i = 0; i < n; i++)
#define REPP(i, a, b) for(int i = a; i < b; i++)
#define foreach(gg, itit) for(auto itit = gg.begin(); itit != gg.end(); itit++)
#define X first
#define Y second
#define mod 1000000007
using namespace std;
typedef pair<int, int> ii;
typedef long long ll;
int n, fr[2003][2003];
int countfree(int a, int b){
  if(a == 0 && b == 0) return  fr[a][b] = 1;
  if(a == 1 && b == 0) return  fr[a][b] = 1;
  if(b == 0) return  fr[a][b] = 1;
  if(a > b + 1) return  fr[a][b] = (fr[a - 1][b] + fr[a][b-1])%mod;
  else return  fr[a][b] = fr[a][b-1];
}
int countfull(int a, int b){
  if(a == 0) return  fr[a][b] = 1;
  if(a >= b) return  fr[a][b] = fr[a-1][b];
  else if(a < b) return  fr[a][b] = (fr[a-1][b] + fr[a][b-1])%mod;
}
int main(){
  //  ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
  int x, y, z, a, b, t;
  cin >> t;
  z = t;
  while(t--){
    REP(i, 2001) REP(j, 2001) fr[i][j] = 0;
    scanf("%d-%d", &a, &b);
    n = a + b;
    REP(i, a + 1) REP(j, b + 1){
      if(i > j) x = countfree(i, j);
    }
    REP(i, 2001) REP(j, 2001) fr[i][j] = 0;
    REP(i, a + 1) REP(j, b + 1){
      y = countfull(i, j);
      
    }
    printf("Case #%d: %d %d\n", z - t, x, y);
  }
  return 0;
}
