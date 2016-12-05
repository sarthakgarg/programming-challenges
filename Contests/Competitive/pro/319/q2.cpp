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
vector<ii> edj;
vector<int> ones;
vector<int> cyc[100005];
int n,m,p,x,y,g,h,per[100005],visited[100005],pre=-1,preg=-1,flag,last=-1;
int main(){
	ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
	cin>>n;
	if(n==1) {cout<<"YES\n";return 0;}
	REPP(i,1,n+1) cin>>per[i];
	REPP(i,1,n+1){
		if(visited[i]==0){
			x = i;
			while(visited[x]==0){
				cyc[i].pb(x);
	//			cout<<x<<" ";
				visited[x]=1;
				x = per[x];
			}
			
			g = cyc[i].size();
			if(g!=2&&g!=1){flag=1;break;}
			if(g==1){
				ones.pb(i);
				continue;
			}
			last = i;
			if(pre==-1){
				for(int k=0;k<g-1;k++) edj.pb(ii(cyc[i][k], cyc[i][k+1]));
			}
			else{
				for(int k=0;k<g;k++) edj.pb(ii(cyc[pre][k], cyc[i][k]));
			}
			pre = i;
		}
	}
	int k;
	if(!ones.empty()&&last!=-1)edj.pb(ii(cyc[last][0], ones[0]));
	g = ones.size();
	for(k=0;k<g-1;k++) edj.pb(ii(ones[k],ones[k+1]));
	if(flag==0){
		cout<<"YES\n";
		foreach(edj, it) cout<<it->X<<" "<<it->Y<<"\n";
	}
	else {
		cout<<"NO\n";
	}
	return 0;
}