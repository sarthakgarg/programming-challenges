/* Longest increasing subsequence O(nlogn) time,
Usage.
Input : Array a[] from 0 to n-1 of a sequence of positive integers.
MAXV stores the maximum value in the sequence.
The arrays parent[] and index[] are used for tracking and printing the lis.
dp[] 0 to n dp[i] stores the minimum ending value of an increasing sequence of length i
Output : Array res[] from 0 to n-1. res[i] stores the length of the longest increasing subsequence strictly ending at the index i
*/
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
#define INF 1e9
const int MAXN = 100000, MAXV = 1000000007;
int res[MAXN + 1], a[MAXN + 1], dp[MAXN + 2], n, ind[MAXN + 2], parent[MAXN + 1], pos, mx;
void calc_lis() {
	REP(i, MAXN + 1) {
		dp[i] = MAXV;
		ind[i] = -1;
	}
	dp[0] = -1;
	for (int i = 0; i < n; ++i) {
		res[i] = (int) (upper_bound(dp, dp + n + 1, a[i]) - dp);
		parent[i] = ind[res[i] - 1];
		dp[res[i]] = a[i];
		ind[res[i]] = i;
	}
}
void print(int i) {
	if (parent[i] != -1) print(parent[i]);
	cout << a[i] << " ";
}
int main() {
	cin >> n;
	REP(i, n) cin >> a[i];
	calc_lis();
	REP(i, n) cout << res[i] << " ";
	cout << "\n";
	mx = -1;
	REP(i, n) {
		if (mx < res[i]) {
			mx = res[i];
			pos = i;
		}
	}
	print(pos);
	cout << "\n";
	return 0;
}