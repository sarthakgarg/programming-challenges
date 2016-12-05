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
#define	foreach( gg,itit )	for( auto itit=gg.begin();itit!=gg.end();itit++ )
#define	mp make_pair
#define	pb push_back
#define sz(a) int((a).size())
#define	debug(ccc)	cout << #ccc << " = " << ccc << endl;
#define present(c,x) ((c).find(x) != (c).end())
const int mod = 1e9 + 7;
#define INF 1e18
ll n, k, p, q, s, t, fin[2], dp[5003][5003];
bool done[5003][5003];
vector<ll> arr;
vector<ll> diff;
ll max(ll a, ll b) {
	if (a > b) return a;
	else return b;
}
ll find(ll fs, ll ft) {
	ll pos = fs * s + ft * t + fs + ft;
	pos--;
	if (fs == fin[0] && ft == fin[1]) {if (pos == (n - 2))return diff[n - 2]; else return 0;}
	if (done[fs][ft] == true) return dp[fs][ft];
	done[fs][ft] = true;
	int ans = 0, mx = -1;
	if (pos != -1) ans += diff[pos];
	if (fs != fin[0]) mx = max(mx, find(fs + 1, ft));
	if (ft != fin[1]) mx = max(mx, find(fs, ft + 1));
	return dp[fs][ft] = mx + ans;
}
int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	cin >> n >> k;
	REP(i, n) {cin >> p; arr.pb(p);}
	sort(arr.begin(), arr.end());
	REPP(i, 1, k + 1) fin[(n - i) / k  - (n - k) / k]++;
	int q = 0;
	foreach (arr, it) {
		if (it + 1 != arr.end()) {
			diff.pb(*(it + 1) - *it);
			q += *(it + 1) - *it;
		}
	}
	s = (n - k) / k;
	t = (n - 1) / k;
	cout << q - find(0, 0) << "\n";
	return 0;
}