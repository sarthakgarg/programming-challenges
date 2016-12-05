#include<stdio.h>
#include"iostream"
using namespace std;
typedef long long ll;
#define N 2002
ll x1, x2, y1, y2, dist1[N], dist2[N], p, q, ans, n, mn = 1000000000000000000;
int main(){
	cin >> n >> x1 >> y1 >> x2 >> y2;
	for(int i = 0; i < n; i++){
		cin >> p >> q;
		dist1[i + 1] = (x1 - p) * (x1 - p) + (y1 - q) * (y1 - q);
		dist2[i + 1] = (x2 - p) * (x2 - p) + (y2 - q) * (y2 - q);
	}
	for(int i = 0; i <= n; i++){
		ll r12 = dist1[i], r22 = 0;
		for(int j = 1; j <= n; j++){
			if(dist1[j] > r12) r22 = max(r22, dist2[j]);  
		}
		mn = min(mn, r12 + r22);
	}
	cout << mn << "\n";
	return 0;
}