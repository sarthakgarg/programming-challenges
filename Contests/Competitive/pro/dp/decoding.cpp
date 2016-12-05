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
ll a[60][60], b[60][60], c[60][60],p,q,r,s,t,n,m,k;
char str[3];
void sq(){
	REPP(i,1,m+1) REPP(j,1,m+1) b[i][j] = a[i][j];
	ll sum ;
	REPP(i,1,m+1){
		REPP(j,1,m+1){
			sum =0;
			REPP(k,1,m+1) sum=(sum+b[i][k]*b[k][j])%mod;
			a[i][j] = sum;
		}
	}
}
void mult(){
	REPP(i,1,m+1) REPP(j,1,m+1) b[i][j] = a[i][j];
	ll sum ;
	REPP(i,1,m+1){
		REPP(j,1,m+1){
			sum =0;
			REPP(k,1,m+1) sum=(sum+b[i][k]*c[k][j])%mod;
			a[i][j] = sum;
		}
	}
}
void modexp(ll n){
	if(n==0){
		REPP(i,1,m+1) a[i][i] = 1;
		return ;
	}
	modexp(n/2);
	sq();
	if(n%2) mult();
	return ;
}
int main(){
	cin>>n>>m>>k;
	REPP(i,1,m+1) REPP(j,1,m+1) c[i][j]=1;
	REP(i,k){
		cin>>str;
		if(str[0]>='a') p = str[0] - 'a' + 1;
		else p = str[0] - 'A' + 27;
		if(str[1]>='a') q = str[1] - 'a' +1;
		else q = str[1] -'A' +27;
		c[q][p] =0;
	}
	modexp(n-1);
	REPP(i,1,m+1)REPP(j,1,m+1)s= (s+a[i][j])%mod;
	cout<<s<<"\n";
	return 0;
}