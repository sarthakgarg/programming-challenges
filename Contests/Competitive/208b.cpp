#include<bits/stdc++.h>
using namespace std;
#define REP(i,a) for(int i=0;i<a;++i)
#define REPP(i,a,b) for(int i=a;i<b;++i)
const int mod = 1e9 + 7;
int n, dp[60][4][15][4][15][15][4], suits[60], val[60], lksuit[100], lkval[100];
int find(int n, int s3, int v3, int s2, int v2, int s1, int v1) {
	if (n == -1) {if ((s1 == s2 || v1 == v2) && (s1 == s3 || v1 == v3)) return 1; else return 0;}
	if (dp[n][s3][v3][s2][v2][s1][v1] != -1) return dp[n][s3][v3][s2][v2][s1][v1];
	int a = 0, b = 0;
	if (s1 == s2 || v1 == v2) a = find(n - 1, suits[n], val[n], s3, v3, s1, v1);
	if (s1 == suits[n] || v1 == val[n]) b = find(n - 1, s1, v1, s3, v3, s2, v2);
	return dp[n][s3][v3][s2][v2][s1][v1] = max(a, b);
}
char str[2];
int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	FILL(dp, -1);
	lksuit['S'] = 0; lksuit['D'] = 1; lksuit['H'] = 3; lksuit['C'] = 4;
	REPP(j, '2', '9' + 1) lkval[j] = j - '2';
	lkval['T'] = 8; lkval['J'] = 9; lkval['Q'] = 10; lkval['K'] = 11; lkval['A'] = 12;
	cin >> n;
	REP(i, n) {cin >> str; suits[i] = lksuit[str[1]]; val[i] = lkval[str[0]];}
	if (n == 1) {cout << "YES\n"; return 0;}
	if (n == 2) {if (suits[1] == suits[0] | val[0] == val[1])cout << "YES\n"; else cout << "NO\n"; return 0;}
	int x = find(n - 4, suits[n - 3], val[n - 3], suits[n - 2], val[n - 2], suits[n - 1], val[n - 1]);
	if (x == 1) cout << "YES\n"; else cout << "NO\n";
	return 0;
}