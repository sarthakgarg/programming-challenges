#include <stdio.h>
#include "iostream"
#include <stack>
#include <queue>
#include <vector>
#include <map>
#include <set>
#include <unordered_map>
#include <unordered_set>
#include<string.h>
#define REP(i, n) for(int i = 0; i < n; i++)
#define REPP(i, a, b) for(int i = a; i < b; i++)
#define foreach(gg, itit) for(auto itit = gg.begin(); itit != gg.end(); itit++)
#define X first
#define Y second
#define mod 1000000007
#define MAXN 1000005
#define MAXALPHA 27
using namespace std;
typedef pair<int, int> ii;
typedef long long ll;
typedef unsigned long long ull;
int visit[52][52], grid[52][52], flag;
void dfs(int i, int j, int x, int y){
	visit[i][j] = 1;
	for(int k = -1; k < 2; k++){
		for(int l = -1; l < 2; l++){
			if(i + k == x && j + l == y) continue;
			if(k == 0 && l == 0) continue;
			if(k == 0 || l == 0){
				if(grid[i + k][j + l] == grid[i][j]){
					if(visit[i + k][j + l] == 1){
						flag = 1;
					}
					else dfs(i + k, j + l, i, j);
				}
			}
		}
	}
}
int main(){
	int n, m, x, y;
	char str[53];
	cin >> n >> m;
	for(int i = 0; i < n; i++){
		cin >> str;
		for(int j = 0; j < m; j++){
			grid[i + 1][j + 1] = str[j] - 'A' + 1;
		}
	}
	for(int i = 0; i < n + 1; i++) grid[i][0] = 0;
	for(int j = 0; j < m + 1; j++) grid[0][j] = 0;
	for(int i = 1; i <= n; i++){
		for(int j = 1; j <= m; j++){
			for(int l = 0; l <= n; l++) for(int k = 0; k <= m; k++) visit[l][k] = 0;
			dfs(i, j, 0, 0);
		}
	}
	if(flag == 1) cout << "Yes\n";
	else cout << "No\n";
	return 0;
}