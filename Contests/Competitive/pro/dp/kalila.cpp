// This is a standard code of the convex hull trick that gives the min value of the linear functions 
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
typedef pair<ii, double> inv;
#define X first
#define Y second
#define REP(i,a) for(int i=0;i<a;++i)
#define REPP(i,a,b) for(int i=a;i<b;++i)
const int mod = 1e9 + 7;
#define INF 1e18+7
const int MaxN = 100000;
ll m[MaxN + 2], n, k, p, q, r, s, t, x[MaxN + 2];
inv st[MaxN + 2];

void add(ll b, ll m) {
	while (s > 1 && (b - st[s - 2].X.Y) / (st[s - 2].X.X - m) <= (st[s - 2].X.Y - st[s - 1].X.Y) / (st[s - 1].X.X - st[s - 2].X.X)) s--;
	st[s] = inv(ii(m, b), (s > 0) ? ((double)(b - st[s - 1].X.Y) / (st[s - 1].X.X - m)) : -INF);
	s++;
}

ll query(ll x) {
	ll lo = 0, hi = s - 1, mid;
	while (lo < hi) {
		ll mid = lo + (hi - lo + 1) / 2;
		if (st[mid].Y > x) hi = mid - 1;
		else lo = mid;
	}
	return x * st[lo].X.X + st[lo].X.Y;;
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	cin >> n;
	REP(i, n)cin >> x[i];
	REP(i, n)cin >> m[i];
	add(0, m[0]);
	REPP(i, 1, n) {
		p = query(x[i]);
		add(p, m[i]);
	}
	cout << p << "\n";
	return 0;
}