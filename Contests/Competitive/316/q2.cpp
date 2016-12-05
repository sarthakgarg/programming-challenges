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
int ans,tot,red;
char str[300005],ch[2];
int main(){
	ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
	int n,m,x;
	cin>>n>>m>>str;
	str[n]='b';
	str[n+1]='\0';
	REP(i,n+1){if(str[i]=='.')tot++;else if(i>0&&str[i-1]=='.')red++;}
	ans=tot-red;
	REP(i,m){
		cin>>x>>ch;
		if(ch[0]=='.'){
			if(str[x-1]!='.'){
				tot++;
				if(x>1&&str[x-2]=='.')red--;
				if(str[x]!='.')red++;
				str[x-1]='.';
			}	
		}
		else{
			if(str[x-1]=='.'){
				tot--;
				if(x>1&&str[x-2]=='.')red++;
				if(str[x]!='.')red--;
				str[x-1]='B';
			}					
		}
		cout<<tot-red<<"\n";
	}
	return 0;
}