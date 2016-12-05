#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll, ll> ii;
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
const int mod = 1e9 + 7;
#define INF 1e18+7
ll n, m, r, inp[62][62][62], fast[62][62], dp[62][62][62], x, y, g;
int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	cin >> n >> m >> r;
	REPP(i, 1, n + 1) REPP(j, 1, n + 1) fast[i][j] = INF;
	REPP(i, 1, m + 1) {
		REPP(j, 1, n + 1) {
			REPP(k, 1, n + 1) cin >> inp[i][j][k];
		}
	}
	REPP(t, 1, m + 1) {
		REPP(k, 1, n + 1) {
			REPP(i, 1, n + 1) {
				REPP(j, 1, n + 1) {
					inp[t][i][j] = min(inp[t][i][j], inp[t][i][k] + inp[t][k][j]);
				}
			}
		}
		REPP(i, 1, n + 1) REPP(j, 1, n + 1) fast[i][j] = min(fast[i][j], inp[t][i][j]);
	}
	REPP(i, 1, n + 1) REPP(j, 1, n + 1) dp[0][i][j] = fast[i][j];
	REPP(k, 1, n - 1) {
		REPP(i, 1, n + 1) {
			REPP(j, 1, n + 1) {
				dp[k][i][j] = INF;
				REPP(p, 1, n + 1) {
					dp[k][i][j] = min(dp[k][i][j], min(dp[k - 1][i][j], dp[k - 1][i][p] + fast[p][j]));
				}

			}
		}
	}
	REPP(i, 1, r + 1) {
		cin >> x >> y >> g;
		if (g > n - 2) g = n - 2;
		cout << dp[g][x][y] << "\n";
	}
	return 0;
}