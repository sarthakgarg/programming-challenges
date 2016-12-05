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
typedef pair<int,int> ii;
#define X first
#define Y second
#define REP(i,a) for(int i=0;i<a;++i)
#define REPP(i,a,b) for(int i=a;i<b;++i)
#define FILL(a,x) memset(a,x,sizeof(a))
#define	foreach( gg,itit )	for( typeof(gg.begin()) itit=gg.begin();itit!=gg.end();itit++ )
#define	mp make_pair
#define	pb push_back
#define sz(a) int((a).size())
#define	debug(ccc)	cout << #ccc << " = " << ccc << endl;
#define present(c,x) ((c).find(x) != (c).end())
const int mod = 1e9+7;
ll n,m,a[205],x,y,z,q,s,l,k;
bool done[205][205][405];
double p[205],dp[205][220][405];
double find(ll n, ll l, ll k){
	if(n==-1){if(l<=0&&k>=0) return 1;else return 0;}
	if(k>200) k = 200;
	if(l<0) l = 0;
	if(done[n][l][k+203]==true) return dp[n][l][k+203];
	done[n][l][k+203] = true;
	return dp[n][l][k+203] = p[n]*find(n-1, l-1, k+a[n]) + (1-p[n])*find(n-1, l, k);

}
int main(){
	ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
	cin>>n>>l>>k;
	REP(i,n){cin>>p[i];p[i]/=100;}
	REP(i,n) cin>>a[i];
	printf("%.12lf\n",find(n-1, l, k));
	return 0;
}