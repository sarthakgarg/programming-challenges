#include<bits/stdc++.h>
using namespace std;
int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int t, a, b;
	cin >> t;
	while (t--) {
		int ans = 0;
		cin >> a >> b;
		while (a > b || (a & (a - 1)) != 0) {a /= 2; ans++;}
		while (a < b) {a *= 2; ans++;}
		cout << ans << "\n";
	}
	return 0;
}
-