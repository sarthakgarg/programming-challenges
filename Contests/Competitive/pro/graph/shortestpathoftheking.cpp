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
#define INF 1e9
const int mod = 1e9+7;
int ls,rs,lt,rt;
char start[3],en[3];
int ab(int a){
	return (a>=0)?a:-a;
}
int main(){
	int ans;
	ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
	cin>>start>>en;
	ls=start[0]-'a'+1;rs=start[1]-'1'+1;lt=en[0]-'a'+1;rt=en[1]-'1'+1;
	ans=max(ab(lt-ls),ab(rt-rs));
	cout<<ans<<"\n";
	REP(i,ans){
		en[0]='\0';en[1]='\0';en[2]='\0';
		int j=0;
		if(ls<lt){en[j]='R';j++;ls++;}
		else if(ls>lt){en[j]='L';j++;ls--;}
		if(rs>rt){en[j]='D';j++;rs--;}
		else if(rs<rt){en[j]='U';j++;rs++;}
		cout<<en<<"\n";
	}
	return 0;
}	