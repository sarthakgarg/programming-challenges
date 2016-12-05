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
ll n, h, p, q, s, t, x, y, mx, arr[100009], tmin[100005];
stack<ii> st;
int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	cin >> n;
	REPP(i, 1, n + 1)tmin[i] = INF;
	REPP(i, 1, n + 1)cin >> arr[i];
	for (ll j = n + 1; j >= 0; j--) {
		if (j == n + 1) mx = INF;
		else mx = st.top().Y;
		st.push(ii(arr[j] + j, min(mx, arr[j] + j)));
	}
	ll pos = 0;
	while (!st.empty()) {
		tmin[pos] = min(tmin[pos], st.top().X);
		tmin[pos] = min(tmin[pos], st.top().Y - pos);
		pos++;
		st.pop();
	}
	ll lt = 1, rt = n;
	while (lt < rt) {
		swap(arr[lt], arr[rt]);
		swap(tmin[lt], tmin[rt]);
		lt++;
		rt--;
	}
	for (ll j = n + 1; j >= 0; j--) {
		if (j == n + 1) mx = INF;
		else mx = st.top().Y;
		st.push(ii(arr[j] + j, min(mx, arr[j] + j)));
	}
	pos = 0;
	while (!st.empty()) {
		tmin[pos] = min(tmin[pos], st.top().X);
		tmin[pos] = min(tmin[pos], st.top().Y - pos);
		pos++;
		st.pop();
	}
	ll ans = -1;
	REPP(i, 1, n + 1) ans = max(ans, tmin[i]);
	cout << ans << "\n";
	return 0;
}