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
#define INF 1e9
const int mod = 1e9+7;
map<ii,int> ans;
int a,b;
int find(int x,int y){
	if(x==y) return 0;
	if(x<y) swap(x,y);	
	if(ans[ii(x,y)]!=0) return ans[ii(x,y)];
	int re=INF;
	if(x%2==0) re=min(re,find(x/2,y)+1);
	if(x%3==0) re=min(re,find(x/3,y)+1);
	if(x%5==0) re=min(re,find(x/5,y)+1);
	return ans[ii(x,y)]=re;
}
int main(){
	cin>>a>>b;
	int p= find(a,b);
	if(p>1e8) cout<<"-1";
	else cout<<p;
	cout<<"\n";
	return 0;
}