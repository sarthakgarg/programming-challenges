#include<bits/stdc++.h>
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
int dp[5002][5002],n,m;
char str1[5002],str2[5002];
int main(){
	ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
	cin>>str1>>str2;n=strlen(str1);m=strlen(str2);
	int ans=0;
	REP(i,n){
		int sum=0;
		REP(j,m){
			if(str1[i]==str2[j]){
				if(i==0||j==0) sum++;
				else sum=(sum+dp[i-1][j-1]+1)%mod;
			}
			dp[i][j]=sum;
		}
		ans=(ans+sum)%mod;
	}
	cout<<ans<<"\n";
	return 0;
}	