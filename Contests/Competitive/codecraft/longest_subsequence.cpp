#include<stdio.h>
#include"iostream"
#define N 1000004
using namespace std;
typedef long long ll;

ll sv[N], arr[N], f[N], x, y, z, k, n, m, l;
int main(){
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	cin >> n >> m;
	for(int i = 0; i < n; i++){
		cin >> arr[i];
		if(arr[i] < N) f[arr[i]]++;
	}
	for(int i = 0; i < N; i++){
		if(f[i] != 0){
			for(int j = i; j < N; j += i){
				sv[j] += f[i];
			}
		}
	}
	l = 1;
	for(int i = 1; i <= m; i++){
	 	if(sv[i] > k){
	 		k = sv[i];
			l = i;
	 	}
	}
	cout << l << " " << k << "\n";
	for(int i = 0; i < n; i++){
		if(l % arr[i] == 0) cout << i + 1 << " ";
	} 
	cout << "\n";
	return 0;
}