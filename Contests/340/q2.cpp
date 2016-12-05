#include<stdio.h>
#include"iostream"
using namespace std;
typedef long long ll;

int main(){
	ll n, ans = 1, x, prevpos = -1;
	cin >> n;
	for(int i = 0; i < n; i++){
		cin >> x;
		if(x == 1){
			if(prevpos != -1) ans *= (i - prevpos);
			prevpos = i;
		}
	}
	if(prevpos == -1) cout << "0\n";
	else cout << ans << "\n";
	return 0;

}