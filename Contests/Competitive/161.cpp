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
#include<stack>
#include<queue>
#include<deque>
using namespace std;
typedef long long ll;
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
vector<int> adj[50006];
ll ways[50006][2], nways[50006][2];
ll sum[50006], newsum[50006];
int parent[50006], visited[50006];
void dfs(int v) {
	visited[v] = 1;
	foreach (adj[v], it) {
		if (visited[*it] == 0) {
			dfs(*it);
		}
		else parent[v] = *it;
	}
}
void update(int src, int dest, int val, int flag) {
	if (flag == 0) {
		if (parent[src] == dest) ways[src][0] = val;
		else ways[dest][1] = val;
	}
	else {
		if (parent[src] == dest) nways[src][0] = val;
		else nways[dest][1] = val;
	}
}
ll query(int src, int dest, int flag) {
	if (flag == 0) {
		if (parent[src] == dest) return ways[src][0];
		else return ways[dest][1];
	}
	else {
		if (parent[src] == dest) return nways[src][0];
		else return nways[dest][1];
	}
}
int main() {
	int n, k, p, q, r;
	ll s;
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	cin >> n >> k;
	REP(i, n - 1) {
		cin >> p >> q;
		adj[p].push_back(q);
		adj[q].push_back(p);
	}
	parent[1] = 0;
	dfs(1);
	REPP(i, 1, n + 1) {
		foreach(adj[i], it) update(i, *it, 1, 0);
	}
	REPP(i, 1, n + 1) {
		s = 0;
		foreach (adj[i], it) {
			s += query(i, *it, 0);
		}
		sum[i] = s;
	}
	REP(j, k - 1) {
		REPP(i, 1, n + 1) {
			newsum[i] = 0;
			foreach (adj[i], it) {
				p = *it;
				s = sum[p] - (query(p, i, 0));
				update(i, p, s, 1);
				newsum[i] += s ;
			}
		}
		REPP(i, 1, n + 1) {
			sum[i] = newsum[i];
			foreach (adj[i], it) {
				p = *it;
				update(i, p, query(i, p, 1), 0);
			}
		}
	}
	s = 0;
	REPP(i, 1, n + 1) {
		s += sum[i];
	}
	cout << s / 2 << "\n";
	return 0;
}