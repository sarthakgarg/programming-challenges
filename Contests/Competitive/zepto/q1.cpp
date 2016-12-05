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
#define	foreach( gg,itit )	for( typeof(gg.begin()) itit=gg.begin();itit!=gg.end();itit++ )
#define	mp make_pair
#define	pb push_back
#define sz(a) int((a).size())
#define	debug(ccc)	cout << #ccc << " = " << ccc << endl;
#define present(c,x) ((c).find(x) != (c).end())
const int mod = 1e9+7;
int main(){
	ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
	int n,p,q,r;
	char str[103];
	cin>>n>>str;
	int flag=0;
	REP(i,n){
		REPP(dist,1,n){
			if(i+4*dist>=n) continue;
			if(str[i]=='*'&&str[i+dist]=='*'&&str[i+ 2*dist]=='*'&&str[i+3*dist]=='*'&&str[i+4*dist]=='*') flag=1;
		}
	}
	if(!flag)cout<<"no\n";
	else cout<<"yes\n";
	return 0;
}	