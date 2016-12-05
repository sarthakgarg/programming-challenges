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
vector<int> adj[1003];
int x[1003],y[1003],n,ans,l,r,visit[1003];
void dfs(int v){
	visit[v]=1;
	foreach(adj[v],it){if(visit[*it]==0)dfs(*it);}
}
int main(){
	ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
	cin>>n;
	REPP(i,1,n+1){cin>>l>>r;x[i]=l;y[i]=r;}
	REPP(i,1,n+1){
		REPP(j,1,n+1){
			if(i==j) continue;
			if(x[i]==x[j]||y[i]==y[j]){
				adj[i].pb(j);
				adj[j].pb(i);
			}
		}
	}
	REPP(i,1,n+1){
		if(visit[i]==0){ans++;dfs(i);}
	}
	cout<<ans-1<<"\n";
	return 0;
}	