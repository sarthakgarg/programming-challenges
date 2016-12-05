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
	int a1,b1,a2,b2,a3,b3,flag=0;
	ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
	cin>>a1>>b1>>a2>>b2>>a3>>b3;
	if(a2+a3<=a1&&max(b2,b3)<=b1) flag=1;
	if(a2+b3<=a1&&max(b2,a3)<=b1) flag=1;
	if(b2+a3<=a1&&max(a2,b3)<=b1) flag=1;
	if(b2+b3<=a1&&max(a2,a3)<=b1) flag=1;
	if(a2+a3<=b1&&max(b2,b3)<=a1) flag=1;
	if(a2+b3<=b1&&max(b2,a3)<=a1) flag=1;
	if(b2+a3<=b1&&max(a2,b3)<=a1) flag=1;
	if(b2+b3<=b1&&max(a2,a3)<=a1) flag=1;
	if(flag==1) cout<<"YES\n";
	else cout<<"NO\n";
	return 0;
}