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
#include<algorithm>
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
vector<int> adj[30];
vector<ii> order; 
int visit[30], timer, flag;
void dfs(int v, int mark){
	timer++;
	visit[v] = mark;
	foreach(adj[v], it){
		if(visit[*it] == 0){
			dfs(*it, mark);
			timer++;
		}
		else if(visit[*it] == mark){
		//	cout << "defualt " << (char)(v + 'a') <<(char)(*it + 'a') << "\n"; 
			flag = 1;
		}
	}
	order.push_back(ii(timer, v));
}
int main(){
	int n, m, ans, ct, x, y, pos[102], len[102];
	char str[102][102];
	cin >> n;
	for(int i = 0; i < n; i++){
		cin >> str[i];
		pos[i] = 0;
		len[i] = strlen(str[i]);
	}
	vector<ii> lis;
	for(int i = 0; i < n - 1; i++) lis.push_back(ii(i, i + 1));
	while(!lis.empty()){
		vector<ii> nu;
		foreach(lis, it){
			int y3 = it -> X;
			int y2 = it -> Y;
			cout << y3 << " " << y2 << "\n";
			cout << str[y3][pos[y3]] << " " << str[y2][pos[y2]]<<"\n";
			cout << "\n";
			if(str[y3][pos[y3]] != str[y2][pos[y2]]){
				cout << y3 << " " << y2 << "\n";
				cout << str[y3][pos[y3]] << " " << str[y2][pos[y2]]<<"\n";
				adj[str[y3][pos[y3]] - 'a'].push_back(str[y2][pos[y2]] - 'a');
			}
			else{
				pos[y3]++;
				pos[y2]++;
				if(pos[y3] != len[y3] && pos[y2] == len[y2]){
					flag = 1;
					break;
				}
				else if(pos[y3] != len[y3] && pos[y2] != len[y2]){
					nu.push_back(ii(y3, y2));
				}
			}
		}
		if(flag == 1) break;
		lis.clear();
		foreach(nu, it) lis.push_back(*it);
		nu.clear();
	}
	for(int i = 0; i < 26; i++){
		if(visit[i] == 0) dfs(i, i + 1);
	}
	/*for(int i = 0; i < 26; i++){
		cout << (char)(i + 'a') << " ";
		foreach(adj[i], it) cout << (char)(*it + 'a') << " ";
		cout<<"\n";
	}*/
	if(flag == 1) {
		cout << "Impossible\n";
		return 0;
	}
	sort(order.begin(), order.end());
	for(auto it = order.end() - 1; it != order.begin(); it--) cout << (char)(it -> Y + 'a');
	cout << (char)(order.begin() -> Y + 'a') << "\n";
	return 0;
}