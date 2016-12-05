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
//#include<algorithm.h>
#define REP(i, n) for(int i = 0; i < n; i++)
#define REPP(i, a, b) for(int i = a; i < b; i++)
#define foreach(gg, itit) for(auto itit = gg.begin(); itit != gg.end(); itit++)
#define X first
#define Y second
#define MAXN 1000005
#define MAXALPHA 27
using namespace std;
typedef pair<int, int> ii;
typedef long long ll;
ll n, mn = 1000000006, ans = 0, pos, arr[200006], dp[200005];
int main(){
	cin >> n;
	REP(i, n){
		cin >> arr[i];
		mn = min(mn, arr[i]);
	}
	for(int i = n - 1; i >= 0; i--){
		if(arr[i] == mn) dp[i] = 0;
		else{
			if(i == n - 1) dp[i] = 1;
			else dp[i] = dp[i + 1] + 1;
		}
	}
//	REP(i, n) cout << dp[i] << " ";
//	cout << "\n";
	ll mx = 0;
	REP(i, n){
		if(dp[i] != n - i) mx = max(mx, dp[i]);
		else mx = max(mx, dp[i] + dp[0]);
	}
	cout << mn*n + mx << "\n";
	return 0;
}