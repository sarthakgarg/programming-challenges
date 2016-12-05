#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> ii;
#define X first
#define Y second
#define REP(i,a) for(int i=0;i<a;++i)
#define REPP(i,a,b) for(int i=a;i<b;++i)
#define	pb push_back
const int mod = 1e9 + 7;
int n, m, parent[1000006], size[1000006] = {1}, prv, ct, val, pos, stat[1000006], mx[1000006], mn[1000006], maxi, mini;
ll ls[1000007], eq[10000007], x, total;
int play[1000007], val_max = -1;
char str[2];
vector<ii> lis, quer;
vector<pair<int, ll> >ans;
int fin(int i) {
	if (parent[i] == i) return i;
	else {
		int j = fin(parent[i]);
		return parent[i] = j;
	}
}
void uni(int i, int j) {
	int k = fin(i), l = fin(j);
	if (size[k] < size[l]) {
		parent[k] = l;
		mx[l] = max(mx[l], mx[k]);
		mn[l] = min(mn[l], mn[k]);
		size[l] += size[k]; size[k] = 0;
	}
	else {
		parent[l] = k;
		mx[k] = max(mx[l], mx[k]);
		mn[k] = min(mn[l], mn[k]);
		size[k] += size[l]; size[l] = 0;
	}
}
void print(ll count, int index) {
	if (count % 2 == 0) {if (play[index] == 0)cout << "C"; else cout << "D";}
	else {if (play[index] == 0)cout << "D"; else cout << "C";}
}
int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	cin >> n >> m;
	REP(i, n) {cin >> val; lis.pb(ii(val, i)); parent[i] = i; mx[i] = i; mn[i] = i; val_max = max(val_max, val);}
	sort(lis.begin(), lis.end());
	prv = -1; ct = 0;
	total = 1LL * (n) * (n + 1) / 2;
	REP(i, n) {
		val = lis[i].X; pos = lis[i].Y;
		stat[pos] = 1;
		if (pos > 0 && stat[pos - 1] == 1)uni(pos, pos - 1);
		if (pos < n - 1 && stat[pos + 1] == 1)uni(pos, pos + 1);
		maxi = mx[fin(pos)]; mini = mn[fin(pos)];
		x = 1LL * (maxi - pos + 1) * (pos - mini + 1);
		if (val == prv)ans[ct - 1].Y += x;
		else {ans.pb(ii(val, x)); ct++; prv = val;}
	}
	REP(i, m) {
		cin >> str;
		if (str[0] == '<')stat[i] = -1; else if (str[0] == '=')stat[i] = 0; else stat[i] = 1;
		cin >> x >> str;
		if (str[0] == 'D')play[i] = 0; else play[i] = 1;
		quer.pb(ii(x, i));
	}
	sort(quer.begin(), quer.end());
	int i = 0;
	x = 0;
	REP(j, m) {
		val = quer[j].X;
		pos = quer[j].Y;
		if (val > val_max) {ls[pos] = total; continue;}
		while (i < ct && ans[i].X <= val) {x += ans[i].Y; i++;}
		if (i != 0) {
			ls[pos] = (ans[i - 1].X == val) ? (x - ans[i - 1].Y) : x;
			eq[pos] = (ans[i - 1].X == val) ? ans[i - 1].Y : 0;
		}
	}
	REP(i, m) {
		if (stat[i] == -1)print(ls[i], i);
		else if (stat[i] == 0)print(eq[i], i);
		else print(total - ls[i] - eq[i], i);
	}
	cout << "\n";
	return 0;
}