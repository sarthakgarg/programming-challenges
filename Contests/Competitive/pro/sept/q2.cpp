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
#define	foreach( gg,itit )	auto itit=gg.begin();itit!=gg.end();itit++ )
#define	mp make_pair
#define	pb push_back
#define sz(a) int((a).size())
#define	debug(ccc)	cout << #ccc << " = " << ccc << endl;
#define present(c,x) ((c).find(x) != (c).end())
const int mod = 1e9+7;
ll t,n,m,arr[20003],ct[20004],x,ans,pt;
int main(){
	ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
	cin>>t;
	while(t--){
		cin>>n>>m;
		arr[0] = 0;
		REPP(i,1,m+1)cin>>arr[i];
		sort(arr,arr+m+1);
		x = 0;
		REP(i,m+1){x+=arr[i];ct[i]=x;}
		ans=0;
		pt=0;
		while(ans+pt+1<m){
			ans++;
			while(ct[pt+1]<=ans) pt++;
		}
		cout<<ans<<"\n";
	}
	return 0;
}



