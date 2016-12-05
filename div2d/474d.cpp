//coding the basic dp (state is till n and ending in a suitable config)
#include<stdio.h>
#include"iostream"
#include<string.h>
#include<vector>
#include<stack>
#include<queue>
#include<map>
#include<set>
#include<algorithm>
#define N 100006
#define mod 1000000007
#define X first
#define Y second 
#define REP(i, n) for(int i = 0; i < n; i++)
#define REPP(i, a, b) for(int i = a; i < b; i++)
#define foreach(gg, itit) for(auto itit = gg.begin(); itit != gg.end(); itit++)
using namespace std;
typedef long long ll;
typedef pair<int, int> pi;
int t, k, dp[N][2], a, b, ans;
int main(){
    cin >> t >> k;
    dp[0][0] = 0;
    dp[0][1] = 1;
    REPP(i, 1, N){
        dp[i][1] = (dp[i - 1][0] + dp[i - 1][1]) % mod;
        dp[i][0] = ((i - k) >= 0) ? (dp[i - k][1] + dp[i - k][0]) % mod : 0;
    }
    REP(i, N){
        ans = (ans + dp[i][0]) % mod;
        ans = (ans + dp[i][1]) % mod;
        dp[i][0] = ans;
    }
    REP(i, t){
        cin >> a >> b;
        cout << ((dp[b][0] - dp[a - 1][0]) % mod + mod) % mod << "\n";
    }
    return 0;
}