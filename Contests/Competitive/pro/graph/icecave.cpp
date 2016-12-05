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
int visit[504][504],n,m,ls,rs,lt,rt,x,y,dest,flag;
char str[504][504];
queue<ii> bfs;
vector<ii> adj[504][504];
int main(){
	ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
	cin>>n>>m;
	REPP(i,1,n+1) cin>>1+str[i];
	REP(i,n+2)REP(j,m+2){if(i==0||i==n+1||j==0||j==m+1)visit[i][j]=1;}
	REPP(i,1,n+1){
		REPP(j,1,m+1){
			adj[i][j].pb(ii(i,j-1));
			adj[i][j].pb(ii(i+1,j));
			adj[i][j].pb(ii(i,j+1));
			adj[i][j].pb(ii(i-1,j));
		}
	}
	cin>>ls>>rs>>lt>>rt;
	str[ls][rs]='.';
	if(str[lt][rt]=='X'&&!(ls==lt&&rs==rt));
	else{
		int ct=0;
		foreach(adj[lt][rt],it){
			if(visit[it->X][it->Y]==1) continue;
			if(str[it->X][it->Y]=='.') ct++;
		}
		if(ls==lt&&rs==rt){
			if(ct<1) flag=1;
		}
		else{
			if(ct<2) flag=1;
		}
	}
	if(flag==1){cout<<"NO\n"; return 0;}
	visit[ls][rs]=1;
	str[lt][rt]='.';
	bfs.push(ii(ls,rs));
	while(!bfs.empty()){
		ii v = bfs.front();
		bfs.pop();
		visit[v.X][v.Y]=1;
		if(v.X==lt&&v.Y==rt){ flag=1;break; }
		foreach(adj[v.X][v.Y],it){
			if(visit[it->X][it->Y]==0&&str[it->X][it->Y]=='.'){
				visit[it->X][it->Y]=1;
				bfs.push(ii(it->X,it->Y));
			}
		}
	}
	if(flag==1) cout<<"YES\n";
	else cout<<"NO\n";
	return 0;
}	