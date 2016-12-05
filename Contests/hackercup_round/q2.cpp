#include<stdio.h>
#include"iostream"
#include<math.h>
#define N 3002
using namespace std;
typedef long long ll;
int t, n, k;
double x, y, z, p, a, b, pro[N][N], dp[N]; 
int main(){
	cin >> t;
	for(int m = 1; m <= t; m++){
		cin >> n >> k >> p;
		pro[0][0] = 1;
		for(int i = 1; i < n + 1; i++){
			pro[i][0] = (1 - p) * pro[i - 1][0];
			for(int j = 1; j < i + 1; j++){
				pro[i][j] = p * pro[i - 1][j - 1] + (1 - p) * pro[i - 1][j];
			}
			pro[i][i + 1] = 0;
		}
		for(int i = 1; i < n + 1; i++){
			for(int j = i; j > k - 1; j--){
				pro[i][j] += pro[i][j + 1];
			}
		}
		for(int i = 1; i < n + 1; i++){
			for(int j = 1; j < i + 1; j++){
				dp[i] = max(dp[i], dp[i - j] + pro[j][k]);
			}
		}
		printf("Case #%d: %.9lf\n", m, dp[n]);
		for(int i = 0; i < n + 1 ; i++) dp[i] = 0;
	}
}