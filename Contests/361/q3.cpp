#include"iostream"
#include<queue>
#include<map>
#include<string.h>
#include<vector>
#include<stack>
#include<stdio.h>
#include<math.h>
#include<set>
#include<algorithm>
#define N 100005
#define M 150000
#define mod 10000007
#define MIN -1000000000
#define X first
#define Y second 
#define INF 1000000000000000007
#define REP(i, n) for(int i = 0; i < n; i++)
#define REPP(i, a, b) for(int i = a; i < b; i++)
#define foreach(gg, itit) for(auto itit = gg.begin(); itit != gg.end(); itit++)
using namespace std;
typedef long long ll;
ll m, a, b;
int check(ll a, ll b){
    ll ct = 0, k = 2;
    while(a >= k * k * k){
        ct += (a / (k * k * k));
        k++;
    }
    if(ct < b) return 0;
    else if(ct > b) return 1;
    else return 2;
}
int main(){
    cin >> m;
    ll lo = 0, hi = INF, mid;
    while(lo < hi){
        mid = lo + (hi - lo) / 2;
        if(check(mid, m) == 0){
            lo = mid + 1;
        }
        else {
            hi = mid;
        }
    }
    if(check(lo, m) == 2) cout << lo << "\n";
    else cout << "-1\n";
}