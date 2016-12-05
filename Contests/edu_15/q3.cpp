#include<stdio.h>
#include"iostream"
#include<string.h>
#include<vector>
#include<stack>
#include<queue>
#include<map>
#include<set>
#include<algorithm>
#define N 100005
#define mod 1000000007
#define X first
#define Y second 
#define INF 2000000007
#define REP(i, n) for(int i = 0; i < n; i++)
#define REPP(i, a, b) for(int i = a; i < b; i++)
#define foreach(gg, itit) for(auto itit = gg.begin(); itit != gg.end(); itit++)
using namespace std;
typedef long long ll;
int max(int a, int b){return (a > b) ? a : b;}
int min(int a, int b){return (a > b) ? b : a;}
int n, m, x, y = -INF;
vector<int> cell, citi;
int main(){
    cin >> n >> m;
    cell.resize(m);
    citi.resize(n);
    REP(i, n) cin >> citi[i];
    REP(i, m) cin >> cell[i];
    sort(cell.begin(), cell.end());
    REP(i, n){
        auto it = lower_bound(cell.begin(), cell.end(), citi[i]);
        x = min((it != cell.end()) ? (*it - citi[i]) : (INF), (it != cell.begin()) ? (citi[i] - *(it - 1)) : (INF));
        y = max(y, x);
    }
    cout << y << "\n";
    return 0;
}