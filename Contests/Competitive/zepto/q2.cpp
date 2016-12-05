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
int main(){
	ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
	int n;
	cin>>n;
	int num=1,arr[1000006],sum[1000006]={0};
	REP(i,n+1)num*=2;
	num-=2;
	int ans=0;
	REP(i,num){cin>>arr[i+2];}
	for(int i=num+1;i>1;i-=2){sum[i/2]=max(sum[i]+arr[i],sum[i-1]+arr[i-1]);ans+=(max(sum[i]+arr[i],sum[i-1]+arr[i-1])-min(sum[i]+arr[i],sum[i-1]+arr[i-1]));}
	cout<<ans<<"\n";
	return 0;
}	


