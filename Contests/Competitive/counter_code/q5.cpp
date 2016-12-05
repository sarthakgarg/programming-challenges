#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> ii;
#define REP(i,a) for(ll i=0;i<a;++i)
#define REPP(i,a,b) for(ll i=a;i<b;++i)
#define	foreach( gg,itit )	for( auto itit=gg.begin();itit!=gg.end();itit++ )
const ll mod = 1e9+7;
stack<ll> lis;
vector<ll> components[1000006];
ll adj[1000005],comp[1000005],visit[1000005],fact[1000007],num[1000006],in[1000006],freq[1000006],iscycle[1000008];
int main(){
	ll n,x,y=1,z,v;
	cin>>n;
	REPP(i,1,n+1){cin>>adj[i];in[adj[i]]++;}
	REPP(i,1,n+1){
		x=i;
		if(visit[x]==1) continue;
		while(visit[x]==0)
		{
			visit[x]=1;
			lis.push(x);
			x=adj[x];
		}
		if(comp[x]==0){z=y;y++;
			v=x;
			while(adj[x]!=v){iscycle[x]=1;x=adj[x];}
			iscycle[x]=1;
		}
		else z=comp[x];
		while(!lis.empty()){comp[lis.top()]=z;components[z].push_back(lis.top());lis.pop();}
	} 
	REPP(i,1,n+1){num[comp[i]]++;if(in[i]==0){freq[comp[i]]++;}}
	ll m=0;	
	REPP(i,1,y){if(freq[i]==0) m++ ; else m+=freq[i];}
	m=n-m;	
	fact[1]=1;fact[0]=1;
	REPP(i,2,1000006)fact[i]=(1LL*fact[i-1]*i)%mod;
	ll ans=1;
	REPP(i,1,y){
		ll b=1,c=1;
		if(freq[i]==0) b=num[i]+1;
		else{
			foreach(components[i],it){
				if(in[*it]!=0){
					b=(1LL*b*in[*it])%mod;
					if(iscycle[*it]==0)c=(1LL*c*in[*it])%mod;
				}
			}
		}
		b-=c;
		b=(b+mod)%mod;
		ans=(1LL*ans*b)%mod;
	}
	ans=(1LL*ans*fact[n-m])%mod;
	cout<<m<<" "<<ans<<"\n";
	return 0;
}	

