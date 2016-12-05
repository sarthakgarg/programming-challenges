#include<stdio.h>
#include"iostream"
#include<string.h>
#include<vector>
#include<stack>
#include<queue>
#include<map>
#include<set>
#include<algorithm>
#define N 100005
#define M 40
#define mod 1000000007
#define X first
#define Y second 
#define INF 2000000007
#define REP(i, n) for(int i = 0; i < n; i++)
#define REPP(i, a, b) for(int i = a; i < b; i++)
#define foreach(gg, itit) for(auto itit = gg.begin(); itit != gg.end(); itit++)
using namespace std;
typedef long long ll;
int max(int a, int b){return (a > b) ? a : b;}
ll sum[N][M], mn[N][M], v[N][M], k, t;
int edg[N], wg[N], n;
int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> n >> k;
    REP(i, n) cin >> edg[i];
    REP(i, n) cin >> wg[i];
    while((1LL << t) <= k) t++;
    REP(i, n) {
        v[i][0] = edg[i];
        sum[i][0] = mn[i][0] = wg[i];
    }
    REPP(j, 1, t){
        REP(i, n){
            v[i][j] = v[v[i][j - 1]][j - 1];
            sum[i][j] = sum[i][j - 1] + sum[v[i][j - 1]][j - 1];
            mn[i][j] = min(mn[i][j - 1], mn[v[i][j - 1]][j - 1]);
        } 
    }
    REP(i, n){
        ll vsum = 0;
        ll vmn = INF;
        int vert = i;
        ll rem = k;
        int log = t - 1;
        while(rem){
            vsum += sum[vert][log];
            vmn = min(vmn, mn[vert][log]);
            vert = v[vert][log];
            rem -= (1LL << log);
            while((1LL << log) > rem) log--;
        }
        cout << vsum << " " << vmn << "\n";
    }
    return 0;
}