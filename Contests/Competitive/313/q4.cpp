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
const int mod = 1e9 + 7;
char str1[200005],str2[200005];
int check(int s1,int e1,int s2,int e2,int param){
	int l1=e1-s1+1,flag=0,l,r;
	if(l1%2==1&&param==0){
		l=s1;
		r=s2;
		while(l<=e1){
			if(str1[l]!=str2[r]){flag=1;break;}
			l++;
			r++;
		}
		if(flag==0)return 1;
		else return 0;
	}
	if(l1%2==1&&param==1){
		l=s1;
		r=s2;
		while(l<=e1){
			if(str1[l]!=str1[r]){flag=1;break;}
			l++;
			r++;
		}
		if(flag==0)return 1;
		else return 0;
	}
	if(check(s1,(s1+e1)/2,s2,(s2+e2)/2,param)==1){
		if(check(s1,(s1+e1)/2,(s2+e2)/2+1,e2,param)==1){
			if(check(s1,(s1+e1)/2,(s1+e1)/2+1,e1,1)==1){
				return 1;
			}
			return 0;
		}
		if(check((s1+e1)/2+1,e1,(s2+e2)/2+1,e2,param)==1){
			return 1;
		}
		return 0; 
	}
	if(check(s1,(s1+e1)/2,(s2+e2)/2+1,e2,param)==1)
	{
		if(check((s1+e1)/2+1,e1,s2,(s2+e2)/2,param)==1){
			return 1;
		}
		return 0;
	}
	return 0;
}
int main(){
	ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
	int p,q,r,s,t,flag=0;
	scanf("%s",str1);
	scanf("%s",str2);
	p=strlen(str1);
	if(check(0,p-1,0,p-1,0)) cout<<"YES\n";
	else cout<<"NO\n";
	return 0;		
}