#include<stdio.h>
#include"iostream"
using namespace std;
typedef long long ll;
int main(){
  ll n, a, b, c, d, x, temp = 0;
  cin >> n >> a >> b >> c >> d;
  for(int i = 1; i <= n; i++){
    if(i - c + b >= 1 && i - c + b <= n && i - d + a >= 1 && i - d + a <= n && i - c - d + a + b >= 1 && i - c - d + a + b <= n) temp++;
  }
  cout << n * temp << "\n";
  return 0;
}
