#include<string.h>
#include<math.h>
#include<set>
#include<algorithm>
#include<stdio.h>
#include"iostream"
#include<queue>
#include<map>
#define N 400
#define M 150000
#define mod 1000000007
#define X first
#define Y second 
#define INF 10007
#define REP(i, n) for(int i = 0; i < n; i++)
#define REPP(i, a, b) for(int i = a; i < b; i++)
#define foreach(gg, itit) for(auto itit = gg.begin(); itit != gg.end(); itit++)
using namespace std;
typedef long long ll;
int t, n, l, a[N], dp[N][N];
int main(){
    cin >> t;
    REPP(y, 1, t + 1){
        cin >> n >> l;
        REP(i, n) cin >> a[i];
        REPP(k, 1, n + 1){
            REP(i, n){
                if(i + k - 1 >= n) dp[i][i + k - 1] = INF;
                else if(k < 3) dp[i][i + k - 1] = k;
                else{
                    dp[i][i + k - 1] = 1 + dp[i + 1][i + k - 1];
                    REPP(k1, i + 1, i + k - 1) REPP(k2, k1 + 1, i + k){
//                        cout << "i " << i << " k1 " << k1 << " k2 " << k2 << "\n";
                        if((i + 1 == k1 || dp[i + 1][k1 - 1] == 0) && (k1 + 1 == k2 || dp[k1 + 1][k2 - 1] == 0) && a[k1] == a[i] + l && a[k2] == a[i] + 2 * l){
                            dp[i][i + k - 1] = min(dp[i][i + k - 1], (k2 != i + k - 1) ? dp[k2 + 1][i + k - 1] : 0);
                        }
                    }
                }
            }
        }
 /*       REP(i, n){
            REPP(j, i, n) cout << dp[i][j] << " ";
            cout << "\n";
        }
*/        cout << "Case #" << y << ": " << dp[0][n - 1] << "\n";
    }
    return 0;
}