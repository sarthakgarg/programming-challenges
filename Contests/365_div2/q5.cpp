#include<stdio.h>
#include"iostream"
#include<string.h>
#include<vector>
#include<stack>
#include<queue>
#include<map>
#include<set>
#include<algorithm>
#include<unordered_map>
#define N 1005
#define M 10000
#define mod 1000000007
#define X first
#define Y second
#define INF 100000000000000007
#define REP(i, n) for(int i = 0; i < n; i++)
#define REPP(i, a, b) for(int i = a; i < b; i++)
#define foreach(gg, itit) for(auto itit = gg.begin(); itit != gg.end(); itit++)
using namespace std;
typedef long long ll;
ll n, k, a[N], sum[M][2], len[M][2];
int prv[N][M], id[N][M], pos;
vector<ll> lis;
vector<int> ans;
typedef pair<ll, ll> ii;
ii mn = ii(INF, INF);
void accum(int i, int j){
    if(prv[i][j] == -1 || i == 0) return;
    if(id[i][j] != -1) ans.push_back(id[i][j]);
    accum(i - 1, prv[i][j]);
}
ll gcd(ll a, ll b){
    if(b == 0) return a;
    else return gcd(b, a % b);
}
int main(){
    cin >> n >> k;
    REP(i, n) scanf("%I64d", &a[i]);
    for(ll i = 1; i * i <= k; i++){
        if(k % i == 0){
            lis.push_back(i);
            if(i * i != n) lis.push_back(k / i);
        }
    }
    int s = lis.size();
    sort(lis.begin(), lis.end());
    REP(i, s - 1) sum[i][0] = INF;
    sum[s - 1][0] = 0;
    len[s - 1][0] = 0;
    prv[0][s - 1] = -1;
    id[0][s - 1] = -1;
    REPP(i, 1, n + 1){
        int pr = (i - 1) % 2;
        int cr = i % 2;
        REP(j, s) {
            sum[j][cr] = INF;
            len[j][cr] = INF;
        }
        REP(j, s){
            if(sum[j][pr] == INF) continue;
            if(ii(len[j][cr], sum[j][cr]) > ii(len[j][pr], sum[j][pr])){
                sum[j][cr] = sum[j][pr];
                prv[i][j] = j;
                id[i][j] = -1;
                len[j][cr] = len[j][pr];
            }
            auto it = lower_bound(lis.begin(), lis.end(), lis[j]/gcd(lis[j], a[i - 1]));
            int idx = (int)(it - lis.begin());
            if(ii(len[idx][cr], sum[idx][cr]) > ii(len[j][pr] + 1, sum[j][pr] + a[i - 1])){
                sum[idx][cr] = sum[j][pr] + a[i - 1];
                len[idx][cr] = len[j][pr] + 1;
                prv[i][idx] = j;
                id[i][idx] = i - 1;
            }
        }
        if(sum[0][cr] != INF){
            if(ii(len[0][cr], sum[0][cr]) < mn){
                mn = ii(len[0][cr], sum[0][cr]);
                pos = i;
            }
        }
    }
    if(pos != 0) accum(pos, 0);
    if(ans.size() == 0) cout << "-1\n";
    else{
        cout << ans.size() << "\n";
        foreach(ans, it) cout << (*it) + 1 << " ";
        cout << "\n";
    }
    return 0;
}