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
int n,m,visited[103],ct,x,y,timer;
vector<int> adj[103];
void dfs(int v){
	visited[v]=1;
	foreach(adj[v],it){
		if(visited[*it]==0) dfs(*it);
		else ct++;
	}
}
int main(){
	ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
	cin>>n>>m;
	REP(i,m){cin>>x>>y;adj[x].pb(y);adj[y].pb(x);}
	dfs(1);
	int flag=0;
	REPP(i,2,n+1){if(visited[i]==0)flag=1;}
	if(ct==n+1&&flag==0) cout<<"FHTAGN!";
	else cout<<"NO";
	cout<<"\n";
	return 0;
}