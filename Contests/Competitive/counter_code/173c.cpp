#include<bits/stdc++.h>
using namespace std;
#define INF 1000000000
#define REP(i,a) for(int i=0;i<a;++i)
#define REPP(i,a,b) for(int i=a;i<b;++i)
int sq[504][504], sum[504][504], dp[2][504][504];
int main() {
	int n, m;
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	cin >> n >> m;
	REPP(i, 1, n + 1)REPP(j, 1, m + 1)cin >> sq[i][j];
	REPP(i, 1, n + 1)REPP(j, 1, m + 1)sum[i][j] = sum[i - 1][j] + sum[i][j - 1] - sum[i - 1][j - 1] + sq[i][j];
	int mx = -INF;
	REPP(i, 1, n + 1) {
		REPP(j, 1, m + 1) {
			int n = i % 2, p = (i - 1) % 2, len = min(2 * ((i - 1) / 2) + 1, 2 * ((j - 1) / 2) + 1);
			dp[n][j][1] = sq[i][j];
			for (int k = 3; k <= len; k += 2) {
				dp[n][j][k] = sum[i][j] - sum[i - k][j] - sum[i][j - k] + sum[i - k][j - k] - dp[p][j - 1][k - 2] - sq[i - k + 2][j - k + 1];
				mx = max(dp[n][j][k], mx);
			}
		}
	}
	cout << mx << "\n";
	return 0;
}