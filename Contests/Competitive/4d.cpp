//templates
// l(i,n) loop
// ra(i,a,b) loop in a range
//fill(a,x) memset
//trv(container,iterator)
//mp make_pair
//pb push_back
//db(x) debug x
//lo long long
//head headers
#include<stdio.h>
#include"iostream"
#include<stdlib.h>
#include<string.h>
#include<math.h>
#include<algorithm>
#include<complex>
#include<map>
#include<vector>
#include<set>
//#include<unordered_map>
//#include<unordered_set>
#include<stack>
#include<queue>
#include<deque>
#define X first
#define Y second
using namespace std;
typedef pair<int, int> ii;
typedef pair<ii, int> pi;
int w, h, ct = 0, dp[5006], pos[5006];
vector<pi> lis;

void print(int idx) {
	if (pos[idx] != idx) print(pos[idx]);
	cout << lis[idx].Y + 1 << "\n";
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int mx, n, p, q, r, s, t;
	cin >> n >> w >> h;
	for (int i = 0; i < 5006; i++) pos[i] = i;
	for (int i = 0; i < n; i++) {
		cin >> p >> q;
		if (p > w && q > h) lis.push_back(pi(ii(p, q), i));
	}
	sort(lis.begin(), lis.end());
	t = lis.size();
	if (t == 0) {cout << "0\n"; return 0;}
	for (int i = 0; i < t; i++) {
		mx = 0;
		p = i;
		for (int j = 0; j < i; j++) {
			if (lis[j].X.X < lis[i].X.X && lis[j].X.Y < lis[i].X.Y) {
				if (mx < dp[j]) {
					mx = dp[j];
					p = j;
				}
			}
		}
		dp[i] = 1 + mx;
		pos[i] = p;
	}
	p = -1;
	mx = -1;
	for (int i = 0; i < t; i++) {
		if (mx < dp[i]) {
			mx = dp[i];
			p = i;
		}
	}
	cout << mx << "\n";
	print(p);
	return 0;
}