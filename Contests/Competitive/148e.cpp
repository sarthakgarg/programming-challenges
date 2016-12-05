#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> ii;
#define X first
#define Y second
#define REP(i,a) for(int i=0;i<a;++i)
#define REPP(i,a,b) for(int i=a;i<b;++i)
#define FILL(a,x) memset(a,x,sizeof(a))
#define	foreach( gg,itit )	for( auto itit=gg.begin();itit!=gg.end();itit++ )
#define	mp make_pair
#define	pb push_back
#define sz(a) int((a).size())
#define	debug(ccc)	cout << #ccc << " = " << ccc << endl;
#define present(c,x) ((c).find(x) != (c).end())
#define INF 1000000000
const int mod = 1e9 + 7;
int n, m, dp[101][10005], num[101], sm[101][101], grd[101][101];
int greed(int k, int p) {
	int mx = 0;
	if (grd[k][p] != -1) return grd[k][p];
	REP(i, p + 1) {mx = max(mx, sm[k][i] - sm[k][0] + sm[k][num[k]] - sm[k][num[k] - p + i]);}
	return grd[k][p] = mx;
}
int find(int k, int p) {
	if (p == 0) return 0;
	if (k == n || p < 0) return -INF;
	if (dp[k][p] != -1) return dp[k][p];
	int mx = 0;
	REP(i, num[k] + 1) {mx = max(mx, greed(k, i) + find(k + 1, p - i));}
	return dp[k][p] = mx;
}
int main() {
	int x, sum;
	cin >> n >> m;
	REP(i, n) {sum = 0; cin >> num[i]; REP(j, num[i]) {cin >> x; sum += x; sm[i][j + 1] = sum;}}
	FILL(dp, -1);
	FILL(grd, -1);
	cout << find(0, m);
	return 0;
}