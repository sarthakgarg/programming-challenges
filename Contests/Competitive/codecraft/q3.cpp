#include <stdio.h>
#include <iostream>
#include <stdlib.h>
#include <string.h>
#include <vector>
#include <map>
#include <set>
#include <stack>
#include <queue>
#include <deque>
#include <cmath>
#include <utility>
#include <algorithm>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>
#define pdd pair<double,double>
#define PB push_back
#define MP make_pair
#define N 2000001
#define M 25
#define MOD 1000000007

int dp[N][M];

ll modexp(ll x){
	ll n = MOD - 2, ans = 1;

	while(n > 0){
		if(n % 2 == 1)
			ans = (ans * x) % MOD;

		x = (x * x) % MOD;

		n/=2;
	}

	// cout << ans << '\n';

	return ans;
}

ll compute(ll n, ll r){
	ll ans = 1, d = 1;

	if(n < r)
		return 0;

	while(r > 0){
		ans = (ans * (n - r + 1)) % MOD;
		d = (d * r) % MOD;
		r = r - 1;
	}

	ans = (ans * modexp(d)) % MOD;

	return ans;
}

int main(){
	ll t,n,m,i,j,k;

	dp[1][0] = 1;

	for(i = 2; i <= N; i++){
		dp[i][1] = 1;
		for(j = 2*i; j <= N; j+=i){
			for(k = 1; k < M-1 && dp[i][k] > 0; k++){
				dp[j][k+1] = (dp[j][k+1] + dp[i][k])%MOD;
			}
		}
	}

	scanf("%I64d", &t);

	while(t--){
		scanf("%I64d%I64d", &n, &m);

		ll ans = 0;

		for(i = 0; i < M; i++){
			if(dp[n][i] == 0)
				continue;

			// cout << i << ' ' << dp[n][i] << '\n';
			ans = (ans + 1LL*dp[n][i]*compute(m,i))%MOD;
		}

		printf("%I64d\n", ans);
	}

	return 0;
}