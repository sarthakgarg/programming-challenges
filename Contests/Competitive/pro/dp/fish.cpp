//does the states are visted in a queued manner. Yes !
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
typedef pair<ll,ll> ii;
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
#define INF 1e18+7
ll n,p,x,y,k,r;
double dp[262160],arr[20][20];
queue<ll> q1;
int main(){
	ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
	cin>>n;
	REP(i,n)REP(j,n)cin>>arr[i][j];
	REP(i,(1<<n))dp[i]=INF;
	q1.push((1<<n)-1);
	dp[(1<<n)-1]=1;
	while(!q1.empty()){
		r = q1.front();
		q1.pop();
		k = r;
		vector<ll> st;
		ll ct=0,num=0;
		while(k!=0){
			if(k%2==1) {st.pb(ct);num++;}
			ct++;
			k/=2;
		}
		if(num==1) continue;
		foreach(st,it){
			double sum = 0;
			foreach(st,it1){
				sum+=arr[*it1][*it];
			}
			sum/=((num)*(num-1)/2);
			ll nw = r - (1<<*it);
			if(dp[nw]==INF){dp[nw]=sum*dp[r];q1.push(nw);}
			else{dp[nw]+=sum*dp[r];}
		}
	}
	REP(i,n) printf("%.6lf ",dp[1<<i]);
	cout<<"\n";
	return 0;
}