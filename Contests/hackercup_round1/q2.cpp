#include <stdio.h>
#include "iostream"
#include <queue>
#define N 1000005
#define X first
#define Y second
using namespace std;
typedef long long ll;
typedef pair<ll, ll> ii;
priority_queue<ii, vector<ii>, greater<ii> > washing;
vector<ll> dryer;
ll t, l, m, n, x, z, ans, d, k;
ii y;
int main(){
	cin >> t;
	for(int k = 1; k <= t; k++){
		cin >> l >> n >> m >> d;
		for(int i = 0; i < n; i++){
			cin >> x;
			washing.push(ii(x, x));
		}
		for(int i = 0; i < l; i++){
			y = washing.top();
			dryer.push_back(y.X);
			washing.pop();
			washing.push(ii(y.X + y.Y, y.Y));
		}
		ll sz = dryer.size();
		if(m >= l) ans = dryer[sz - 1] + d;
		else {
			for(int i = 0; i < sz; i++){
				dryer[i] = max(dryer[i], (i - m >= 0) ? (dryer[i - m]) : 0) + d;
			}
			ans = dryer[sz - 1];
		}
		cout << "Case #" << k << ": " << ans << "\n";
		dryer.clear();
		while(!washing.empty()) washing.pop();
	}
	return 0;
}