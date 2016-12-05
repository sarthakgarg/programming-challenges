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
ll dp[3005],sum[3005],cost[3005],n,p,m,x,y;
ii mar[3005];
ll min(ll a,ll b){return (a>b)? b : a ;}
int main(){
	ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
	cin>>n;
	REPP(i,1,n+1){
		cin>>x>>mar[i].Y;
		mar[i].X = -x;
	}
	x=0;
	sort(mar+1,mar+n+1);
	REPP(i,1,n+1){
		x+=mar[i].X;
		sum[i] = x;
		y=INF;
		REPP(j,0,i){
			y = min(y,dp[j]+(i-1-j)*mar[i].X - (sum[i-1]-sum[j]));
		}
		dp[i] = mar[i].Y + y;
	}
	cout<<dp[n]<<"\n";
	return 0;
}	