#include<stdio.h>
#include"iostream"
#define N 100005
using namespace std;
typedef long long ll;
ll last, ct, num, t, n, arr[N], m;
int main(){
	cin >> t;
	for(int m = 1; m <= t; m++){
		cin >> n;
		for(int i = 0; i < n; i++) cin >> arr[i];
		ct = 0;
		num = 0;
		for(int i = 0; i < n; i++){
			if(ct == 0) ct++;
			else {
				if(arr[i] <= arr[i - 1]){
					num += (4 - ct);
					ct = 1;
				}
				else{
					if(arr[i] > arr[i - 1] + (4 - ct) * 10){
						num += (4 - ct);
						ct = 1;
					}
					else{
						if(arr[i] <= arr[i - 1] + 10) ct = (ct + 1) % 4;
						else if(arr[i] <= arr[i - 1] + 20) {
							ct = (ct + 2) % 4;
							num++;
						}
						else {
							ct = (ct + 3) % 4;
							num += 2;
						}
					}
				}
			}
		}
		if(ct != 0) num += (4 - ct);
		cout << "Case #" << m << ": " << num << "\n";
	}
	return 0;
}