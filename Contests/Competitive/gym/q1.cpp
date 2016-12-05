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
#include<unordered_map>
#include<unordered_set>
#include<stack>
#include<queue>
#include<deque>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> ii;
#define X first
#define Y second
#define REP(i,a) for(int i=0;i<a;++i)
#define REPP(i,a,b) for(int i=a;i<b;++i)
#define FILL(a,x) memset(a,x,sizeof(a))
#define	foreach( gg,itit )	for( auto itit=gg.begin();itit!=gg.end();itit++ )
#define	mp make_pair
#define	pb push_back
#define sz(a) int((a).size())
#define	debug(ccc)	cout << #ccc << " = " << ccc << endl;
#define present(c,x) ((c).find(x) != (c).end())
#define INF 1e18
ll dp[1003][1003], l, m, n, p, q, r, s, t;
const int MAXV = 100000;
void find(ll n, ll k){
	if(n == 0 || k > 2*n || k < n) return dp[n][k] = 0;
	if(dp[n][k] != 0) return dp[n][k];
	return dp[n][k] = (dp[n][k - 1]*(2*l - k + 1) + dp[l - 1][k - 1]*4) % mod; 
}
int main(){
	ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
	dp[1][1] = 1;
	cin >> n;
	while(n != 0){
		cout << find(n, 2*n) << "\n";
		cin >> n;
	}	
	return 0;
}