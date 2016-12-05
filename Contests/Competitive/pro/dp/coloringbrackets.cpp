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
typedef pair<ll,ll> ii;
typedef pair<ii,double> inv;
#define X first
#define Y second
#define REP(i,a) for(int i=0;i<a;++i)
#define REPP(i,a,b) for(int i=a;i<b;++i)
#define FILL(a,x) memset(a,x,sizeof(a))
#define	foreach( gg,itit )	for( auto itit=gg.begin();itit!=gg.end();itit++ )
#define	mp make_pair
#define	pb push_back
#define sz(a) int((a).size())
#define	debug(ccc)	cout << #ccc << " = " << ccc << endl;
#define present(c,x) ((c).find(x) != (c).end())
const int mod = 1e9+7;
#define INF 1e18+7
ll l,r,ct,ans,x,y,n,m;
char str[1000];
ll check(ll l,ll r,ll lc, ll rc){
	if(((l==lc)&&(l!=0))||((r==rc)&&(r!=0))) return 0;
	else return 1;
}
ll find(ll l,ll r,ll lcolor, ll rcolor){
	if(l>r) return 1;
	ll re=0;
	ll trc = 0, close=l;
	while(trc!=0||close==l){
		if(str[close]=='(') trc++;
		else trc--;	
		close++;
	}
	close--;

	if(close==r){
		if(check(1,0,lcolor,rcolor)) re+=find(l+1,r-1,1,0);
		if(check(2,0,lcolor,rcolor)) re+=find(l+1,r-1,2,0);
		re=(re%mod);
		if(check(0,1,lcolor,rcolor)) re+=find(l+1,r-1,0,1);
			re=(re%mod);	
		if(check(0,2,lcolor,rcolor)) re+=find(l+1,r-1,0,2);
				re=(re%mod);
		return re;
	}
	ll temp=close;
	close
	if(check(1,0,lcolor,0)&&check(0,1,0,rcolor)) re+=(find(l+1,close-1,1,0)*find(close+2,r-1,0,1));
		re=(re%mod);	
	if(check(2,0,lcolor,0)&&check(0,2,0,rcolor)) re+=(find(l+1,close-1,2,0)*find(close+2,r-1,0,2));

	if(check(1,0,lcolor,0)&&check(0,2,0,rcolor)) re+=(find(l+1,close-1,1,0)*find(close+2,r-1,0,2));

	if(check(2,0,lcolor,0)&&check(0,1,0,rcolor)) re+=(find(l+1,close-1,2,0)*find(close+2,r-1,0,1));

	if(check(1,0,lcolor,0)&&check(1,0,0,0)) re+=(find(l+1,close-1,1,0)*find(close+2,r-1,1,0));	
			re=(re%mod);
	if(check(1,0,lcolor,0)&&check(2,0,0,0)) re+=(find(l+1,close-1,1,0)*find(close+2,r-1,2,0));
			re=(re%mod);	
	if(check(2,0,lcolor,0)&&check(1,0,0,0)) re+=(find(l+1,close-1,2,0)*find(close+2,r-1,1,0));	
			re=(re%mod);
	if(check(2,0,lcolor,0)&&check(2,0,0,0)) re+=(find(l+1,close-1,2,0)*find(close+2,r-1,2,0));	
			re=(re%mod);
	if(check(0,1,0,0)&&check(0,1,0,rcolor)) re+=(find(l+1,close-1,0,2)*find(close+2,r-1,0,1));	
			re=(re%mod);
	if(check(0,1,0,0)&&check(0,2,0,rcolor)) re+=(find(l+1,close-1,0,2)*find(close+2,r-1,0,2));	
			re=(re%mod);
	if(check(0,2,0,0)&&check(0,1,0,rcolor)) re+=(find(l+1,close-1,0,2)*find(close+2,r-1,0,1));	
			re=(re%mod);
	if(check(0,2,0,0)&&check(0,2,0,rcolor)) re+=(find(l+1,close-1,0,2)*find(close+2,r-1,0,2));	
			re=(re%mod);
	re+=(find(l+1,close-1,0,1)*find(close+2,r-1,2,0));
			re=(re%mod);
	re+=(find(l+1,close-1,0,2)*find(close+2,r-1,1,0));
			re=(re%mod);
	return re;
}
int main(){
	ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
	cin>>str;
	n = strlen(str);
	cout<<find(0,n-1,0,0)<<"\n";
	return 0;
}
