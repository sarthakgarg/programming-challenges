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
int edj[102][102],n,m,x,y,k,visit[102],ct;
vector<int> adj[102];
vector<int> lang[102];
void dfs(int v){
	visit[v]=1;
	foreach(adj[v],it){if(visit[*it]==0)dfs(*it);}
}
int main(){
	ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
	cin>>n>>m;
	REPP(i,1,n+1){
		cin>>k;
		if(!k)ct++;
		REPP(j,1,k+1){
			cin>>x;
			lang[x].pb(i);
		}
	}
	REPP(i,1,m+1){
		foreach(lang[i],it){
			if(it+1==lang[i].end()) continue;
			if(edj[*it][*(it+1)]==1) continue;
			adj[*it].pb(*(it+1)); 
			adj[*(it+1)].pb(*it);
			edj[*it][*(it+1)]=1;
			edj[*(it+1)][*it]=1;
		}
	}
	REPP(i,1,n+1){
		if(visit[i]==0){y++;dfs(i);}
	}
	if(ct==n) cout<<y<<"\n";
	else cout<<y-1<<"\n";
	return 0;
}