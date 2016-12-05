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
#define INF 1e18
const int MAXV = 100000;
ll l, n, m, arr[100000], p, q, power, k, ans[100], sum[10000], pw[10000], inv[5];
void print(int i){
	if(i == 0) cout <<"P"<<"\n";
	else if(i == 1) cout<<"S" <<"\n";
	else cout<<"R\n";
}
ll find(ll x){
//	cout<<"find "<<x<<" called\n";
	int l = 0;
	//cout<<x<<"\n";
	if(x == 1) return 0;
	else if(x == 2) return 1;
	else if(x == 3) return 2;
	x -= 3;		
	while(sum[l] < x) l++;
	if(l == 1){
		if(x == 1) return 1;
		else if(x == 2) return 2;
		else if(x == 3) return 0;
		else if(x == 4) return 2;
		else if(x == 5) return 0;
		else if(x == 6) return 1;
	}
	else{
		q = x - sum[l-1];
		if(q > pw[l]/2) return (inv[find(3 + sum[l-1] + q - pw[l]/2)]);
		return inv[find(q)];
	}
}
int main(){
	ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
	cin >> n;
	inv[0] = 1;
	inv[1] = 2;
	inv[2] = 0;
	pw[0] = 0;
	sum[0] = 0;
	pw[1] = 6;
	sum[1] = 6;
	l = 1;
	while(sum[l] < 1000000000007){
		pw[l + 1] = pw[l] * 3;
		sum[l + 1] = sum[l] + pw[l + 1];
		l++;
	}
	while(n != 0){
		p = n;
		print(find(n));
		cin >> n;
	}
	return 0;
}