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
#define	foreach( gg,itit )	for( typeof(gg.begin()) itit=gg.begin();itit!=gg.end();itit++ )
#define	mp make_pair
#define	pb push_back
#define sz(a) int((a).size())
#define	debug(ccc)	cout << #ccc << " = " << ccc << endl;
#define present(c,x) ((c).find(x) != (c).end())
const int mod = 1e9+7;
int n,m,t,mark[50009], parent[50009], size[50009], x,y,q,r;
int fin(int i){
	if(parent[i]==i) return i;
	else{
		int j=fin(parent[i]);
		parent[i]=j;
		return j;
	}
}
void uni(int i,int j){
	int k,l;
	k=fin(i);
	l=fin(j);
	if(size[k]<size[l]){
		parent[k]=l;
		size[l]+=size[k];
		size[k]=0;
	}
	else{
		parent[l]=k;
		size[k]+=size[l];
		size[l]=0;
	}
}
char str[50007], ch[50007];
ll modexp(ll base, ll pow){
	if(pow==0) return 1;
	ll x = modexp(base,pow/2);
	x = (x*x)%mod;
	if(pow%2) x = (x*base)%mod;
	return x;
}
int main(){
	ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
	cin>>t;
	while(t--){
		cin>>n>>m;
		REPP(i,1,n+1){parent[i]=i;size[i]=1;}
		cin>>str;
		REPP(i,1,n+1)ch[i]='A';
		int l = 1;
		int r = n;
		while(l<r){
			uni(l,r);
			l++;
			r--;
		}
		REPP(i,1,m+1){
			cin>>x>>y;
			if(fin(x)!=fin(y)) uni(x,y);
		}
		// groups made.
		ll flag=0;
		ll ct=0; 
	//	REPP(i,1,n+1){cout<<i<<" "<<fin(i)<<"\n";}
		REPP(i,1,n+1){

			if(ch[fin(i)]=='A'){
				ch[fin(i)]=str[i-1];
				if(str[i-1]=='?') ct++;
			}
			else if(ch[fin(i)]=='?'){
				ch[fin(i)] = str[i-1];
				if(str[i-1]!='?') ct--;
			}
			else{
				if(ch[fin(i)]!=str[i-1]&&str[i-1]!='?'){
					flag=1;
					break;
				}
			}
		}
		if(flag==1){cout<<"0\n"; continue;}
		cout<<modexp(26,ct)<<"\n";
	}
	return 0;
}