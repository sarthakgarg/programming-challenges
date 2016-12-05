#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define REP(i,a) for(int i=0;i<a;++i)
#define REPP(i,a,b) for(int i=a;i<b;++i)
#define FILL(a,x) memset(a,x,sizeof(a))
#define	foreach( gg,itit )	for( auto itit=gg.begin();itit!=gg.end();itit++ )
#define	pb push_back
vector<int> fact[100007];
int n, k, arr[100005], rem[100005], pos[100005], zeropos = -1, ans[100005], mx;
int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	REPP(i, 1, 100003) {
		for (int j = i; j < 100003; j += i)fact[j].pb(i);
	}
	FILL(pos, -1);
	cin >> n >> k;
	REP(i, n) {cin >> arr[i]; rem[i] = (arr[i] >= k) ? (arr[i] - k) : (k - arr[i]);}
	REP(i, n - 1) {
		if (rem[i] == 0)zeropos = i;
		else foreach(fact[rem[i]], it)pos[*it] = i;
		if (arr[i + 1] <= k)ans[i + 1] = -1;
		else ans[i + 1] = max(pos[arr[i + 1]], zeropos);
	}
	ll sum = 1;
	mx = -1;
	REPP(i, 1, n) {mx = max(mx, ans[i]); sum += (i - mx);}
	cout << sum << "\n";
	return 0;
}
