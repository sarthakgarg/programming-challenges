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
typedef pair<int,int> ii;
vector<ii> lis;
map<ii,i> ans;
int h,w,modinv[100006];
int modexp(int base,int power){
	if(power==0) return 1;
	ll x=modexp(base,power/2);
	x=(x*x)%mod;
	if(power%2==1){
		x*=base;
		x=x%mod;
	} 
	return (int)x;
}
int combine(int n,int r){
	ll a=1;
	REPP(i,1,r+1){
		a*=(n-i+1);
		a%=mod;
		a*=modinv[i];
		a%=mod;
	}
	return (int)a;
}
int ans(int x,int y){
	int p,q,b=1;
	ll a;
	modinv[1]=1;
	REPP(i,2,100005) modinv[i]=modexp(i,mod-2);
	auto it=ans.find(ii(x,y));
	if(it!=ans.end()) return it->Y;
	a=combine(h+w,h);
	foreach(lis,it){
		if(it->X<=x&&it->Y<=y){
			a+=1LL*ans(it->X,it->Y)*combine(h-it->X+w-it->Y,h-it->X);
			a=a%mod;
		}
	}
	ans.insert(pair<ii,i>(ii(x,y),(int)a));
	return (int)a;
}
int main(){
	ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
	int p,q,r,s,t;
	cin>>h>>w>>n;
	REP(i,n){
		cin>>p>>q;
		lis.push_back(ii(p,q));
	}
	cout<<ans(h,w)<<"\n";
	return 0;
}		
