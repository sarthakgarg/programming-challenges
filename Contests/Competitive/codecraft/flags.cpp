#include<stdio.h>
#include"iostream"
#define N 8
#define mod 1000000007
using namespace std;
typedef long long ll;
ll a[N][N], b[N][N], c[N][N], d[N][N], e[N][N];
int n, m, k, p, q;
void mu(int sgn){
	for(int i = 0; i < n; i++){
		for(int j = 0; j < n; j++){
			ll sm = 0;
			for(int k = 0; k < n; k++) sm = (sm + a[i][k] * ((sgn == 1) ? (b[k][j]) : (a[k][j]))) % mod;
			c[i][j] = sm;
		}
	}
	for(int i = 0; i < n; i++) for(int j = 0; j < n; j++) a[i][j] = c[i][j];
}
void mi(){
	for(int i = 0; i < n; i++) a[i][i]++;
	for(int i = 0; i < n; i++){
		for(int j = 0; j < n; j++){
			ll sm = 0;
			for(int k = 0; k < n; k++) sm = (sm + a[i][k] * d[k][j]) % mod;
			c[i][j] = sm;
		}
	}
	for(int i = 0; i < n; i++) for(int j = 0; j < n; j++) d[i][j] = c[i][j];
}
void expo(ll k){
	if(k == 0){
		for(int i = 0; i < n; i++) for(int j = 0; j < n; j++) a[i][j] = (i == j) ? (1) : (0);
		return;
	}
	expo(k / 2);
	mu(0);
	if(k % 2 == 1) mu(1);
}
void exposum(ll k){
	if(k == 0){
		for(int i = 0; i < n; i++) for(int j = 0; j < n; j++) d[i][j] = (i == j) ? (1) : (0);
		return;
	}
	exposum(k / 2);
	expo(k / 2 + 1);
	mi();
	if(k % 2 == 0){
		expo(k + 1);
		for(int i = 0; i < n; i++) for(int j = 0; j < n; j++) d[i][j] = ((d[i][j] - a[i][j]) % mod + mod) % mod;
	}
}
ll modexp(ll base, ll power){
	if(power == 0) return 1;
	ll x = modexp(base, power / 2);
	x = (x * x) % mod;
	if(power % 2 == 1) x = (x * base) % mod;
	return x;
}
int main(){
	cin >> p >> q;
	n = 8;
	b[0][1] = 1;
	b[0][2] = 1;
	b[0][3] = 1;
	b[0][4] = 1;
	b[1][4] = 1;
	b[1][5] = 1;
	b[2][1] = 1;
	b[2][3] = 1;
	b[3][4] = 1;
	b[3][6] = 1;
	b[4][1] = 1;
	b[4][3] = 1;
	b[5][1] = 1;
	b[6][3] = 1;
	b[1][7] = 2;
	b[2][7] = 2;
	b[3][7] = 2;
	b[4][7] = 2;
	b[5][7] = 3;
	b[6][7] = 3;
	b[7][7] = 4;
	exposum(q);
	for(int i = 0; i < n; i++) for(int j = 0; j < n; j++) e[i][j] = d[i][j];
	exposum(p - 1);
	ll ans = 0;
	for(int i = 0; i < n - 1; i++) ans += e[0][i] - d[0][i];
	ans = (ans % mod + mod) % mod;
	ans = (ans * modexp(2, mod - 2)) % mod;
	cout << ans << "\n";
	return 0;
}
