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
#define N 100007
#define M 29
#define mod 1000000007
#define X first
#define Y second
#define INF 10000000000000007
#define REP(i, n) for(int i = 0; i < n; i++)
#define REPP(i, a, b) for(int i = a; i < b; i++)
#define foreach(gg, itit) for(auto itit = gg.begin(); itit != gg.end(); itit++)
using namespace std;
typedef long long ll;
typedef pair<int, int> ii;
typedef pair<string, ii> node;
vector<node> lis;
int c[N];
ll dp[N];
int n;
int main(){
    cin >> n;
    REP(i, n) cin >> c[i + 1];
    REP(i, n){
        string s;
        cin >> s;
        lis.push_back(node(s, ii(i + 1, 0)));
        reverse(s.begin(), s.end());
        lis.push_back(node(s, ii(i + 1, 1)));
    }
    sort(lis.begin(), lis.end());
    REPP(i, 1, n + 1) dp[i] = INF;
    foreach(lis, it){
        int idx = (*it).Y.X;
        int flag = (*it).Y.Y;
        ll cost = 0;
        if(flag == 1){ 
            cost = c[idx];
        }
        if(dp[idx - 1] + cost < dp[idx]) dp[idx] = dp[idx - 1] + cost;
    }
    if(dp[n] != INF) cout << dp[n] << "\n";
    else cout << "-1\n";
    return 0;
}