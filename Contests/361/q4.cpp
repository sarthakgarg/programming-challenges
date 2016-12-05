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
#define N 500005
#define M 150000
#define mod 1000000007
#define MIN -1000000000
#define X first
#define Y second 
#define INF 1000000000000000007
#define REP(i, n) for(int i = 0; i < n; i++)
#define REPP(i, a, b) for(int i = a; i < b; i++)
#define foreach(gg, itit) for(auto itit = gg.begin(); itit != gg.end(); itit++)
using namespace std;
typedef long long ll;
map<ll, ll> sc, ec;
set<ll> pt;
ll l, r, n, k, a, b, x, y, ct, ans, fact[N];
ll modexp(ll base, ll power){
    if(power == 0) return 1 % mod;
    ll x = (modexp(base, power / 2));
    x = (x * x) % mod;
    if(power % 2) x = (x * base) % mod;
    return x;
}
int main(){
    cin >> n >> k;
    fact[0] = 1 % mod;
    REPP(i, 1, N) fact[i] = (1LL * i * fact[i - 1]) % mod;
    REP(i, n){
        cin >> l >> r;
        sc[l]++;
        ec[r + 1]++;
        pt.insert(l);
        pt.insert(r + 1);
    }
    foreach(pt, it){
        x = *it;
        if(it != pt.begin()){
            if(ct >= k){
                a = ((fact[ct] * modexp(fact[k], mod - 2)) % mod) * modexp(fact[ct - k], mod - 2);
                a %= mod;
                a = a * (x - y);
                a %= mod;
                ans += a;
                ans %= mod;
            }
        }
        ct -= ec[x];
        ct += sc[x];
        y = x;
    }
    cout << ans << "\n";
}