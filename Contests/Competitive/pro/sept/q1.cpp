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
#define	foreach( gg,itit )	auto itit=gg.begin();itit!=gg.end();itit++ )
#define	mp make_pair
#define	pb push_back
#define sz(a) int((a).size())
#define	debug(ccc)	cout << #ccc << " = " << ccc << endl;
#define present(c,x) ((c).find(x) != (c).end())
const int mod = 1e9+7;
ll t, n, px[500*500+7], py[500*500 + 7],ans,x,y;
ll ab(ll a ){
	return (a>0)?a:-a;
}
int main(){
  ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);	
  cin>>t;
  while(t--){
  	ans=0;
  	cin>>n;
  	REPP(i,1,n+1)REPP(j,1,n+1){cin>>x;px[x]=i;py[x]=j;}
  	REPP(i,1,n*n){y = (ab(px[i+1]-px[i])+ab(py[i+1]-py[i]));ans+=y;}
  	cout<<ans<<"\n";
 	}
 	return 0;
 }