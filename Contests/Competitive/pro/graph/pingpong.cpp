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
#define present(c,x) ((c).fin(x) != (c).end())
#define INF 1e9
const int mod = 1e9+7;
int parent[102],size[102],m,l,r,x,interl[102],sig,a,b,interr[102];
int fin(int a){
	if(parent[a]==a) return a;
	int j=fin(parent[a]);
	parent[a]=j;
	return j;
}
void uni(int a, int b){
	int i=fin(a),j=fin(b);
	if(size[i]<size[j]){
		parent[i]=j;
		size[j]=size[j]+size[i];
		size[i]=0;
	}
	else{
		parent[j]=i;
		size[i]=size[i]+size[j];
		size[j]=0;
	}
}	
int main(){
	ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
	cin>>m;
	REP(i,m){
		cin>>sig>>a>>b;
		if(sig==1){
			interl[x]=a;
			interr[x]=b;
			parent[x]=x;
			size[x]=1;
			REP(j,x){
				if(interl[j]>interl[x]&&interl[j]<interr[x]&&fin(j)!=fin(x)){uni(x,j); printf("%d %d union\n",x+1,j+1);}
				if(interr[j]>interl[x]&&interr[j]<interr[x]&&fin(j)!=fin(x)){uni(x,j); printf("%d %d union\n",x+1,j+1);}
			}
			x++;
		}
		else{
			if(fin(a-1)==fin(b-1)) cout<<"YES\n";
			else cout<<"NO\n";
		}
	}
	return 0;	
}