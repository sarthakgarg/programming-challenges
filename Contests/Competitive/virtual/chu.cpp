// before starting a dp question ask yourself whether it is possible to do it incrementally or not 
#include<stdio.h>
#include"iostream"
using namespace std;
typedef long long ll;
#define REP(i,n) for(int i=0;i<n;i++)
#define REPP(i,a,b) for(int i=a;i<b;i++)
#define INF 10000000
int dp[504][504],chg[504][504],n,k,p,x,y,l,r,ct;
char str[504];
int main(){
	ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
	cin>>str>>k;
	n=strlen(str);
	//fill the change array 
	REP(i,0,n){
		x=i;
		y=0;
		ct=0;
		while(x-y>=0&&x+y<n){if(str[x+y]!=str[x-y])ct++;chg[x-y][x+y]=ct;y++;}
		x=i;y=0;ct=0;
		while(x-y>=0&&x+y+1<n){if(str[x+y+1]!=str[x-y])ct++;chg[x-y][x+y+1]=ct;y++;}
	}
	//now apply the incremental dp 
	REP(i,504)REP(j,504)dp[i][j]=INF;
	dp[0][0]=0;
	REP(i,n){
		REP(j,k){
			//we are at ith index and till now have done j palindromes
			REPP(r,i,n){dp[r+1][j+1]=min(dp[r+1][j+1],dp[i][j]+chg[i][r]);}
			// updated the dp array , noe chaeck for dp[n][1....k]
		}
	}
	ct=INF;
	REPP(i,1,k+1)ct=min(ct,dp[n][i]);
	cout<<ct<<"\n";
	return 0;
}