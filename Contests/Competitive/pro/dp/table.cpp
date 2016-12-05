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
ll modexp(ll a, ll pow, ll mod) {
	if (pow == 0) return 1;
	ll x = modexp(a, pow / 2, mod);
	x = (x * x) % mod;
	if (pow % 2) x = (x * a) % mod;
	return x;
}
ll n, m, k, p, q, r, s, t, x, y, fact[102], mult[102][3], dp[102][10009];
bool done[102][10009];
ll find(ll in, ll k) {
	ll mu;
	if (in == -1) {if (k == 0) return 1; else return 0;}
	if (done[in][k] == true) return dp[in][k];
	done[in][k] = true;
	REP(i, 1 + min(k, n)) {
		if ((m - in - 1) / n + 1 == m / n + 1) mu = mult[i][1];
		else mu = mult[i][0];
		dp[in][k] = (dp[in][k] + mu * find(in - 1, k - i)) % mod;
	}
	return dp[in][k];
}
int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	cin >> n >> m >> k;
	fact[0] = 1;
	p = m / n + 1 ;
	q = m / n;
	REPP(i, 1, 101) fact[i] = (i * fact[i - 1]) % mod;
	REP(i, n + 1) {
		t = ((((fact[n] * modexp(fact[n - i], mod - 2, mod)) % mod) * modexp(fact[i], mod - 2, mod)) % mod);
		mult[i][1] = modexp(t, m / n + 1, mod);
		mult[i][0] = modexp(t, m / n, mod);
	}
	cout << find(n - 1, k) << "\n";
	return 0;
}