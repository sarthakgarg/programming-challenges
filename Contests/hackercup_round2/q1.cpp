#include<stdio.h>
#include"iostream"
#define N 50004
using namespace std;
typedef long long ll;
int n, arr[N], lo, hi, mid, x, y, t, stlo, sthi;
int main(){
	cin >> t;
	for(int m = 1; m <= t; m++){
		cin >> n;
		for(int i = 0; i < n; i++){
			cin >> arr[i];
		}
		lo = -1;
		hi = -1;
		int flag = 0;
		stlo = 0;
		sthi = n - 1;
		while(stlo < sthi){
			if(lo == -1){
				lo = arr[stlo];
				hi = arr[stlo];
				stlo++;
			}
			else{
				if(arr[stlo] == lo - 1){
					stlo++;
					lo--;
				}
				else if(arr[stlo] == hi + 1){
					stlo++;
					hi++;
				}
				else if(arr[sthi] == lo - 1){
					sthi--;
					lo--;
				}
				else if(arr[sthi] == hi + 1){
					sthi--;
					hi++;
				}
				else {
					flag = 1;
					break;
				}
			}
		}
		if(flag == 0) cout << "Case #" << m << ":" << " yes\n";
		else {
			lo = -1;
			hi = -1;
			int flag = 0;
			stlo = 0;
			sthi = n - 1;
			while(stlo < sthi){
				if(lo == -1){
					lo = arr[sthi];
					hi = arr[sthi];
					sthi--;
				}
				else{
					if(arr[stlo] == lo - 1){
						stlo++;
						lo--;
					}
					else if(arr[stlo] == hi + 1){
						stlo++;
						hi++;
					}
					else if(arr[sthi] == lo - 1){
						sthi--;
						lo--;
					}
					else if(arr[sthi] == hi + 1){
						sthi--;
						hi++;
					}
					else {
						flag = 1;
						break;
					}
				}
			}
		if(flag == 0) cout << "Case #" << m << ":" << " yes\n";
		else cout << "Case #" << m << ":" << " no\n";	
		}
	}
	return 0;
}