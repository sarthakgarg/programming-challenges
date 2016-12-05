#include<bits/stdc++.h>
using namespace std;
typedef pair<int, int> ii;
#define X first
#define Y second
#define REP(i,a) for(int i=0;i<a;++i)
#define REPP(i,a,b) for(int i=a;i<b;++i)
#define FILL(a,x) memset(a,x,sizeof(a))
#define	foreach( gg,itit )	for( auto itit=gg.begin();itit!=gg.end();itit++ )
#define	pb push_back
const int mod = 1e9 + 7;
vector<int> adj[500003], bit[500006];
vector<ii> levels[500005];
int  h_mx, n, m, h, v, x, y, tim, s[500006], f[500006], he[500006], l, r, p;
void dfs(int v, int h) {
	tim++;
	he[v] = h;
	h_mx = max(h_mx, h);
	s[v] = tim;
	levels[h].pb(ii(tim, v));
	foreach(adj[v], it) {dfs(*it, h + 1);}
	f[v] = tim;
	return;
}
char str[500005];
int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	cin >> n >> m;
	REPP(i, 2, n + 1) {cin >> x; adj[x].pb(i);}
	cin >> str;
	dfs(1, 1);
	REPP(i, 1, h_mx + 1) {
		x = 0;
		foreach(levels[i], it) {x = x ^ (1 << (str[it->Y - 1] - 'a')); bit[i].pb(x);}
	}
	REP(i, m) {
		cin >> x >> y;
		if (y < he[x] || y > h_mx) {
			cout << "Yes\n"; continue;
		}
		l = s[x]; r = f[x];
		auto it1 = lower_bound(levels[y].begin(), levels[y].end(), ii(l, -1));
		auto it2 = lower_bound(levels[y].begin(), levels[y].end(), ii(r, -2));
		if (it1 == levels[y].end()) {cout << "Yes\n"; continue;}
		if (it2 == levels[y].begin() && (it2->X > r)) {cout << "Yes\n"; continue;}
		if (it2 == levels[y].end() || (it2->X) > r) it2--;
		l = it1 - levels[y].begin(); r = it2 - levels[y].begin();
		p = bit[y][r] ^ ((l > 0) ? (bit[y][l - 1]) : (0));
		if ((r - l + 1) % 2 == 1) {if ((p != 0) && ((p - (p & -p)) == 0)) {cout << "Yes\n"; continue;}}
		else {if (p == 0) {cout << "Yes\n"; continue;}}
		cout << "No\n";
	}
	return 0;
}