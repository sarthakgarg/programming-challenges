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
#define M 150000
#define mod 1000000007
#define X first
#define Y second 
#define INF 1000000000007
#define REP(i, n) for(int i = 0; i < n; i++)
#define REPP(i, a, b) for(int i = a; i < b; i++)
#define foreach(gg, itit) for(auto itit = gg.begin(); itit != gg.end(); itit++)
using namespace std;
typedef long long ll;
vector<int> lis;
ll modexp(ll a, ll p){
        if(p == 0) return 1 % mod;
        ll x = modexp(a, p / 2);
        x = (x * x) % mod;
        if(p % 2) x = (x * a) % mod;
        return x;
}
ll n, x, visit[N], edg[N], ans = 1, len = 0, t, y;
int main(){
    cin >> n;
    REPP(i, 1, n + 1) cin >> edg[i];
    REPP(i, 1, n + 1){
        if(visit[i] == 0){
            x = i;
            while(visit[x] == 0){
                visit[x] = i;
                x = edg[x];
            }
            if(visit[x] == i) lis.push_back(x);
        }
    }
    foreach(lis, it){
        x = y = *it;
        t = 1;
        while(edg[y] != x){
            y = edg[y];
            t++;
        }
        len += t;
        ans = (ans * (modexp(2, t) - 2)) % mod;
    }
    len = n - len;
    ans = (ans * modexp(2, len)) % mod;
    ans = (ans + mod) % mod;
    cout << ans << "\n";
    return 0;
}