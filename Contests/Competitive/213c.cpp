//templates
// l(i,n) loop 
// ra(i,a,b) loop in a range 
//fill(a,x) memset
//trv(container,iterator)
//mp make_pair
//pb push_back
//db(x) debug x
//lo long long 
//head headers
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
#define INF 100000000
int dp[301][301],arr[301][301],m;
int main(){
	ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
	cin>>m;
	REPP(i,1,m+1)REPP(j,1,m+1)cin>>arr[i][j];
	REPP(i,1,m+1)REPP(j,1,m+1){dp[i][j]=-INF;}
	REP(i,m+1)dp[0][i]=-INF;
	dp[1][1]=0;
	REPP(i,1,m+1){
		cout<<"processing row "<<i<<"\n";
		REPP(j,1,m+1)REPP(k,1,m+1){
			dp[j][k]+=((j==k)?arr[i][j]:arr[i][j]+arr[i][k]);
		}
		REPP(j,1,m+1)REPP(k,j,m+1){
			dp[j][k]=max(dp[j][k],dp[j-1][k]+arr[i][j]);			
		}
		REPP(j,1,m+1)REPP(k,j,m+1){
			if(j==k) continue;
			dp[j][k]=max(dp[j][k-1]+arr[i][k],dp[j][k]);
		}	
		REPP(j,1,m+1){
			REPP(k,1,m+1)cout<<dp[j][k]<<" ";
			cout<<"\n";
		}
	}
	return 0;
}	