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
typedef pair<int, int> ii;
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
const int mod = 1e9 + 7;
int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int n, p, q, r, x, ans[1004];
	char ch, str[1004];
	cin >> n >> str;
	ans[0] = 1;
	p = 0;
	REP(i, n - 1) {
		if (str[i] == '=') {ans[i + 1] = ans[i];} 
		else {
			if(str[i]=='L') ans[i+1]=min(ans[i]-1,1);
			else {ans[i+1]=ans[i]+1;p=i+1;}					
			if(ans[i+1]<=0){x=1-ans[i+1];REPP(j,p,i+2){ans[j]+=x;}}
		}
	}
//	if(ans[n-1]<=0){x=1-ans[n-1];REPP(j,p,n)ans[j]+=x;}
	REP(i, n) cout << ans[i] << " ";
	cout << "\n";
	return 0;
}
