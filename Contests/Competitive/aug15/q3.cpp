#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define REP(i,a) for(int i=0;i<a;++i)
int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	ll t, n, l, h, sum, x, y, p;
	cin >> t;
	while (t--) {
		cin >> n >> p;
		sum = 0, x = -1;
		int arr[1000006] = {0};
		REP(i, n) {cin >> l >> h; arr[l]++; arr[h + 1]--;}
		REP(i, n) {sum += arr[i]; arr[i] = sum;}
		sum = 0;
		REP(i, p)sum += arr[i];
		REP(i, n - p + 1) {x = max(x, sum); sum += arr[i + p]; sum -= arr[i];}
		cout << p*n - x << "\n";
	}
	return 0;
}