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
#include<unordered_map>
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
typedef int ll;
ll max(ll a, ll b){return (a > b) ? a : b;}
ll min(ll a, ll b){return (a < b) ? a : b;}
ll modexp(ll a, ll p){
    if(p == 0) return 1 % mod;
    ll x = modexp(a, p / 2);
    x = (x * x) % mod;
    if(p % 2) x = (x * a) % mod;
    return x;
}
char str[2], d[N];
ll n, r[N], c[N], q, tu[4 * N], tl[4 * N], sz, temp;
vector<ll> lis;
set<ll> hist;
unordered_map<ll, ll> m;
void update(ll v, ll tl, ll tr, ll pos, ll val, ll t[]){
    if(tl == tr && tl == pos) t[v] = val;
    else{
        ll mid = (tl + tr) / 2;
        if(pos <= mid) update(2 * v, tl, mid, pos, val, t);
        else update(2 * v + 1, mid + 1, tr, pos, val, t);
        t[v] = max(t[2 * v], t[2 * v + 1]);
    }
}
ll query(ll v, ll tl, ll tr, ll l, ll r, ll t[]){
    if(l > r) return 0;
    if(tl == l && tr == r) return t[v];
    ll mid = (tl + tr) / 2;
    return max(query(2 * v, tl, mid, l, min(mid, r), t), query(2 * v + 1, mid + 1, tr, max(l, mid + 1), r, t));
}
int main(){
    cin >> n >> q;
    lis.push_back(0), lis.push_back(n + 1);
    REP(i, q){
        scanf("%d%d%s", &c[i], &r[i], str);
        d[i] = str[0];
        lis.push_back(r[i]);
    }
    sort(lis.begin(), lis.end());
    lis.erase(unique(lis.begin(), lis.end()), lis.end());
    sz = lis.size();
    REP(i, sz) m[lis[i]] = i;
    update(1, 0, sz - 1, m[0], n, tl);
    update(1, 0, sz - 1, m[n + 1], n, tu);
    REP(i, q){
        if(hist.find(r[i]) != hist.end()){
            cout << "0\n";
            continue;
        }
        hist.insert(r[i]);
        if(d[i] == 'U'){
            ll lo = 0, hi = temp = m[r[i]], mid;
            while(lo < hi){
                mid = lo + (hi - lo + 1) / 2;
                if(query(1, 0, sz - 1, mid, temp, tl) >= r[i]) lo = mid;
                else hi = mid - 1;
            }
            cout << r[i] - lis[lo] << "\n";
            update(1, 0, sz - 1, temp, n - lis[lo], tu);
        }
        else{
            ll lo = temp = m[r[i]], hi = sz - 1, mid;
            while(lo < hi){
                mid = lo + (hi - lo) / 2;
                if(query(1, 0, sz - 1, temp, mid, tu) >= n - r[i] + 1) hi = mid;
                else lo = mid + 1;
            }
            printf("%d\n", lis[lo] - r[i]);
            update(1, 0, sz - 1, temp, lis[lo] - 1, tl);
        }
    }
    return 0;
}