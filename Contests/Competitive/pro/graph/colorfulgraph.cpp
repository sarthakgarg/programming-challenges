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
int color[100004],n,m,c,x,y,visit[100004];
vector<int> adj[100004];
set<int> cnt[100004];
int main(){
	ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
	cin>>n>>m;
	REPP(i,1,n+1) {cin>>color[i];visit[color[i]]=1;}
	REPP(i,1,m+1){
		cin>>x>>y;
		adj[x].pb(y);
		adj[y].pb(x);
	}
	REPP(i,1,n+1){
		foreach(adj[i],it){
			if(color[i]==color[*it]) continue;
			cnt[color[*it]].insert(color[i]);
		}
	}
	int ans=-1,mx=-1;
	REPP(i,1,100003){
		if(visit[i]==0) continue;
		x=cnt[i].size();
		if(mx<x)
		{
			mx=x;
			ans=i;
		}
	}
	cout<<ans<<"\n";
	return 0; 
}