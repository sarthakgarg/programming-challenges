//solution of a modification of the lcs problem 
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
#define INF 1000000007
const int mod = 1e9+7;
int dp[1005][1005][105],n,m,s;
char str1[1005],str2[1005];
int find(int p,int q,int k){
	if(dp[p][q][k]!=-1) return dp[p][q][k];
	if(p==n||q==m) return dp[p][q][k]=0;
	int mx=0;
	if(k>=s||k==0) mx=max(find(p,q+1,0),find(p+1,q,0));
	if(str1[p]==str2[q]){
		mx=max(mx,find(p+1,q+1,k+1)+1);
	}
	return dp[p][q][k]=-INF;
}
int main(){
	ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
	cin>>str1>>str2;
	n=strlen(str1);m=strlen(str2);
	cin>>s;
	FILL(dp,-1);
	int a=find(0,0,0);
	if(a<0) a=0;
	cout<<a<<"\n";
	return 0;	
}	