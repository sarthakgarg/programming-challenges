#include<stdio.h>
#include"iostream"
#include<vector>
#define N 100005
using namespace std;
typedef long long ll;
ll len[N], deg[N], n, m, x, y, ans;
vector<ll> adj[N];
int main(){
	cin >> n >> m;
	while(m--){
		cin >> x >> y;
		deg[x]++;
		deg[y]++;
		if(x < y) swap(x, y);
		adj[x].push_back(y);
	}
	for(int i = 1; i <= n; i++){
		ll mx = 1;
		ll sz = adj[i].size();
		for(int j = 0; j < sz; j++){
			mx = max(mx, len[adj[i][j]] + 1);
		}
		len[i] = mx;
	//	cout << len[i] << " ";
		ans = max(ans, len[i] * deg[i]);
	}
	cout << ans << "\n";
	return 0;
}