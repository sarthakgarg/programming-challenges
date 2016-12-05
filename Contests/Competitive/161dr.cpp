// This is an order n*k solution to the problem 161 D
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
typedef pair<ll, ll> ii;
typedef pair<int, ii> edj;
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
vector<edj> adj[50006];
int visited[50006];
ll ct = 0;
ll dfs(int v, ll pred, int start) {
	cout << "hi\n";
	visited[v] = start;
	ll x, sum = 0;
	foreach (adj[v], it) {
		if (visited[it->X] != start) {
			x = dfs(it->X, it->Y.Y, start);
			it->Y.X = x;
			sum += x;
		}
		else it->Y.Y = pred;
	}
	return sum;
}
void count(int v, int start) {
	visited [v] = start;
	foreach (adj[v], it) {
		if (visited[it->X] != start) {
			ct += it->Y.X;
			ct += it->Y.Y;
			count(it->X, start);
		}
	}
}
int main() {
	int n, k, sum = 0, p, q, r, s;
//	ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
	cin >> n >> k;
	REP(i, n - 1) {
		cin >> p >> q;
		adj[p].push_back(edj(q, ii(1, 1)));
		adj[q].push_back(edj(p, ii(1, 1)));
	}
	REP(i, k - 1) {
		dfs(1, 0, i+1);
		p=i+1;
	}
	count(1,p+1);
	cout << ct/2 << "\n";
	return 0;
}