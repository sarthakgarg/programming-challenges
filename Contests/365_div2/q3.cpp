#include<stdio.h>
#include"iostream"
#include<string.h>
#include<vector>
#include<stack>
#include<queue>
#include<map>
#include<set>
#include<algorithm>
#define N 10005
#define mod 1000000007
#define X first
#define Y second
#define INF 100000000000007
#define REP(i, n) for(int i = 0; i < n; i++)
#define REPP(i, a, b) for(int i = a; i < b; i++)

#define foreach(gg, itit) for(auto itit = gg.begin(); itit != gg.end(); itit++)
using namespace std;
typedef long long ll;
int n, mnpos, mxpos;
double v, u, w, mn = INF, mx = -INF;
double x[N], y[N], tim = 0.0, p, q, s;
int main(){
    cin >> n >> w >> v >> u;
    REP(i, n){
        cin >> x[i] >> y[i];
        if(x[i] != 0){
            s = (v * y[i]) / x[i];
            if(s >= mx){
                mxpos = i;
                mx = s;
            }
            if(s >= 0 && s < mn){
                mnpos = i;
                mn = s;
            }
        }
        else{
            mx = INF;
            mxpos = i;
        }
    }
    if(mx <= u || mn >= u) printf("%.7lf\n", w / u);
    else{
        int i = mnpos;
        tim += (x[i] / v);
        while(true){
            if(x[(i + 1) % n] == x[i]) s = INF;
            else s = (v * (y[(i + 1) % n] - y[i]) / (x[(i + 1) % n] - x[i]));
            if(s >= 0 && s < u) tim += (x[(i + 1) % n] - x[i]) / v;
            else{
                tim += (w - y[i]) / u;
                break;
            }
            i++;
        }
        printf("%.7lf\n", tim);
    }
    return 0;
}