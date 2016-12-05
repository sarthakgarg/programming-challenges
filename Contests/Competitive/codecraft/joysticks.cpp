#include<stdio.h>
#include"iostream"
using namespace std;
int main(){
	int a, b, ans = 0;
	cin >> a >> b;
	while(1){
		if(a == 1 && b == 1 || a == 0 || b == 0) break;
		if(a > b){
			b++;
			a -= 2;
		} 
		else{
			a++;
			b -= 2;
		}
		ans++;
	}
	cout << ans << "\n";
	return 0;
}