#include<stdio.h>
#include"iostream"
using namespace std;
typedef long long ll;

int main(){
	int x;
	cin >> x;
	int ans = x / 5;
	if(x % 5 != 0) ans++;
	cout << ans << "\n";
	return 0;


}