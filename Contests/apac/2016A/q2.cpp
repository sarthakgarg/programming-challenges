#include<stdio.h>
#include"iostream"
#include<string.h>
#include<vector>
#include<stack>
#include<queue>
#include<map>
#include<set>
#include<algorithm>
#define N 1005
#define mod 1000000007
#define X first
#define Y second
#define INF 1000000000007
#define REP(i, n) for(int i = 0; i < n; i++)
#define REPP(i, a, b) for(int i = a; i < b; i++)
#define foreach(gg, itit) for(auto itit = gg.begin(); itit != gg.end(); itit++)
using namespace std;
typedef double ll;
ll t, n, m, arr[N];
int l, r;
int check(ll x){
    int d = r - l + 1;
    double comp = 1;
    REPP(j, l, r + 1){
        if(comp > 1000000000) return 0;
        comp *= arr[j];
        while(d > 0 && comp > x){
            comp /= x;
            d--;
        }
    }
    while(d--) comp /= x;
    if(comp > 1) return 0;
    else return 1;
}
int main(){
    cin >> t;
    REPP(i, 1, t + 1){
        cin >> n >> m;
        cout << "Case #" << i << ":\n";
        REP(j, n) cin >> arr[j];
        REP(j, m){
            cin >> l >> r;
            ll lo = 1, hi = 1000000000;
            int iter = 100;
            while(iter--){
                ll mid = (lo + hi) / 2;
                int p = check(mid);
                if(p == 0) lo = mid;
                else hi = mid;
            }
            printf("%.7lf\n", lo);
        }
    }
    return 0;
}