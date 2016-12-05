#include<bits/stdc++.h>
using namespace std;
#define REPP(i,a,b) for(int i=a;i<b;++i)
#define INF 1e9+7
int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int t, n, x, y, ct, dp[200005][2];
	char str[2][200005];
	cin >> t;
	while (t--) {
		cin >> str[0] >> str[1];
		n = strlen(str[0]);
		dp[0][0] = (str[0][0] == '.') ? 0 : INF;
		dp[0][1] = (str[1][0] == '.') ? 0 : INF;
		REPP(i, 1, n) {
			dp[i][0] = (str[0][i] == '.') ? min(dp[i - 1][0], dp[i - 1][1] + 1) : INF;
			dp[i][1] = (str[1][i] == '.') ? min(dp[i - 1][0] + 1, dp[i - 1][1]) : INF;
		}
		int ans = min(dp[n - 1][0], dp[n - 1][1]);
		if (ans > 100000000) cout << "No\n";
		else cout << "Yes\n" << ans << "\n";
	}
	return 0;
}