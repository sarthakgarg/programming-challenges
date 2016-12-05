//solution of a modification of the lcs problem 
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
#define INF 1000000007
const int mod = 1e9+7;
int dp[105][105][105],n,m,s,t[105];
char str1[105],str2[105],virus[105];
int fault(int l, char ch){
	while(l!=-1){
		if(ch==virus[l]) return l+1;
		l=t[l];
	}
	return 0;
}
void buildtable()
{  
  int i = 2, j = 0;
  t[0] = -1; t[1] = 0;
  while(i < s)
  {
    if(virus[i-1] == virus[j]) { t[i] = j+1; i++; j++; }
    else if(j > 0) j = t[j];
    else { t[i] = 0; i++; }
  }
}
int find(int p,int q,int k){
	if(dp[p][q][k]!=-1) return dp[p][q][k];
	if(k==s) return dp[p][q][k]=-INF;
	if(p==n||q==m) return dp[p][q][k]=0;
	int mx=max(find(p,q+1,k),find(p+1,q,k));
	if(str1[p]==str2[q]){
		mx=max(mx,find(p+1,q+1,fault(k,str1[p]))+1);
	}
	return dp[p][q][k]=mx;
}
void print(int p,int q,int k){
	if(p==n||q==m) return;
	if(dp[p][q][k]==dp[p+1][q][k]){print(p+1,q,k);return;}
	if(dp[p][q][k]==dp[p][q+1][k]){print(p,q+1,k);return;}
	cout<<str1[p];
	print(p+1,q+1,fault(k,str1[p]));
	return;
}
int main(){
	ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
	cin>>str1>>str2>>virus;
	n=strlen(str1);m=strlen(str2);s=strlen(virus);
	buildtable();
	FILL(dp,-1);
	int a=find(0,0,0);
	if(a==0) cout<<"0";
	else print(0,0,0);
	cout<<"\n";
	return 0;	
}	