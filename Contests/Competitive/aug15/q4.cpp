#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll, ll> ii;
#define X first
#define Y second
#define	pb push_back
#define INF 1e18+7
vector<ii> lis;
int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	lis.pb(ii(1, 1)); lis.pb(ii(2, 2));
	ll b = 0;
	while (1) {
		ll a = lis[b].X + lis[b + 1].X;
		if (a > INF)break;
		lis.pb(ii(a, b + 3));
		b++;
	}
	ll t, n, x;
	cin >> t;
	while (t--) {
		cin >> n;
		auto it = lower_bound(lis.begin(), lis.end(), ii(n, -1));
		if (it == lis.begin())x = 1;
		else if (it == lis.end()) {it--; x = it->Y;}
		else if (n == it->X)x = it->Y;
		else {it--; x = it->Y;}
		cout << x << "\n";
	}
	return 0;
}
