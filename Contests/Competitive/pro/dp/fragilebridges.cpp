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
typedef pair<int, int> ii;
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
const int mod = 1e9 + 7;
#define INF 2e18
ll dp[100006][4], a[100006], x, y, p, q, r, n;
int main(){
	ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
	cin>>n;
	REP(i,n-1) cin>>a[i+2];
	REPP(i,2,n+1){
		if(a[i]%2==0){
			dp[i][1] = dp[i-1][1] + a[i] - 1;   //terminals
			if(dp[i-1][0]!=0)
				dp[i][0] = max(dp[i-1][1], dp[i-1][0]) + a[i];  //middle 
			else dp[i][0] = dp[i-1][1] + a[i];
			if(i==2) dp[i][0] = 0;
			dp[i][2] = dp[i-1][2] + a[i];	//loops 
		}
		else {
			dp[i][1] = max(dp[i-1][1] + a[i], dp[i-1][2] + a[i]); //terminal
			if(dp[i-1][0]!=0)
				dp[i][0] = max(dp[i-1][1], dp[i-1][0]) + a[i] -1; //middle 
			else dp[i][0] = dp[i-1][1] + a[i] - 1;
			if(i==2) dp[i][0] = 0;
			if(a[i]!=1)
				dp[i][2] = dp[i-1][2] + a[i] -1 ; //loops
			else  dp[i][2] =0;
		}
	}
	dp[n][0] = max(dp[n][0], dp[n][2]);
	cout<<max(dp[n][0], dp[n][1])<<"\n";
	return 0;
}