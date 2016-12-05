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
int main(){
	int a1,a2,a3,a4,a5,a6;
	cin>>a1>>a2>>a3>>a4>>a5>>a6;
	cout<<(2*a4+1)*(a5+a6) + ((a5 - 1)*a5)/2 + a5*a6 -(a6*(a6+1))/2	+ ((a3-1)*a3)/2 + a2*a3 - ((a2+1)*a2)/2<<"\n";
	return 0;
}