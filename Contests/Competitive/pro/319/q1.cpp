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
int prime[1003];
vector<int> seq;
int n,m,x,y,z,p,f[1003],ct,ans;
int main(){
	ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
	cin>>n;
	prime[1]=1;
	for(int i=2;i*i<1003;i++){
		if(prime[i]==0){
			for(int j=2*i;j<1003;j+=i) prime[j]=1;
		}
	}
	if(n==1){cout<<"0\n";return 0;}
	REPP(i,2,n+1){
		z=0;
		x = i;
		REPP(j,2,1003){
			ct = 0;
			while(x!=1&&prime[j]==0&&x%j==0){
				x/=j;
				ct++;
			}
			if(prime[j]==0&&ct!=0){
				if(f[j]<ct){
					f[j]=ct;
					z=1;
				}
			}
		}
		if(z==1){
			ans++;
			seq.pb(i);
		}
	}
	cout<<ans<<"\n";
	foreach(seq, it) cout<<*it<<" ";
	cout<<"\n";
	return 0;
}