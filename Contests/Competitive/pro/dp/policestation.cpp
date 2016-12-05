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
#define INF 1e18
const int mod = 1e9+7;
vector<ll> adj[102];
queue<ll> q1,qn;
ll ways1[103],waysn[103],dist1[103],distn[103],x,y,s,p,q,t,n,m,ver[103];
int main(){
	ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
	cin>>n>>m;
	REPP(i,1,n+1){distn[i]=INF;dist1[i]=INF;}
	REPP(i,1,m+1){
		cin>>x>>y;
		adj[x].pb(y);
		adj[y].pb(x);
	}
	dist1[1]=0;
	ways1[1]=1;
	q1.push(1);
	while(!q1.empty()){
		x = q1.front();
		q1.pop();
		foreach(adj[x],it){
			if(dist1[*it]==dist1[x]+1||dist1[*it]==INF)ways1[*it]+=ways1[x];
			if(dist1[*it]==INF){dist1[*it]=dist1[x]+1;q1.push(*it);}
		}
	}
	distn[n]=0;
	waysn[n]=1;
	qn.push(n);
	while(!qn.empty()){
		x = qn.front();
		qn.pop();
		foreach(adj[x],it){
			if(distn[*it]==distn[x]+1||distn[*it]==INF)waysn[*it]+=waysn[x];
			if(distn[*it]==INF){distn[*it]=distn[x]+1;qn.push(*it);}
		}
	}
	REPP(i,1,n+1){
		foreach(adj[i],it){
			if(dist1[i]+distn[*it]+1==dist1[n]){ver[i]+=ways1[i]*waysn[*it];ver[*it]+=ways1[i]*waysn[*it];}
		}
	}
	REPP(i,1,n+1){
		s = max(s,ver[i]);
	}
	printf("%.12lf\n",(double)s/ways1[n]);
	return 0;
}	