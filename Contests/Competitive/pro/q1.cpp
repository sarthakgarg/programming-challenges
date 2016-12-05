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
#define	foreach( gg,itit )	for( typeof(gg.begin()) itit=gg.begin();itit!=gg.end();itit++ )
#define	mp make_pair
#define	pb push_back
#define sz(a) int((a).size())
#define	debug(ccc)	cout << #ccc << " = " << ccc << endl;
#define present(c,x) ((c).find(x) != (c).end())
const int mod = 1e9+7;
ll n,m,k,t,p,q,r,s,v[200];
void find(ll k){
	int i = 0;
	for(int j = 0; j < n; j++){
		int ct = 0;
		ct++;
	}
}
int main(){
	ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
	cin >> t;
	while(t--){
		cin >> k >> m >> n;
		q = 0;
		REP(i, n){ cin >> v[i]; q += v[i]; }
		sort(v, v + n);
		p = 0;
		r = n - 1;
		q = k - q;
		while(q < m){
			p++;
			q += v[r];
			r--;
		}
		cout << p << "\n";
	}
	return 0;
}
