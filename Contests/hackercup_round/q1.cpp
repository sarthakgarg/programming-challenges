#include<stdio.h>
#include"iostream"
#include <string.h>
#define N 100004
using namespace std;
typedef long long ll;
ll t, x, y, z, a, b, lft[N], rgt[N], lsum[N], rsum[N], n;
char A[N], B[N];
int main(){
	cin >> t;
	for(int m = 1; m <= t; m++){
		cin >> n >> A >> B;
//		n = strlen(A);
		y = -1;
		x = 0;
		for(int i = 0; i < n; i++){
			if(B[i] != y){
				y = B[i];
				x++;
			}
			if(A[i] == B[i]) lsum[i] = (i > 0) ? (lsum[i - 1]) : (0);
			else lsum[i] = x;
		}
		
		a = 0;
		b = n - 1;
		while(a < b){
			swap(A[a], A[b]);
			swap(B[a], B[b]);
			a++;
			b--;
		}
		
		y = -1;
		x = 0;
		for(int i = 0; i < n; i++){
			if(B[i] != y){
				y = B[i];
				x++;
			}
			if(A[i] == B[i]) rsum[i] = (i > 0) ? (rsum[i - 1]) : (0);
			else rsum[i] = x;
		}
/*		for(int i = 0; i < n; i++) cout << lsum[i] << " ";
		cout << "\n";
		for(int i = 0; i < n; i++) cout << rsum[i] << " ";
		cout << "\n";*/
		
		ll mx = -1;
		for(int i = 0; i < n; i++) mx = max(mx, min(lsum[i], rsum[n - 1 - i]));
		cout << "Case #" << m << ": " << mx << "\n";
	}
	return 0;
}