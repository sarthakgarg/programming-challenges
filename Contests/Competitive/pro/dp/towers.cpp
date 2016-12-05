#include<stdio.h>
#include"iostream"
#include<stdlib.h>
#include<string.h>
#include<math.h>
#include<algorithm>
#include<complex>
#include<map>
#include<vector>
#include<set>
#include<unordered_map>
#include<unordered_set>
#include<stack>
#include<queue>
#include<deque>
using namespace std;
typedef long long ll;
typedef pair<int, int> ii;
#define X first
#define Y second
#define REP(i,a) for(int i=0;i<a;++i)
#define REPP(i,a,b) for(int i=a;i<b;++i)
#define FILL(a,x) memset(a,x,sizeof(a))
#define	foreach( gg,itit )	for( typeof(gg.begin()) itit=gg.begin();itit!=gg.end();itit++ )
#define	mp make_pair
#define	pb push_back
#define sz(a) int((a).size())
#define	debug(ccc)	cout << #ccc << " = " << ccc << endl;
#define present(c,x) ((c).find(x) != (c).end())
const int mod = 1e9 + 7;
#define INF 2e18
ll a[5002], dp[5002][5002], s[5002], x, y, q, r, n;
int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	cin >> n;
	REPP(i, 1, n + 1) {cin >> a[i]; x += a[i]; s[i] = x;}
	REPP(i, 0, n) dp[n + 1][i] = 0;
	for (int i = n; i > 0; i--) {
		ll mx  = INF;
		x = n;
		for (int j = 0; j < i; j++) {
			while (x >= i && s[x] - s[i - 1] >= s[i - 1] - ((j == 0) ? 0 : s[j - 1]))
			{
				mx = min(mx, dp[x + 1][i] + x - i);
				x--;
			}
			dp[i][j] = mx;
		}
	}
	cout << dp[1][0] << "\n";
	return 0;
}