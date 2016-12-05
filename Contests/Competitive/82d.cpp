#include<bits/stdc++.h>
using namespace std;
#define REP(i,a) for(int i=0;i<a;++i)
#define FILL(a,x) memset(a,x,sizeof(a))
#define sz(a) int((a).size())
int n, arr[1006], dp[1006][1006][3];
int find(int e, int l) {
	if (e == -1) return arr[l];
	if (e == 0) return max(arr[e], arr[l]);
	if (dp[e][l][0] != -1) return dp[e][l][0];
	int a, b, c;
	a = find(e - 2, e - 1) + max(arr[e], arr[l]);
	b = find(e - 2, e) + max(arr[l], arr[e - 1]);
	c = find(e - 2, l) + max(arr[e], arr[e - 1]);
	if (a == min(min(a, b), c)) {dp[e][l][0] = a; dp[e][l][1] = l; dp[e][l][2] = e; return a;}
	else if (b == min(min(a, b), c)) {dp[e][l][0] = b; dp[e][l][1] = l; dp[e][l][2] = e - 1; return b;}
	else {dp[e][l][0] = c; dp[e][l][1] = e; dp[e][l][2] = e - 1; return c;}
}
void print(int e, int l) {
	if (e == -1) {cout << n - l << "\n"; return;}
	if (e == 0) {cout << n - l << " " << n << "\n"; return;}
	cout << n - dp[e][l][1] << " ";
	cout << n - dp[e][l][2] << "\n";
	if (dp[e][l][1] == l && dp[e][l][2] == e) print(e - 2, e - 1);
	else if (dp[e][l][1] == l && dp[e][l][2] == e - 1) print(e - 2, e);
	else print(e - 2, l);
	return;
}
int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	cin >> n;
	REP(i, n) cin >> arr[i];
	int i, j;
	i = 0;
	j = n - 1;
	while (i < j) {swap(arr[i], arr[j]); i++; j--;}
	FILL(dp, -1);
	cout << find(n - 2, n - 1) << "\n";
	print(n - 2, n - 1);
	return 0;
}