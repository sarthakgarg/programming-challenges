#include<stdio.h>
#include"iostream"
using namespace std;
typedef long long ll;
int v[103];
int main(){
	int n, m, y, x;
	cin >> n >> m;
	while(n--){
		cin >> x;
		while(x--){
			cin >> y;
			v[y] = 1;
		}
	}
	for(int i = 1; i <= m; i++){
		if(v[i] == 0){
			cout <<"NO\n";
			return 0;
		}
	}
	cout << "YES\n";
	return 0;
}