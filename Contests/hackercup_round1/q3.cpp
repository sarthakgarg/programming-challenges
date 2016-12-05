#include <stdio.h>
#include "iostream"
#define N 100005
#define eps 1e-12
using namespace std;
typedef long long ll;
double a, b, x, y, z, k, p, sn[N], s, ans;
ll n, t, q, r, k1, k2;
double IN(double l, double r, double add){
	if(l > r) return 0;
	double temp = (r * r - l * l) / 2 + add * (r - l);
	temp /= (b - a);
	return temp;
}

int main(){
	cin >> t;
	for(int m = 1; m <= t; m++){
		cin >> n >> a >> b;
		ans = 0;
		s = 0;
		for(int i = 0; i < n; i++){
			cin >> x;
			s += x;
			sn[i + 1] = s;
		}
		for(int i = 0; i < n; i++){
			if(sn[i] > a) k1 = 0;
			else k1 = (int)((a - sn[i]) / s);
			ans -= IN(k1 * s + sn[i], min(a, k1 * s + sn[i + 1]), -sn[i] - (k1 * s));
			if(sn[i + 1] > b) k2 = 0;
			else k2 = (int)((b - sn[i + 1]) / s) + 1;
			ans -= IN(max(b, sn[i] + k2 * s), k2 * s + sn[i + 1], -sn[i] - (k2 * s));
			ans += (k2 - k1 + 1) * IN(sn[i], sn[i + 1], -sn[i]);
		}
		printf("Case #%d: %.15lf\n", m, ans);
	}
	return 0;
}
