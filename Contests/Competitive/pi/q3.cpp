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
const int mod = 1e9+7;
ll arr[200005][2],n,k,inp[200005];
unordered_map<ll,ll> ct,ct1;
int main(){
	ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
	cin>>n>>k;
	ll x,y,fin;
	ll z,p;
	REP(i,n)cin>>inp[i];
	ll sum=0;
	REP(i,n){
		x=inp[i];
		if(x%k==0) x/=k;
		else x=1000000009;
		y=ct[x];
		sum+=ct1[x];
		ct1[inp[i]]+=y;
		ct[inp[i]]++;
	}
	cout<<sum<<"\n";
	return 0;
}	