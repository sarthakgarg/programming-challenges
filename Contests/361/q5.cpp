//Coding the RMQ data structure
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
#define N 200005
#define M 20
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
ll n, x, a[N], b[N], dpa[N][M], dpb[N][M], ans;
ll lg(ll n){
    ll k = 1, ct = 0;
    while(k < n) k = (k << 1), ct++;
    if(k > n) k = (k >> 1), ct--;
    return ct;
}
void build(ll arr[], ll dp[][M], ll n){
    REP(i, n) dp[i][0] = arr[i];
    REPP(j, 1, M){
        REP(i, n){
            if(i + (1 << j) - 1 >= n) continue;
            dp[i][j] = max(dp[i][j - 1], dp[i + (1 << (j - 1))][j - 1]);
        }
    }
}
ll query(ll l, ll r, ll dp[][M]){
    ll len = r - l + 1;
    ll j = lg(len);
    return max(dp[l][j], dp[r - (1 << j) + 1][j]);
}
int main(){
    cin >> n;
    REP(i, n) cin >> a[i];
    REP(i, n) cin >> x, b[i] = -x;
    build(a, dpa, n), build(b, dpb, n);
    REP(i, n){
        ll lo = i, hi = n - 1, mid;
        while(lo < hi){
            mid = lo + (hi - lo) / 2;
            if(query(i, mid, dpa) + query(i, mid, dpb) < 0) lo = mid + 1;
            else hi = mid;
        }
        ll lft = lo;
        lo = i, hi = n - 1;
        while(lo < hi){
            mid = lo + (hi - lo + 1) / 2;
            if(query(i, mid, dpa) + query(i, mid, dpb) <= 0) lo = mid;
            else hi = mid - 1;
        }
        ll rgt = lo;
        if(query(i, lft, dpa) + query(i, lft, dpb) == 0 && query(i, rgt, dpa) + query(i, rgt, dpb) == 0) ans += (rgt - lft + 1);
    }
    cout << ans << "\n";
}