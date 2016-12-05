#include<stdio.h>
#include"iostream"
#include<queue>
#include<map>
#include<string.h>
#include<math.h>
#include<set>
#include<algorithm>
#define N 500
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
double dp[M][2];
int l, n, b, t, s, k, p, nxt[M];
void transfer(int j, double q){
    int x = j, y, z;
    int a = x - (nxt[j] - 1) * (nxt[j]) / 2;
    y = (nxt[j] + 1) * (nxt[j]) / 2 + a;
    z = y + 1;
    dp[x][1] += q / 3;
    dp[y][1] += q / 3;
    dp[z][1] += q / 3;
}
int main(){
    cin >> t;
    s = 1;
    REPP(i, 1, M){
        if(i > s * (s + 1) / 2) s++;
        nxt[i] = s;
    }
    REPP(y, 1, t + 1){
        cin >> b >> l >> n;
        REPP(i, 1, M) dp[i][0] = dp[i][1] = 0;
        dp[1][0] = (double) (b * 750);
        REPP(i, 1, l){
            REPP(j, 1, 1 + l * (l + 1) / 2){
                if(dp[j][0] > 250) transfer(j, dp[j][0] - 250);
            }
            REPP(j, 1, 1 + (l + 1) * (l + 2) / 2){
                dp[j][0] = dp[j][1];
                dp[j][1] = 0;
            }
        }
        if(dp[n][0] > 250) dp[n][0] = 250;
        printf("Case #%d: %.14lf\n", y, dp[n][0]);
    }
    return 0;
}