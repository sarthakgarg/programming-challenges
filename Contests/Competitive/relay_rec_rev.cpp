// the basic aim of the question is how to maintain 2 paths , we have to take into account 2 rows . First fill the
// however we do not have enough storage capacity, to have n^4 thus we start a dp on the number of steps(or the sum),
//the row achieved by the first and the row achieved by the second

#include<bits/stdc++.h>
#define REP(i,n) for(int i=0;i<n;i++)
#define REPP(i,a,b) for(int i=a;i<b;++i)
#define FILL(a,x) memset(a,x,sizeof(a))
#define INF 10000000
int dp[604][302][302], arr[302][302], n, s;
int find(int steps, int r1, int r2) {
	int c1 = steps - r1 + 1, c2 = steps - r2 + 1;
	if (r1 < 1 || r2 < 1 || c1 < 1 || c2 < 1) {return dp[steps][r1][r2] = -INF;}
	if (r1 == 1 && r2 == 1 && c1 == 1 && c2 == 1)return dp[steps][r1][r2] = arr[1][1];
	if (dp[steps][r1][r2] != -INF) return dp[steps][r1][r2];
	int a, b, c, d;
	a = find(steps - 1, r1, r2);
	b = find(steps - 1, r1 - 1, r2);
	c = find(steps - 1, r1 - 1, r2 - 1);
	d = find(steps - 1, r1, r2 - 1);
	a = max(a, b); a = max(a, c); a = max(a, d);
	dp[steps][r1][r2] = (r1 == r2 && c1 == c2) ? (a + arr[r1][c1]) : (a + arr[r1][c1] + arr[r2][c2]);
	return dp[steps][r1][r2];
}
int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	cin >> n;
	REP(i, 604)REP(j, 302)REP(k, 302)dp[i][j][k] = -INF;
	REPP(i, 1, n + 1)REPP(j, 1, n + 1)cin >> arr[i][j];
	dp[1][1][1] = arr[1][1];
	cout << find(2 * n - 1, n, n) << "\n";
	return 0;
}