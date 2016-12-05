//whenever a dp problem asks to compute a certain value subject to the condition that there are no 'defaulters', compute it as total combinations minus the number with generalization. To compute the number with the defaulters, impose some kind of ordering on the defauters, like iterate over the first defaulter O(n^3)
#include<stdio.h>
#include<vector>
#include<algorithm>
#include<string.h>
#include"iostream"
#define N 204
#define mod 1000000007
using namespace std;
typedef long long ll;
ll fact[N], n, m, p, dp[N], d[];
ll pow(ll b, ll p){
  if(p == 0) return 1 % mod;
  ll x = pow(b, p / 2);
  x = (x * x) % mod;
  if(p % 2) x = (x * b) % mod;
  return x;
}
ll c(ll n, ll r){
  if(n < r) return 0;
  else return (((fact[n] * pow(fact[r], mod - 2)) % mod) * pow(fact[n - r], mod - 2)) % mod;
}
ll compute(ll n, ll y, ll k){
  ll sum = 0;
  for(int r = 0, r <= min(m - 1, k - 1); r++){
    ll sum2 = 0;
    for(int d = 0; d < r; d++){
      if(d % 2 == 0) sum2 = (sum2 + (c(r, d) * pow(r - d, n)) % mod) % mod;
      else sum2 = (sum2 - (c(r, d) * pow(r - d, n)) % mod) % mod;
    }
    sum = (sum + (c(k - 1, r) * sum2) % mod) % mod;
  }
  return sum;
}
int main(){
  cin >> n >> m >> p;
  fact[0] = 1 % mod;
  for(int i = 1; i < N; i++) fact[i] = (i * fact[i - 1]) % mod;
  for(int i = 0; i < n; i++) d[i] = compute(i, m, n - 1);
  dp[0] = 1;
  for(int i = 1; i <= p; i++){
    ll sum = 0;
    dp[i] = pow(n, p);
    for(int j = 0; j < i; j++){
      for(int k = j + 1; k < i; k++){
        // the indices j and k are of same color (say x) and the cells between j and k are of less than m colors chosen from n - 1 colors. The cells after the kth index upto the i - 1th index can be of any color.
        ll mult = (dp[j] * d[k - j - 1]) % mod;
        mult = (mult * pow(n, i - k - 1));
        sum = (sum + mult) % mod;
      }
    }
    dp[i] = (dp[i] - sum) % mod;
    dp[i] = (dp[i] + mod) % mod;
  }
  cout << dp[p] << "\n";
  return 0;
}
