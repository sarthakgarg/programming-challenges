#include<stdio.h>
#include"iostream"
#include<string.h>
using namespace std;
typedef long long ll;
#define REP(i,n) for(int i=0;i<n;i++)
#define REPP(i,a,b) for(int i=a;i<b;i++)
#define INF 10000000
char ch, str[100005], pat[16];
int t[16], n, m, s, test, dp[100005];
void build() {
	int l, mx;
	t[0] = -1;
	REP(i, m) {
		mx = 0; l = t[i]; while (l != -1) {if (pat[l] == pat[i])mx = max(mx, l + 1); l = t[l];}
		t[i + 1] = mx;
	}
	return;
}
void match() {
	int l = 0, mx;
	REP(i, n) {
		if (l != m && str[i] == pat[l])l++;
		else {
			mx = 0; while (l != -1) {if (pat[l] == str[i])mx = max(mx, l + 1); l = t[l];}
			l = mx;
		}
		if (l == m) dp[i] = max(dp[i], i - m + 1);
	}
	return ;
}
int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	cin >> str >> test; n = strlen(str);
	REP(i, n + 1)dp[i] = -1;
	REP(i, test) {
		cin >> pat;
		m = strlen(pat);
		build();
		match();
	}
	int ans = 0, s = -1, pos = 0;
	REP(i, n) {
		s = max(s, dp[i]);
		if (ans < i - s) {
			ans = i - s;
			pos = 1 + s;
		}
	}
	cout << ans << " " << pos << "\n";
	return 0;
}
