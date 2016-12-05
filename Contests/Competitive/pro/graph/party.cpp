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
int visit[2005];
vector<int> adj[2003];
int dfs(int v){
	visit[v]=1;
	int ans=0;
	foreach(adj[v],it)ans=max(ans,dfs(*it));
	return ans+1;
}
int main(){
	ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
	int n,x,y=-1,p,s;
	cin>>n;
	REP(i,n){
		cin>>x;
		if(x>0) adj[x].pb(i+1);
	}
	REPP(i,1,n+1){
		if(visit[i]==0){
			y=max(y,dfs(i));
		}
	}
	cout<<y<<"\n";
	return 0;
}