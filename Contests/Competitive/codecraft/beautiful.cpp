#include<stdio.h>
#include"iostream"
#include<algorithm>
#define N 1003
using namespace std;
typedef long long ll;
ll a[N], x, y, n, an, p;
int main(){
	cin >> n;
	for(int i = 0; i < n; i++) cin >> a[i];
	sort(a, a + n);
	for(int i = 1; i < n; i++){
		int p = i;
		while(1){
			if(p == 0) break;
			int s = p;
			int t = p - 1;
			int x = ((s < n - 1 && a[s] < a[s + 1]) ? 1 : 0) + ((s > 0 && a[s - 1] < a[s]) ? 1 : 0);
			x += (t > 0 && a[t - 1] < a[t]) ? 1 : 0;
			swap(a[s], a[t]);
			int y = ((s < n - 1 && a[s] < a[s + 1]) ? 1 : 0) + ((s > 0 && a[s - 1] < a[s]) ? 1 : 0);
			y += (t > 0 && a[t - 1] < a[t]) ? 1 : 0;
			if(y < x || y == x && a[s] >= a[t]){
				swap(a[s], a[t]);
				break;
			}
			p--;
		}
	}
	for(int i = 0; i < n; i++) cout << a[i] << " ";
	cout << "\n";
	for(int i = 0; i < n - 1; i++) if(a[i] < a[i + 1]) an++;
	cout << an << "\n";
	return 0;
}