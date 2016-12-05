#include <stdio.h>
#include "iostream"
#define X first
#define Y second
using namespace std;
typedef long long ll;
ll c, m, A, cm, cf, ans, arr[1000005], sum[1000005], rsum[1000005], n;
int binsearch(int x, int lo, int hi){
	int mid;
	while(lo < hi){
		int mid = lo + (hi - lo + 1) / 2;
		if(1LL * arr[mid] * mid - sum[mid] < 0) hi = mid - 1;
		else lo = mid;
	}
	return lo;
}
int main(){
	cin >> n >> A >> cf >> cm >> m;
	for(int i = 1; i <= n; i++) cin >> arr[i];
	sort(arr + 1, arr + n + 1);
	ans = 0;
	for(int i = 1; i <= n; i++){
		if(i == 1) sum[i] = arr[i];
		else sum[i] = arr[i] + sum[i - 1];
	}
	for(int i = n; i > 0; i--){
		if(i == n) rsum[i] = arr[i];
		else rsum[i] = rsum[i + 1] + arr[i];
	}
	for(int i = n + 1; i > 1; i--){
		ll temp = 0;
		ll cost = 0;
		ll mininc = m;
		ll offset = 0;
		ll mincount;
		cost = (n - i + 1) * A - rsum[i];
		if(cost <= m){
			temp = 1LL * cf * (n - i + 1);
			mininc -= cost;
		}
		mincount = binsearch(mininc, 1, i - 1);
		if(mincount == i - 1){
			mininc -= (sum[mincount] - mincount * arr[mincount]);
			offset += mininc / mincount;
			if(arr[mincount] + offset > A){
				offset = A - arr[mincount];
			}
		}
		temp += (arr[mincount] + offset) * cm;
		cout << n - i + 1 << " " << (arr[mincount] + offset) << "\n";
		ans = max(ans, temp);
	}
	cout << ans << "\n";
	return 0;
}
	
	
	