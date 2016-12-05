#include<stdio.h>
#include"iostream"
#include<unordered_map>
#include<set>
#include<cstdio>
#define N 160
#define K 100
#define MOD 1000000007
#define INF 100000000000000007
#define NO 100000007 
using namespace std;
typedef long long ll;

ll ct[N][N][K], dp[N][N][K];
int wc[N][N], x, y, w, p, q, n, m , k, imp[K];
set<int> in;
unordered_map<int, int> mp;


void add(int k){
	if(in.find(k) != in.end()) return;
	in.insert(k);
	add(k/2);
	if(k % 2 == 1) add(k/2 + 1);
}

int main(){
	ios_base::sync_with_stdio(false);cin.tie(NULL);
		cin >> n >> m >> k;
	for(int i = 0; i < N; i++) for(int j = 0; j < N; j++) wc[i][j] = NO;
	for(int i = 0; i < m; i++){
		cin >> x >> y >> w;
		wc[x][y] = w;
		wc[y][x] = w;
	}
	add(k);
	int cnt = 0;
	for(auto it = in.begin(); it != in.end(); it++){
		mp[*it] = cnt;
		imp[cnt++] = *it;
	}
	int lim = mp[k];
	for(int p = 0; p <= lim; p++){
		for(int i = 1; i <= n; i++){
			for(int j = 1; j <= n; j++){
				if(p == 0){
					if(i == j) ct[i][i][p] = 1;
					else dp[i][j][p] = INF;
				}
				else if(p == 1){
					if(wc[i][j] != NO){
						ct[i][j][p] = 1;
						dp[i][j][p] = wc[i][j];
					}
					else dp[i][j][p] = INF;
				}
				else{
					ll val = imp[p];
					int a = mp[val/2];
					int b = mp[val - val/2];
					dp[i][j][p] = INF;
					for(int x = 1; x <= n; x++){
						dp[i][j][p] = min(dp[i][j][p], dp[i][x][a] + dp[x][j][b]);
					}
					if(dp[i][j][p] == INF) ct[i][j][p] = 0;
					else{
						for(int x = 1; x <= n; x++){
							if(dp[i][j][p] == dp[i][x][a] + dp[x][j][b]){
								ct[i][j][p] = (ct[i][j][p] + ct[i][x][a] * ct[x][j][b]) % MOD;
							}
						}
					}
				}
			}
		}
	}
	for(int i = 1; i <= n; i++){
		for(int j = 1; j <= n; j++){
			if(dp[i][j][lim] != INF) cout << dp[i][j][lim] << " " << ct[i][j][lim] << " ";
			else cout << "X 0 ";
		}
		cout << "\n";
	}
	return 0;
}