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
#include<cstdio>
using namespace std;
typedef long long ll;
typedef pair<int,int> ii;
#define X first
#define Y second
#define REP(i,a) for(int i=0;i<a;++i)
#define REPP(i,a,b) for(int i=a;i<b;++i)
#define FILL(a,x) memset(a,x,sizeof(a))
#define	foreach( gg,itit )	for(auto itit=gg.begin();itit!=gg.end();itit++ )
#define	mp make_pair
#define	pb push_back
#define sz(a) int((a).size())
#define	debug(ccc)	cout << #ccc << " = " << ccc << endl;
#define present(c,x) ((c).find(x) != (c).end())
#define INF 1e9+7;
const int mod = 1e9+7;
int posp, posa, stp, sta, ina[100006], inp[100006], a, p;
char dira[100006][2], dirp[100006][2];
int main(){
	ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
	cin>>p>>a;
	REP(i,p){cin>>inp[i]>>dirp[i];}
	REP(i,a){cin>>ina[i]>>dira[i];}
	int flag=0;
	sta = 0;
	stp = 0;
	posa=0;
	posp=0;
	int ct=0;
	while(sta<a||stp<p){
		if(ina[sta]==0&&sta==a-1){sta++;}
		else if(ina[sta]==0&&sta!=a){
			sta++;
			ina[sta]--;
			if(dira[sta][0]=='L') posa--;
			else posa++;
		}
		else if(sta!=a){
			ina[sta]--;
			if(dira[sta][0]=='L') posa--;
			else posa++;			
		}

		if(inp[stp]==0&&stp==p-1){stp++;}
		else if(inp[stp]==0&&stp!=p){
			stp++;
			inp[stp]--;
			if(dirp[stp][0]=='L') posp--;
			else posp++;
		}
		else if(stp!=p){
			inp[stp]--;
			if(dirp[stp][0]=='L') posp--;
			else posp++;			
		}		
		if(flag==0){
			if(posa!=posp){flag=1;}
		}
		else{
			if(posa==posp){flag=0;ct++;}
		}
	}
	cout<<ct<<"\n";
	return 0;
}