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
#define INF 2000000000000000009
#define REP(i, n) for(int i = 0; i < n; i++)
#define REPP(i, a, b) for(int i = a; i < b; i++)
#define foreach(gg, itit) for(auto itit = gg.begin(); itit != gg.end(); itit++)
using namespace std;
typedef long long ll;
ll max(ll a, ll b){return (a > b) ? a : b;}
ll min(ll a, ll b){return (a < b) ? a : b;}
ll modexp(ll a, ll p){
    if(p == 0) return 1 % mod;
    ll x = modexp(a, p / 2);
    x = (x * x) % mod;
    if(p % 2) x = (x * a) % mod;
    return x;
}
typedef pair<ll, ll> pi;
typedef pair<pi, ll> pii;
set<pi> b;
ll n, m, x, y, p, q, l[N], r[N], ans[N], flg;
vector<pii> lis;
int main(){
    cin >> n >> m;
    REP(i, n){
        cin >> l[i] >> r[i];
    }
    REP(i, n - 1){
        lis.push_back(pii(pi(l[i + 1] - r[i], r[i + 1] - l[i]), i));
    }
    sort(lis.begin(), lis.end(), greater<pii>());
    b.insert(pi(INF, m + 1));
    b.insert(pi(-1, 0));
    REPP(i, 1, m + 1){
        cin >> x;
        b.insert(pi(x, i));
    }
    foreach(lis, it){
        ll mn = (*it).X.X, mx = (*it).X.Y, idx = (*it).Y;
        auto itf = b.upper_bound(pi(mx, m + 2));
        itf--;
        if(itf->X <= mx && itf->X >= mn){ 
            ans[idx] = itf->Y;
            b.erase(itf);
        }
        else flg = 1;
    }
    if(flg == 1) cout << "No\n";
    else{
        cout << "Yes\n";
        REP(i, n - 1) cout << ans[i] << " ";
        cout << "\n";
    }
    return 0;
}