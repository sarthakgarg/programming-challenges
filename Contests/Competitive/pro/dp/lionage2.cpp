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
#define present(c,x) ((c).fin(x) != (c).end())
#define INF 2e18
const int mod = 1e9+7;
bool done[102][102][28];
ll dp[102][102][28], p,q,r,s,t,k,n,x,y,c[30][30];
char str[103],str1[2];
ll fin(ll n, ll k, ll last){
	if(k<0) return -INF;
	if(n==0) return 0;
	if(done[n][k][last]==true) return dp[n][k][last];
	done[n][k][last]=true;
	ll mx = -INF;
	REPP(i,1,27){
		if(str[n-1]-'a'+1 == i)mx = max(mx,fin(n-1, k, i)+c[i][last]);
		else mx = max(mx, fin(n-1,k-1,i)+c[i][last]);
	}
	return dp[n][k][last] = mx;
}	
int main(){
	ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
	cin>>str>>k;
	n = strlen(str);
	cin>>p;
	REP(i,p){
		cin>>str1;
		x = str1[0] - 'a' + 1;
		cin>>str1;
		y = str1[0] - 'a' + 1;
		cin>>c[x][y];
	}
	cout<<fin(n, k, 0)<<"\n";
	return 0;
}
