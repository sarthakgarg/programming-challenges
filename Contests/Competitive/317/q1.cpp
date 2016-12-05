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
ll a,b,c,l,p,q,r,s,t,ans,k;
ll find(ll t){
	ll re = k*(t+1) - t*(t+1)/2;
	if(k%2==0) re+=(t+1)/2;
	else re+=(t/2)+1;
	re/=2;
	return re;
}
int main(){
	ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
	cin>>a>>b>>c>>l;
	REPP(i,0,l+1){
		ll fin=0;
		k=l-i+1;
		if(k<=0) continue;
		s=b-a-c-i;
		t=a+b-c+i;
		if(t<=s+1) continue;
		if(t<=0){
			swap(t,s);
			t=-t;
			s=-s;
		}
		t--;
		if(s>-1){
			ll add = find(t);
			ll sub = find(s);
			fin+=(add-sub);
		}
		else if(s==-1){
			ll add = find(t);
			fin+=add;
		}
		else{
			ll add = find(t);
			ll sub = find(-s-1);
			fin += (add + sub - find(0));
		}
		k=a-b-c+i+1;
		if(k>=l-i+1){continue;}
		if(k<=0){if(fin>0)ans+=fin; continue;}
		if(s>-1){
			ll add = find(t);
			ll sub = find(s);
			fin-=(add-sub);
		}
		else if(s==-1){
			ll add = find(t);
			fin+=add;
		}		
		else{
			ll add = find(t);
			ll sub = find(-s-1);
			fin -= (add + sub - find(0));
		}
		if(fin>=0) ans+=fin;
	}
	cout<<ans<<"\n";
	return 0;
}	