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
#define REP(i, n) for(ll i = 0; i < n; i++)
#define REPP(i, a, b) for(ll i = a; i < b; i++)
#define pb push_back;
#define foreach(gg, itit) for(auto itit = gg.begin(); itit != gg.end(); itit++)
//ll gcd(ll a, ll b){(b == 0) ? a : gcd(b, a % b);}
typedef long long ll;
typedef pair<ll, ll> ii;
ll max(ll a, ll b){
  if(a < b) return b;
  else return a;
}
ll min(ll a, ll b){
  if(b < a) return b;
  else return a;
}
char a[200005], b[200005];
ll a1[200005], y, lena, l, p, q, lenb, k;
int main(){
  cin >> a >> b;
  y = 0;
  for(ll i = 0; a[i] != '\0'; i++){
    if(a[i] == '1') y++;
    a1[i] = y;
  }
  lena = strlen(a);
  lenb = strlen(b);
  l = 0;
  for(ll i = 0; b[i] != '\0'; i++){
    p = min(lena - 1, i);
    q = max(0, lena - lenb + i);
    //  cout << p << " " << q << " ";
    k = (a1[p] - ((q != 0) ? (a1[q - 1]) : (0)));
    if(b[i] == '0') l += k;
    else{
      l += (p - q + 1 - k);
    }
    //     cout << l << "\n";
  }
  cout << l << "\n";
  return 0;
}
