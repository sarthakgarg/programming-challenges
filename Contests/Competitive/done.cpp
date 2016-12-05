// I think motive of this question is something about managing precision
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
#define	foreach( gg,itit )	for( auto itit=gg.begin();itit!=gg.end();itit++ )
#define	mp make_pair
#define	pb push_back
#define sz(a) int((a).size())
#define	debug(ccc)	cout << #ccc << " = " << ccc << endl;
#define present(c,x) ((c).find(x) != (c).end())
const int mod = 1e9+7;
int n,m,h,s1,s2,x;
int main(){
	ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
	cin>>n>>m>>h;
	int ten[10]={1,10,100,1000,10000,100000,1000000,10000000,100000000,1000000000};
	double pn=1,pd=1,ans;
	int wn=0,wd=0;
	REPP(i,1,m+1){cin>>x;if(i==h)s1+=(x-1) ;else s2+=x;}
	if(n-1>s1+s2){cout<<"-1\n";return 0;}
	if(s2<n-1){cout<<"1\n";return 0;}
	REPP(i,s2-n+2,s1+s2-n+2){pn*=i;while(pn>=1){pn/=10;wn++;}}
	REPP(i,s2+1,s1+s2+1){pd*=i;while(pd>=1){pd/=10;wd++;}}
	if(wd>wn+7) ans=0;
	else ans=(pn/pd)/ten[wd-wn];
	printf("%.6lf\n",1-ans);
	return 0;
}	