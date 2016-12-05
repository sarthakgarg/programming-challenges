#include<stdio.h>
#include<algorithm>
#include"iostream"
#define N 1000005
#define MX 100000000000000000
using namespace std;
typedef long long ll;
ll arr[N], n, t, lt[N], rt[N], ans;
int main(){
  ios_base::sync_with_stdio(false); cin.tie(NULL);
  cin >> t;
  while(t--){
    cin >> n;
    for(int i = 0; i < n; i++) cin >> arr[i];
    if(n == 1){
      cout << "0\n";
      continue;
    }
    sort(arr, arr + n);
    lt[0] = 0;
    for(int i = 1; i < n; i++){
      lt[i] = lt[i - 1] + arr[i] - arr[i / 2];
    }
    for(int i = 0; i < n / 2; i++){
      swap(arr[i], arr[n - 1 - i]);
    }
    rt[0] = 0;
    for(int i = 1; i < n; i++){
      rt[i] = rt[i - 1] - arr[i] + arr[i / 2];
    }
    ans = MX;
    for(int i = 0; i < n; i++){
      ans = min(ans, lt[i] + rt[n - 2 - i]);
    }
    cout << ans << "\n";
  }
  return 0;
}
