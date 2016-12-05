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
int main(){
	ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
	cin>>n>>m;
	int mx=-1;
	REP(i,n)REP(j,m)cin>>arr[i][j];
	REP(i,n){
		REPP(j,0,i){
			REP(k,m){
				REPP(l,0,k){
					int flag=-1;
					REPP(r,l,k+1)if(arr[j][r]==1||arr[i][r]==1)flag=0;
					REPP(r,j,i+1)if(arr[r][k]==1||arr[r][l]==1)flag=0;
					if(flag==1)mx=max(mx,2*(k-l+1)+2*(i-j+1));
				}
			}
		}
	}
	cout<<mx<<"\n";
	return 0;
}	
				}
			}
		}
	}