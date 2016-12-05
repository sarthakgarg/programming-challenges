#include<bits/stdc++.h>
using namespace std;
#define REP(i,a) for(int i=0;i<a;++i)
#define REPP(i,a,b) for(int i=a;i<b;++i)
#define FILL(a,x) memset(a,x,sizeof(a))
const int mod = 1e9 + 7;
int ct = 0;
int modk[1005], modm[1005];
int dp[1004][104], n, m, k;
int modexp(int base, int power, int a) {
	if (!power) return 1 % a;
	int x = modexp(base, power / 2, a);
	x = (1LL * x * x) % a;
	if (power % 2)x = (1LL * x * base) % a;
	return x;
}
int find(int n, int rem) {
	if (n == 0) {if (rem == 0)return 1; else return 0;}
	if (dp[n][rem] != -1) return dp[n][rem];
	int ans = 0;
	REPP(i, 1, 10) {
		int modulo = modk[n - 1];
		modulo = (1LL * modulo * i) % k;
		modulo = (rem - modulo + k) % k;
		if (modulo == 0) ans += find(0, modulo);
		else
			ans += find(n - 1, modulo); ans = ans % m;
	}
	return dp[n][rem] = (ans + ((n == 1) ? 0 : find(n - 1, rem))) % m;
}
int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	cin >> n >> k >> m;
	if (m == 1) {cout << "0\n"; return 0;}
	modk[0] = 1 % k; modm[0] = 1 % m;
	REPP(i, 1, 1005) {modk[i] = (1LL * modk[i - 1] * 10) % k; modm[i] = (1LL * modm[i - 1] * 10) % m;}
	FILL(dp, -1);
	int sum = 0;
	int a;
	for (int i = n; i > 0; i--) {a = (1LL * (find(i, 0) - ((i == 1) ? 0 : find(i - 1, 0))) * modm[max(0, n - i - 1)]) % m; if (i != n)a = (1LL * a * 9) % m; sum = (sum + a) % m;}
	cout << sum << "\n";
	return 0;
}