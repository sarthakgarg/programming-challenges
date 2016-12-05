#include"iostream"
#include<queue>
#include<stdio.h>
#include<vector>
#include<stack>
#include<stdlib.h>
#include<map>
#include<string.h>
#include<math.h>
#include<set>
#include<unordered_map>
#include<algorithm>
#define N 100000
#define M 150000
#define mod 1000000007
#define X first
#define Y second 
#define INF 1000000000007
#define REP(i, n) for(int i = 0; i < n; i++)
#define REPP(i, a, b) for(int i = a; i < b; i++)
#define foreach(gg, itit) for(auto itit = gg.begin(); itit != gg.end(); itit++)
using namespace std;
int j;
bool cmp(int l, int r){
    return (1 & (l >> j)) < (1 & (r >> j)); 
}
int main(){
    int n;
    cin >> n;
    vector<int> v(n);
    for(int i = 0; i < n; i++){
        cin >> v[i];
    }
    for(j = 0; j < 31; j++){
        sort(v.begin(), v.end(), cmp);
    }
    for(int x : v) cout << x << " ";
    cout << "\n";
    return 0;
}