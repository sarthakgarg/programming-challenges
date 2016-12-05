#include<stdio.h>
#include"iostream"
#define N 160
#define INF 1000000000000000007
#define MOD 1000000007
#define NU 10000008
using namespace std;
typedef long long ll;
ll w[N][N], dp[N][N], ct[N][N], a[N][N], b[N][N], x, y, z, p, n, m, k;

void mul(){
	for(int i = 1; i <= n; i++){
		for(int j = 1; j <= n; j++){
			a[i][j] = INF;
			for(int k = 1; k <= n; k++){
				a[i][j] = min(a[i][j], (w[k][j] != NU) ? (dp[i][k] + w[k][j]) : INF);
			}
			b[i][j] = 0;
			if(a[i][j] != INF){
				for(int k = 1; k <= n; k++){
					if(a[i][j] == dp[i][k] + w[k][j]){
						b[i][j] = (b[i][j] + ct[i][k]) % MOD;
					}
				}
			}
		}
	}
	for(int i = 1; i <= n; i++) for(int j = 1; j <= n; j++){
		dp[i][j] = a[i][j];
		ct[i][j] = b[i][j];
	}
}


void sq(){
	for(int i = 1; i <= n; i++){
		for(int j = 1; j <= n; j++){
			a[i][j] = INF;
			for(int k = 1; k <= n; k++){
				a[i][j] = min(a[i][j], (dp[k][j] != INF && dp[i][k] != INF) ? (dp[i][k] + dp[k][j]) : INF);
			}
			b[i][j] = 0;
			if(a[i][j] != INF){
				for(int k = 1; k <= n; k++){
					if(a[i][j] == dp[i][k] + dp[k][j]){
						b[i][j] = (b[i][j] + ct[i][k] * ct[k][j]) % MOD;
					}
				}
			}
		}
	}
	for(int i = 1; i <= n; i++) for(int j = 1; j <= n; j++){
		dp[i][j] = a[i][j];
		ct[i][j] = b[i][j];
	}
}

void expo(ll p){
	if(p == 0){
		for(int i = 1; i <= n; i++)
			for(int j = 1; j <= n; j++)
				if(i == j){
					ct[i][i] = 1;
					dp[i][i] = 0;
				}
				else dp[i][j] = INF;
				return;
	}
	expo(p / 2);
	sq();
	if(p % 2 == 1) mul();
	return;
}

int main(){
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	cin >> n >> m >> k;
	for(int i = 0; i <= n; i++) for(int j = 0; j <= n; j++) w[i][j] = NU;
	for(int i = 0; i < m; i++){
		cin >> x >> y >> z;
		w[x][y] = w[y][x] = z;
	}
	expo(k);
	for(int i = 1; i <= n; i++){
		for(int j = 1; j <= n; j++){
			if(dp[i][j] == INF) cout << "X 0 ";
			else cout << dp[i][j] << " " << ct[i][j] << " ";
		}
		cout << "\n";
	}
	return 0;
}