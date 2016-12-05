#include"iostream"
#include<stdio.h>
#include<vector>
#include<map>
#include<set>
#include<math.h>
#include<algorithm>
#define N 100004
#define B 320
#define X first
#define Y second
#define PI 3.14159265358979323846
using namespace std;
typedef long long ll;
typedef pair<ll, ll> pi;
map<ll, ll> val;
ll n, r, h, m[N], dp[N], mx[B], x, y, z;
pi inp[N];
int main(){
  cin >> n;
  z = ((ll)sqrt(n + 1)) + 1;
  for(int i = 0; i < n; i++){
    cin >> r >> h;
    x = r * r * h;
    inp[i] = pi(x, i);
  }
  sort(inp, inp + n);
  for(int i = 0; i < n; i++)
    m[inp[i].Y] = i;
  for(int i = 0; i < n; i++){
    int j = m[i];
    val[inp[j].X]++;
    int bn = (j - val[inp[j].X] + 1)/ z;
    ll lmax = 0;
    for(int k = bn * z; k < j - val[inp[j].X] + 1; k++) lmax = max(lmax, dp[k]);
    for(int k = 0; k < bn; k++) lmax = max(lmax, mx[k]);
    dp[j] = inp[j].X + lmax;
    y = max(y, dp[j]);
    bn = j / z;
    mx[bn] = max(mx[bn], dp[j]);
  }
  printf("%.14lf\n", PI * (double)(y));
  return 0;
}
