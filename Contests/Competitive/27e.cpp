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
#define INF 1e18+7;
typedef long long ll;                 // this problem requires 2 d dp 
//unsolved bakwaas problem :()
ll dp[1005][2],p[1007],prime[1007];
ll find(int n){
	if(n==1){dp[n][1]=0;return dp[n][0]=1;}
	ll mx=INF,bmin;
	REPP(i,2,n+1){if(n%i==0){
		ll a=find(n/i);
		ll b=dp[n/i][1];
		b++;b=primes[b];
		ll ct=1,flag=0;
		while(ct<i){
			if(a>1+(INF)/b){flag=1;break;}
			a*=b;ct++;
		}
		if(flag==1) continue;
		if(a<=mx){}
	}
	}
	dp[n][1]=
}
int main(){
	ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
	REPP(i,2,1004){if(p[i]!=0)continue;for(int j=i;j*j<1006;j+=i)p[j]=1;}    // aplied sieve 
	int ct=1;REPP(i,2,1004){if(p[i]==0){prime[ct]=i;ct++;}}					 // segregated primes
	int n;cin>>n;cout<<find(n)<<"\n";
	return 0;
}			
	