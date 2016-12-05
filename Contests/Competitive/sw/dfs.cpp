#include<stdio.h>
#include"iostream"
#define N 2004
int edg[N][N], visited[N], n, m, t, cnt[N], x, y, clr[N];
using namespace std;
int dfs(int v, int color){
	visited[v] = 1;
	clr[v] = color;
	int flag = 1;
	for(int j = 0; j < cnt[v]; j++){
		if(visited[edg[v][j]] && clr[edg[v][j]] == color) return -1;
		else if(visited[edg[v][j]] == 0) flag *= dfs(edg[v][j], -1 * color); 
	}
	return flag;
}
int main(){
	cin >> t;
	for(int k = 1; k <= t; k++){
		cin >> n >> m;
		for(int i = 1; i <= n; i++) visited[i] = clr[i] = cnt[i] = 0;
		for(int i = 0; i < m; i++){
			scanf("%d%d", &x, &y);
			edg[x][cnt[x]++] = y;
			edg[y][cnt[y]++] = x;
		}
		int flag = 1;
		for(int i = 1; i <= n; i++){
			if(visited[i] == 0){
				flag *= dfs(i, 1);
			}
		}
		cout << "Scenario #" << k << ":\n";
		if(flag == 1) cout << "No suspicious bugs found!\n";
		else cout << "Suspicious bugs found!\n";
	}
	return 0;
}
