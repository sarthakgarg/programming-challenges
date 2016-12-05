#include"iostream"
#include<stdio.h>
#include<vector>
#include<map>
#include<set>
#include<algorithm>
#define N 103
using namespace std;
typedef long long ll;
char str[N];
int choc[N][N], n, val;
int main(){
  cin >> n;
  for(int i = 0; i < n; i++){
    cin >> str;
    for(int j = 0; j < n; j++){
      if(str[j] == '.') choc[i][j] = 0;
      else choc[i][j] = 1;
    }
  }
  for(int i = 0; i < n; i++){
    for(int j = 0; j < n; j++){
      for(int k = j + 1; k < n; k++) val += choc[i][j] * choc[i][k];
    }
  }
  for(int i = 0; i < n; i++){
    for(int j = 0; j < n; j++){
      for(int k = j + 1; k < n; k++) val += choc[j][i] * choc[k][i];
    }
  }
  cout << val << "\n";
  return 0;
}
