#include<stdio.h>
#include"iostream"
using namespace std;
typedef long long ll;
int main(){
  ll a, b, c;
  cin >> a >> b >> c;
  if(a == b){
    cout << "YES\n";
    return 0;
  }
  if(c != 0 && (b - a) % c == 0 && (b - a) / c >= 0) cout << "YES\n";
  else cout << "NO\n";
  return 0;
}
