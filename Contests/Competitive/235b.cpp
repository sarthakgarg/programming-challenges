#include<bits/stdc++.h>
#define REP(i,a) for(int i=0;i<a;++i)
#define REPP(i,a,b) for(int i=a;i<b;++i)
const int mod = 1e9 + 7;
using namespace std;
int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int n;
	double x, sum1 = 0, sum2 = 0, ans = 0;
	cin >> n;
	REP(i, n) {cin >> x; sum1 += x; sum2 += ans * x; ans = ans * x + x;}
	printf("%lf\n", 2 * sum2 + sum1);
	return 0;
}
