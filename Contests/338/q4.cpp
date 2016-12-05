#include<stdio.h>
#include"iostream"
#define N 200004
#define mod 1000000007
using namespace std;
typedef long long ll;
ll frq[N], n, m, divn = 1, pro = 1;
ll modexp(ll base, ll power){
	if(power == 0) return 1;
	ll x = modexp(base, power / 2);
	x = (x * x) % mod;
	if(power % 2 == 1) x = (x * base) % mod;
	return x;
}
int main(){
	cin >> m;
	while(m--){
		cin >> n;
		frq[n]++;
	}
	for(ll i = 2; i < N; i++){
		if(frq[i] == 0) continue;
		pro = modexp(pro, (frq[i] + 1));
		ll powr = frq[i] * (frq[i] + 1) / 2;
		powr = (powr * divn) % (mod - 1);
		ll temp = modexp(i, powr);
		pro = (pro * temp) % mod;
		divn = (divn * (frq[i] + 1)) % (mod - 1); 
	}
	cout << pro << "\n";
	return 0;
}