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
int n,k,a,ct,m,x,posy,posx;
set<int> pos;
int main(){
	ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
	cin>>n>>k>>a>>m;
	a++;
	ct=(n+1)/a;
	REP(i,m){
		cin>>x;
		x--;
		set<int>::iterator it=lower_bound(pos.begin(),pos.end(),x);
		if(it==pos.end()) posy=n;
		else posy=*it;
		if(it!=pos.begin()){
			it--;
			posx=*it;
		}
		else posx=-1;
		ct=ct-(posy-posx)/a+(x-posx)/a+(posy-x)/a;
		if(ct<k){cout<<i+1<<"\n";return 0;}
		pos.insert(x);		
	}
	cout<<"-1\n";
	return 0;
}	