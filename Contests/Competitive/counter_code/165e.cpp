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
int num[4000006];
int main(){
	ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
	int arr[100006],n,deci[100],x,ct,pow,sum;
	cin>>n;REP(i,n)cin>>arr[i];
	REP(i,n){
		x=arr[i];ct=0;pow=1;
		while(x!=0){
			if(x%2==0){deci[ct]=pow;ct++;}
			pow*=2;
			x/=2;
		}
		while(pow<=4000001){deci[ct]=pow;pow*=2;ct++;}
		pow=1;
		REP(j,ct)pow*=2;
		printf("%d calculations\n",pow);
		REP(j,pow){
			sum=0;x=j;ct=0;
			while(x!=0){if(x%2==1)sum+=deci[ct];x/=2;ct++;}
			if(sum<=4000006){num[sum]=arr[i];/*printf("%d and %d satisfy\n",arr[i],sum);*/}
		}
	}
	REP(i,n){if(num[arr[i]]==0)cout<<"-1\n";else cout<<num[arr[i]]<<"\n";}
	return 0;
}			
