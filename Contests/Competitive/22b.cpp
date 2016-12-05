//templates
// l(i,n) loop 
// ra(i,a,b) loop in a range 
//fill(a,x) memset
//trv(container,iterator)
//mp make_pair
//pb push_back
//db(x) debug x
//lo long long 
//head headers
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
int arr[30][30],n,m;
int dp[30][30][30][30];
int check(int x1,int y1,int x2,int y2){
	int a;
	if(x2<x1||y2<y1)return 1;
	if(dp[x1][y1][x2][y2]!=-1) return dp[x1][y1][x2][y2];
	if(check(x1,y1,x2-1,y2)==1&&check(x1,y1,x2,y2-1)==1&&arr[x2][y2]==0)a=1;
	else a=0;
	dp[x1][y1][x2][y2]=a;
	return a;
}
int main(){
	ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
	cin>>n>>m;
	char str[30];
	FILL(dp,-1);
	int mx=-1;
	REP(i,n){cin>>str;REP(j,m)arr[i][j]=str[j]-'0';}
	REP(i,n){
		REPP(j,0,i+1){
			REP(k,m){
				REPP(l,0,k+1){
					if(check(j,l,i,k))mx=max(2*(k-l+1)+2*(i-j+1),mx);
				}
			}
		}
	}
	cout<<mx<<"\n";
	return 0;
}	