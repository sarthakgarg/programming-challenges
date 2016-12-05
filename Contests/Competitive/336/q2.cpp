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
int n, s, f, tim, t[1002], mx, mn, a; 
int main(){
  cin >> n >> s;
  mx = s;
  while(n--){
    cin >> f >> tim;
    t[f] = max(t[f], tim);
  }
  tim = max(0, t[s]);
  for(int i = s - 1; i >= 0; i--){
    tim++;
    tim = max(tim, t[i]);
  }
  cout << tim << "\n";
  return 0;
}
