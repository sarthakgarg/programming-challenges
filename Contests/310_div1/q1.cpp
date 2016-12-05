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
ll max(ll a, ll b){return (a > b) ? a : b;}
ll min(ll a, ll b){return (a < b) ? a : b;}
ll modexp(ll a, ll p){
    if(p == 0) return 1 % mod;
    ll x = modexp(a, p / 2);
    x = (x * x) % mod;
    if(p % 2) x = (x * a) % mod;
    return x;
}
ll n, k, a, b, x, parts, steps, len = 0;
int main(){
    cin >> n >> k;
    REP(i, k){
        cin >> x;
        ll flg = 0, ct = 0;
        REP(j, x){
            cin >> a;
            if(a == ct + 1) ct++;
            else len = max(len, ct), ct = -1;
            parts++;
            steps++;
        }
        steps--;
        len = max(len, ct);
    }
    //cout << steps << " " << parts << " " << len << "\n";
    cout << steps + parts - 1 - 2 * (len - 1) << "\n";
    return 0;
}