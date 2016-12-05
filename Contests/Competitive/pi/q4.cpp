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
int n,arr[103],sum[103],stat[104];
int main(){
	cin>>n;
	int x,j;
	char str[3];
	REP(i,n){
		cin>>str;
		if(str[0]=='+') stat[i]=1;
		else stat[i]=0;
		cin>>arr[i];
	}
	REP(i,n){
		x=arr[i];
		if(stat[i]==1){j=i;while(j<n&&(j==i||arr[j]!=x)){sum[j]++;j++;}}
		else {
			j=i;
			while(j>=0&&(j==i||arr[j]!=x)){j--;}
			if(j==-1)REP(j,i+1)sum[j]++;
		}
	}	
	int mx=-1;
	REP(i,n) mx=max(mx,sum[i]);
	cout<<mx<<"\n";
	return 0;
}	