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
#define INF 1e18+7
ll gcd(ll a, ll b){
	if(b==0) return a;
	else return gcd(b,a%b);
}
ll n,arr[100003],x,y,z,p,s;
int main(){
	ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
	cin>>n;
	REP(i,n) cin>>arr[i];
	x = gcd(arr[0],arr[1]);
	REPP(i,2,n)x = gcd(x , arr[i]);
	REP(i,n)arr[i]/=x;
	REP(i,n){
		while(arr[i]!=1){
			if(arr[i]%2==0) arr[i]/=2;
			else if(arr[i]%3==0) arr[i]/=3;
			else {p=1;break;}
		}
	}
	if(p==1) cout<<"No\n";
	else cout<<"Yes\n";
	return 0;
}
