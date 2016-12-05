#include"iostream"
#include<stdio.h>
#include<vector>
#include<map>
#include<set>
#include<algorithm>
#define N 100004
#define pb push_back
using namespace std;
typedef long long ll;
ll arr[N], sum[N], x, y, z, k, t , p, n, l, r;
int main(){
  cin >> t;
  while(t--){
    cin >> n;
    ll flag = 0;
    for(int i = 0; i < n; i++) cin >> arr[i];
    if(n == 1){
      cout << "0\n";
      continue;
    }
    x = -1;
    y = -1;
    z = 0;
    l = 0;
    r = n - 1;
    while(l <= r){
      if(x == -1){
        if(l == r) break;
        else{
          x = arr[l];
          y = arr[r];
          l++;
          r--;
        }
      }
      else if(x == y){
        x = -1;
        y = -1;
      }
      else if(x > y){
        y += arr[r];
        r--;
        z++;
      }
      else{
        x += arr[l];
        l++;
        z++;
      }
    }
    if(x != y) z++;
    cout << z << "\n";
  }
  return 0;
}
