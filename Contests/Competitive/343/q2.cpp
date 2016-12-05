#include"iostream"
#include<stdio.h>
#include<vector>
#include<map>
#include<set>
#include<algorithm>
#define D 366
#define N 5000
using namespace std;
typedef long long ll;
char str[2];
ll male[D], female[D], a, b, val, n;
int main(){
  cin >> n;
  for(int i = 0; i < n; i++){
    cin >> str >> a >> b;
    for(int i = a; i <= b; i++){
      if(str[0] == 'M') male[i - 1]++;
      else female[i-1]++;
    }
  }
  for(int i = 0; i < D; i++){
    val = max(val, 2 * min(male[i], female[i]));
  }
  cout << val << "\n";
  return 0;
}
