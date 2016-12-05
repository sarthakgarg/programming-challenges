#include<stdio.h>
#include"iostream"
#include<string.h>
#include<vector>
#include<stack>
#include<queue>
#include<map>
#include<set>
#include<algorithm>
#define N 200005
#define mod 1000000007
#define X first
#define Y second 
#define INF 1000000000007
#define REP(i, n) for(int i = 0; i < n; i++)
#define REPP(i, a, b) for(int i = a; i < b; i++)
#define foreach(gg, itit) for(auto itit = gg.begin(); itit != gg.end(); itit++)
using namespace std;
typedef long long ll;
int n, k, s, t, c[N], v[N], g[N];

int pred(int f){
    int tim = 0;
    int pos = 0;
    REP(i, k){
        int d = (g[i] - pos);
        if(d > f) return 0;
        tim += (2 * d - ((f - d > d) ? (d) : (f - d)));
        pos = g[i];
    }
    if(tim <= t) return 1;
    else return 0;
}

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    cin >> n >> k >> s >> t;
    REP(i, n) cin >> c[i] >> v[i];
    REP(i, k) cin >> g[i];
    sort(g, g + k);
    g[k] = s;
    k++;
    int lo = 0, hi = mod;
    while(lo < hi){
        int mid = lo + (hi - lo) / 2;
        if(pred(mid) == 1){
            hi = mid;
        }
        else{
            lo = mid + 1;
        }
    }
    int pos = n;
    int cost = mod;
    REP(i, n){
        if(cost > c[i] && v[i] >= lo){
            cost = c[i];
            pos = i;
        }
    }
    if(pos == n) cout << "-1\n";
    else cout << cost << "\n";
    return 0;
}