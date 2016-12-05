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
const int mod = 1e9+7;
#define INF 1e18+7;
bool done[2002][4005];
ll n,c[2002],t[2002],dp[2002][4005];
ll find(ll in, ll tim){
	if(in<0) return (tim>=0)? 0 : INF;
	if(tim>2000) return 0;
	if(done[in][tim+2001]==true) return dp[in][tim+2001];
	done[in][tim+2001]=true;
	ll a = c[in] + find(in-1, tim+t[in]);
	a = min(a, find(in-1,tim-1));
	return dp[in][tim+2001] = a;
}
int main(){
	ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
	cin>>n;
	REP(i,n){cin>>t[i]>>c[i];}
	cout<<find(n-1,0)<<"\n";
	return 0;
}