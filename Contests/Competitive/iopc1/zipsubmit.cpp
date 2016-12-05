#include<stdio.h>
#include"iostream"
#include<vector>
#include<algorithm>
#define N 400005
#define INF 1000000007
using namespace std;
typedef long long ll;
int n, m, a[N], mark1[N], mark2[N], idx1[N], len, idx2[N], p1[N], p2[N], res1[N], res2[N];
vector<int> b(N), c(N);
vector<int> s1, s2;
typedef struct qu{
  int i;
  int q;
  int v;
  int a;
}query;
typedef struct chan{
  int in;
  int val;
}ch;
ch y[N];
bool f1(query l, query r){ return l.i < r.i; }
bool f2(int a, int b){return a > b;}
bool f3(query l, query r){ return l.q < r.q;}
int max(int a, int b){return (a > b) ? a : b;}
query k[N];
void build_reverse(){
  for(int i = 0; i <= n; i++) b[i] = -INF, idx1[i] = -1;
  b[0] = INF;
  for(int i = n - 1; i >= 0; i--){
    auto it = lower_bound(b.begin(), b.begin() + n + 1, a[i], f2);
    y[i].in = res1[i] = it - b.begin();
    y[i].val = b[y[i].in];
    b[y[i].in] = a[i];
    p1[i] = idx1[y[i].in - 1];
    idx1[y[i].in] = i;
  }
  len = 0;
  for(int i = 1; i <= n; i++){
    if(b[i] != -INF) len = i;
  }
}
void build_forward(){
  for(int i = 0; i <= n; i++) c[i] = INF, idx2[i] = -1;
  c[0] = -INF;
  for(int i = 0; i < n; i++){
    auto it = lower_bound(c.begin(), c.begin() + n + 1, a[i]);
    res2[i] = it - c.begin();
    c[res2[i]] = a[i];
    p2[i] = idx2[res2[i] - 1];
    idx2[res2[i]] = i;
  }
}
void solve(){
    int plt = 0, prt = 0;
    for(int i = 0; i <= n; i++) c[i] = INF;
    c[0] = -INF;
    int j = 0;
    for(int i = 0; i < n; i++){
      prt = y[i].in;
      b[prt] = y[i].val;
      while(k[j].i == i){
        if(mark1[i] && mark2[i]) k[j].a = len - 1;
        else k[j].a = len;
        int x = k[j].v;
        auto it = lower_bound(c.begin(), c.begin() + n + 1, x);
        int inc = (it == c.begin()) ? 0 : (it - c.begin() - 1) + 1;
        it = lower_bound(b.begin(), b.begin() + n + 1, x, f2);
        inc += (it == b.begin()) ? 0 : (it - b.begin() - 1);
        k[j].a = max(k[j].a, inc);
        j++;
      }
      auto it = lower_bound(c.begin(), c.begin() + n + 1, a[i]);
      plt = it - c.begin();
      c[plt] = a[i];
    }
}
int main(){
  ios_base::sync_with_stdio(false); cin.tie(NULL);
  cin >> n >> m;
  for(int i = 0; i < n; i++) cin >> a[i];
  for(int i = 0; i < m; i++){
    cin >> k[i].i >> k[i].v;
    k[i].i--;
    k[i].q = i;
    k[i].a = 0;
  }
  sort(k, k + m, f1);
  build_reverse();
  build_forward();
  int t, mx = -1;
  for(int i = 0; i < n; i++){
    if(mx <= res2[i]){
      mx = res2[i];
      t = i;
    }
  }
  while(p2[t] != -1){
    mark2[t] = 1;
    t = p2[t];
  }
  mark2[t] = 1;
  for(int i = 0; i < s2.size(); i++) cout << s2[i] << " " << "\n";
  mx = -1;
  for(int i = n - 1; i >= 0; i--){
    if(mx <= res1[i]){
      mx = res1[i];
      t = i;
    }
  }
  while(p1[t] != -1){
    mark1[t] = 1;
    t = p1[t];
  }
  mark1[t] = 1;
  solve();
  sort(k, k + m, f3);
  for(int i = 0; i < m; i++) cout << k[i].a << "\n";
  return 0;
}
