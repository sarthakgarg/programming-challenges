#include<stdio.h>
#include"iostream"
#include<vector>
#include<string.h>
#define MAXN 21004
#define MAXALPHA 27
#define INF 1000000000
using namespace std;
typedef long long ll;
int trie[MAXN][MAXALPHA], nxt, t, x, y, dp[MAXN][102], l, m, n, k;
vector<int> adj[MAXN];
char str[20005], str1[20005];
void add(char st[]){
    int v = 0;
     for(int i = 0; st[i] != '\0'; i++){
       if(trie[v][st[i] - 'a'] != -1) v = trie[v][str[i] - 'a'];
       else{
         trie[v][st[i] - 'a'] = nxt;
		 adj[v].push_back(nxt);
         v = nxt;
         nxt++;
       }
   }
}	
void make(int v, int depth){
	int sz = adj[v].size();
	int temp[102];
	dp[v][0] = 0;
	for(int i = 1; i <= k; i++) dp[v][i] = INF;
	for(int i = 0; i < sz; i++){
		make(adj[v][i], depth + 1);
		for(int j = 0; j <= k; j++) temp[j] = dp[v][j];
		for(int j = 0; j <= k; j++){
			for(int p = 0; p <= k; p++){
				if(p + j > k) continue;
				temp[p + j] = min(temp[p + j], dp[v][j] + dp[adj[v][i]][p]);
			}
		}
		for(int j = 0; j <= k; j++) dp[v][j] = temp[j];
	}
	if(sz == 0) dp[v][1] = depth - 1;
	else dp[v][1] = depth;
}
int main(){
	cin >> t;
	for(int m = 1; m <= t; m++){
		nxt = 1;
		for(int i = 0; i < MAXN; i++)
		  for(int j = 0; j < MAXALPHA; j++)
		    trie[i][j] = -1;
		for(int i = 0; i < MAXN; i++) adj[i].clear();
		cin >> n >> k;
		for(int i = 0; i < n; i++){
			cin >> str;
			int len = strlen(str);
			str[len] = 'a' + 27;
			str[len + 1] = '\0';
			add(str);
		}
		make(0, 0);
		cout << "Case #" << m << ": " << max(dp[0][k], 1) << "\n";
	}
	return 0;
}