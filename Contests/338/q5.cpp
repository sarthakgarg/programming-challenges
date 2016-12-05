#include<stdio.h>
#include"iostream"
using namespace std;
typedef long long ll;
ll n, m, ct, x, y, k, p;
int main(){
	cin >> n;
	ll lo = 0, hi = 1000000000;
	while(lo < hi){
		ll mid = lo + (hi - lo + 1) / 2;
		if(3 * mid * mid + 3 * mid <= n){
			lo = mid;
		}
		else hi = mid - 1;
	}
	n -= (3 * lo * lo + 3 * lo);
	x += 2 * lo;
	lo++;
	if(n > 0){
		n--;
		x++;
		y += 2;
	} 
	if(n - (lo - 1) < 0){
		x -= n;
		y += 2*n;
		n = 0;
	}
	else {
		n -= (lo - 1);
		x -= (lo - 1);
		y += 2*(lo - 1);
	}
	if(n - lo < 0){
		x -= 2*n;
		n = 0;
	}
	else {
		n -= lo;
		x -= 2*lo;
	}
	
	if(n - lo < 0){
		x -= n;
		y -= 2*n;
		n = 0;
	}
	else {
		n -= lo;
		x -= lo;
		y -= 2*lo;
	}
	
	if(n - lo < 0){
		x += n;
		y -= 2*n;
		n = 0;
	}
	else {
		n -= lo;
		x += lo;
		y -= 2*lo;
	}
	
	if(n - lo < 0){
		x += 2*n;
		n = 0;
	}
	else {
		n -= lo;
		x += 2*lo;
	}
	
	if(n - lo < 0){
		x += n;
		y += 2*n;
		n = 0;
	}
	else {
		n -= lo;
		x += lo;
		y += 2*lo;
	}
	cout << x << " " << y << "\n";
	return 0;
}