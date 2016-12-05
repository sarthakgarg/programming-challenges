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
int dp[5002][5002],len,q,l,r;
char str[5002];
int find(int i,int j){
	if(i<0||j<0) return 0;
	else return dp[i][j];
}
int main(){
	ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
	cin>>str;len=strlen(str);
	REP(i,len){
		int x=0,dev=0;
		while(i-dev>=0&&i+dev<len){
			if(str[i+dev]!=str[i-dev])break;
			dp[i-dev][i+dev]=1;
			dev++;
		}
	}
	REP(i,len){
		int x=0,dev=0;
		while(i-dev>=0&&i+dev+1<len){
			if(str[i+dev+1]!=str[i-dev]) break;
			dp[i-dev][i+dev+1]=1;
			dev++;
		}
	}
	REP(i,len){
		REP(j,len){
			dp[i][j]=find(i-1,j)+find(i,j-1)-find(i-1,j-1)+dp[i][j];
		}
	}	
	cin>>q;
	REP(i,q){
		cin>>l>>r;
		l--;r--;
		cout<<find(r,r)-find(l-1,r)-find(r,l-1)+find(l-1,l-1)<<"\n";
	}
	return 0;
}	