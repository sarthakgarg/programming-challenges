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
#include<unordered_map>
//#include<unordered_set>
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
unordered_map<int, ll> adj[50006];
unordered_map<int, ll> newadj[50006];
ll sum[50006], newsum[50006];
int main() {
	int n, k, p, q, r, s;
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	cin >> n >> k;
	REP(i, n - 1) {
		cin >> p >> q;
		adj[p][q] = 1;
		adj[q][p] = 1;
	}
	REPP(i, 1, n + 1) {
		s = 0;
		foreach (adj[i], it) {
			s += it->Y;
		}
		sum[i] = s;
	}
	REP(i, k - 1) {
		REPP(i, 1, n + 1) {
			newsum[i] = 0;
			foreach (adj[i], it) {
				p = it->X;
				s = sum[p] - (adj[p][i]);
				newadj[i][p] = s;
				newsum[i] += s ;
			}
		}
		REPP(i, 1, n + 1) {
			sum[i] = newsum[i];
			foreach (adj[i], it) {
				p = it->X;       
				it->Y = newadj[i][p];
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