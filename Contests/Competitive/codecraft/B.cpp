#include<stdio.h>
#include"iostream"
#include<vector>
#include<map>
#define N 5002
using namespace std;
typedef long long ll;
int n, m, k, r[N], c[N], x, y, rp[N], cp[N]; 
int main(){
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	cin >> n >> m >> k;
	for(int i = 1; i <= k; i++){
		int type;
		cin >> type >> x >> y;
		if(type == 1){
			r[x] = y;
			rp[x] = i;
		}
		else {
			c[x] = y;
			cp[x] = i;
		}
	}
	for(int i = 1; i <= n; i++){
		for(int j = 1; j <= m; j++){
			if(rp[i] < cp[j]) cout << c[j] << " ";
			else cout << r[i] << " ";
		}
		cout << "\n";
	}
	return 0;
}