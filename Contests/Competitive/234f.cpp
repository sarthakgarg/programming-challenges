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
#define	foreach( gg,itit )	for(auto itit=gg.begin();itit!=gg.end();itit++ )
#define	mp make_pair
#define	pb push_back
#define sz(a) int((a).size())
#define	debug(ccc)	cout << #ccc << " = " << ccc << endl;
#define present(c,x) ((c).find(x) != (c).end())
#define IN 2082213412
const int mod = 1e9+7;
int n,arr[300],a,b,dp[202][40006][2],sum[300];
int find(int r,int rleft,int color){
	int red=rleft,green=b-(sum[n-1]-sum[r]-(a-rleft)),x;
	if((color==0&&red<arr[r])||(color==1&&green<arr[r])) return IN;
	if(r==0) return 0;
	if(dp[r][rleft][color]!=-1) return dp[r][rleft][color];
	if(color==0){x=min(find(r-1,rleft-arr[r],0),find(r-1,rleft-arr[r],1)+min(arr[r],arr[r-1]));}
	else{x=min(find(r-1,rleft,0)+min(arr[r],arr[r-1]),find(r-1,rleft,1));}
	dp[r][rleft][color]=x;
	return x;
}
int main(){
	int ans;
	ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
	freopen("input.txt", "r", stdin);
	freopen("output.txt","w",stdout);
	cin>>n;
	int p=0,q,r,s,t;
	cin>>a>>b;
	REP(i,n)cin>>arr[i];
	REP(i,n){p+=arr[i];sum[i]=p;}
	FILL(dp,-1);
	ans=min(find(n-1,a,0),find(n-1,a,1));
	if(ans==IN)cout<<"-1\n";
	else cout<<ans<<"\n";
	return 0;
}