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
typedef pair<ll,ll> ii;
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
const int  mod= 1e9+7;
#define INF 1e18+7
vector<ii> lis;
int main(){
	ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
	lis.pb(ii(1,1));
	lis.pb(ii(2,2));
	ll b=0;
	while(1){
		ll a=lis[b].X+lis[b+1].X;
		if(a>INF)break;
		lis.pb(ii(a,b+3));
		b++;
	}
	ll t,n,x;
	cin>>t;
	while(t--){
		cin>>n;
		auto it=lower_bound(lis.begin(),lis.end(),ii(n,-1));
		if(it==lis.begin())x=1;
		else if(it==lis.end()){it--;x=it->Y;}
		else if(n==it->X)x=it->Y;
		else {it--;x=it->Y;}
		cout<<x<<"\n";
	}
	return 0;
}		
	