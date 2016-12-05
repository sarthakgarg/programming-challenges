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
//#include<unordered_map>
//#include<unordered_set>
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

vector<int> adj[50006];
int visited[50006];

ll dfs(int v, int k, int start) {
	visited[v] = start;
	if (k == 0) return 1;
	ll sum = 0;
	foreach (adj[v], it) {
		if (visited[*it] != start) {
			sum += dfs(*it, k - 1, start);
		}
	}
	return sum;
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int n, k, p, q, r, s;
	ll sum = 0;
	cin >> n >> k;
	REP(i, n - 1) {
		cin >> p >> q;
		adj[p].push_back(q);
		adj[q].push_back(p);
	}
	REP(i, n) sum += dfs(i + 1, k, i + 1);
	cout << sum / 2 << "\n";
	return 0;


}
