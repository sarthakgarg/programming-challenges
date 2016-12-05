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
int prime[10000007],rub[10000007];
int main(){
	ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
	char str[10];
	for(int i=2;i*i<10000006;i++){
		if(prime[i]==1) continue;
		for(int j=i*i;j<10000006;j+=i) prime[j]=1;
	}
	prime[0]=0;prime[1]=0;
	int ct=0;
	REPP(i,2,10000005){if(prime[i]==0)ct++;prime[i]=ct;}
	REPP(i,1,10000005){
		int j=0,k=i;
		while(k!=0){
			str[j]=k%10+'0';
			k/=10;
			j++;
		}
		int flag=0,l=0,r=j-1;
		while(l<=r){
			if(str[l]!=str[r])flag=1;
			l++;
			r--;
		}
		if(flag==1)rub[i]=1;
	}
	ct=0;
	REPP(i,1,10000005){if(rub[i]==0)ct++;rub[i]=ct;}
	int p,q,n=-1;
	cin>>p>>q;
	REPP(i,1,10000005){if(1LL*q*prime[i]<=1LL*p*rub[i])n=max(n,i);}
	if(n==-1) cout<<"Palindromic tree is better than splay tree\n";
	else cout<<n<<"\n";
	return 0;
}	