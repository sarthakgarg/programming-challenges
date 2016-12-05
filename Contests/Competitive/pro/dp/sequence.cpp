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
typedef pair<int, int> ii;
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
const int mod = 1e9 + 7;
#define INF 1e18
ll min(ll a,ll b){
	if(a<b) return a;
	else return b;	
}
ll ab(ll a){
	if(a<0) return -a;
	else return a;
}
set<ll> s;
vector<ll> heights;
ll dp[5002][2],n,m,h,x,p,q,t,arr[5003];
int main(){
	ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
	cin>>n;
	REP(i,n){ 
		cin>>arr[i];
		s.insert(arr[i]);
	}
	foreach(s,it){heights.pb(*it);p++;}
	REP(i,n){
		x = (i+1)%2;
		t = (i%2);
		m = INF;
		REP(j,p){
			m = min(m,dp[j][x]+ab(heights[j]-arr[i]));
			dp[j][t] = m;
		}
	}
	cout<<m<<"\n";
	return 0;	
}