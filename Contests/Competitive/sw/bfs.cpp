// for bipartiteness, there should not be any edge between vertices with the same shortest distance from a source vertex
#include<stdio.h>
#include"iostream"
#define N 2003
#define INF 1000000009
using namespace std;
int queue[N], front, back, n, m, x, y, cnt[N], d[N], t, edg[N][N];
int isempty(){
	if(front == back) return 1;
	else return 0;
}
void push(int x){
	queue[back++] = x;
}
int top(){
	return queue[front];
}
void pop(){
	front++;
}	
int bfs(int i){
	d[i] = 0;
	push(i);
	while(!isempty()){
		x = top();
		pop();
		for(int j = 0; j < cnt[x]; j++){
			if(d[edg[x][j]] == d[x]) return 0;
			else if(d[edg[x][j]] == INF){
				d[edg[x][j]] = d[x] + 1;
				push(edg[x][j]);
			}
		}
	}
	return 1;	
}
int main(){
	cin >> t;
	for(int k = 1; k <= t; k++){
		cin >> n >> m;
		for(int i = 1; i <= n; i++) {
			cnt[i] = 0;
			d[i] = INF;
		}
		for(int i = 0; i < m; i++){
			scanf("%d%d", &x, &y);
			edg[x][cnt[x]++] = y;
			edg[y][cnt[y]++] = x;
		}
		int flag = 1;
		for(int i = 1; i <= n; i++){
			front = back = 0;
			if(d[i] == INF){
				flag *= bfs(i);
			}
		}
		cout << "Scenario #" << k << ":\n";
		if(flag == 1) cout << "No suspicious bugs found!\n";
		else cout << "Suspicious bugs found!\n";
	}
	return 0;
}
