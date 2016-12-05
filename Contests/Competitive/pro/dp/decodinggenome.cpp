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
ll mark[60][60], dp[100005][60], n, m, p, q, r, s, k;
char str[3];
int main(){
	ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
	cin>>n>>m>>k;
	REP(i,k){
		cin>>str;
		if(str[0]>='a') p = str[0]-'a'+1;
		else p = str[0] - 'A' + 27;
		if(str[1]>='a') q = str[1]-'a'+1;
		else q = str[1] - 'A' + 27;
		mark[p][q]=1;
	}
	REPP(j,1,m+1) dp[1][j] = 1; //starting strings of length 1;
	REPP(i,1,n){
		REPP(j,1,m+1){
			REPP(k,1,m+1){
				if(mark[j][k]!=1){
					dp[i+1][k]=(dp[i+1][k]+dp[i][j])%mod;
				}
			}
		}
	}
	REPP(i,1,m+1){s= (s+dp[n][i])%mod;}
	cout<<s<<"\n";
	return 0;
}