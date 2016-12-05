#include<stdio.h>
#include"iostream"
#include<queue>
#include<map>
#include<string.h>
#include<math.h>
#include<set>
#include<algorithm>
#define N 104
#define mod 1000000007
#define X first
#define Y second 
#define INF 1000000000007
#define REP(i, n) for(int i = 0; i < n; i++)
#define REPP(i, a, b) for(int i = a; i < b; i++)
#define foreach(gg, itit) for(auto itit = gg.begin(); itit != gg.end(); itit++)
using namespace std;
typedef long long ll;
int m, n, t, dp[N][N];
int main(){
    cin >> t;
    REPP(y, 1, t + 1){
        cin >> m >> n;
        REP(i, n){
            REP(j, m + 1){
                if(j > i + 1) dp[i][j] = 0;
                else if(i == 0){
                    if(j == 0) dp[i][j] = m;
                    else if(j == 1) dp[i][j] = 1;
                } 
                else if(j == 0) dp[i][j] = (1LL * m * dp[i - 1][0]) % mod;
                else dp[i][j] = (1LL * j * dp[i - 1][j - 1] + 1LL * (m - j) * dp[i - 1][j]) % mod;
            }
        }
        cout << "Case #" << y << ": " << dp[n - 1][m] << "\n";
    }
    return 0;
}