#include<stdio.h>
#include"iostream"
using namespace std;
typedef long long ll;
ll t, n, q, x, p, r, s, k, lt, rt;
int main(){
  cin >> t;
  while(t--){
    cin >> n >> q;
    while(q--){
      cin >> x;
      r = x;
      s = x;
      lt = 0;
      rt = 0;
      while(2 * r <= n){
        r = 2 * r;
        lt++;
      }
      while(2 * s + 1 <= n){
        s = 2 * s + 1;
        rt++;
      }
      if(lt == rt){
        cout << s - r + 1 << "\n";
      }
      else{
        cout << n - r + 1 + s - n / 2 << "\n";
      }
    }
  }
  return 0;
}
