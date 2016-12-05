#include<stdio.h>
#include"iostream"
#include<string.h>
using namespace std;
typedef long long ll;
#define REP(i,n) for(int i=0;i<n;i++)
#define REPP(i,a,b) for(int i=a;i<b;i++)
#define INF 10000000
int dp[504][504],chg[504][504],n,k,p,x,y,l,r,ct,prv[504][504];
char str[504];
void print(int index,int sum){
	if(index==0) return;
	print(prv[index][sum],sum-1);
	int l=prv[index][sum],r=index-1;
	while(l<=r){if(str[l]!=str[r])str[r]=str[l];l++;r--;}
	REPP(i,prv[index][sum],index)cout<<str[i];
	if(index!=n)cout<<"+";
	return;
}
int main(){
	ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
	cin>>str>>k;
	n=strlen(str);
	REP(i,n){
		x=i;y=0;ct=0;
		while(x-y>=0&&x+y<n){if(str[x+y]!=str[x-y])ct++;chg[x-y][x+y]=ct;y++;}
		x=i;y=0;ct=0;
		while(x-y>=0&&x+y+1<n){if(str[x+y+1]!=str[x-y])ct++;chg[x-y][x+y+1]=ct;y++;}
	}
	REP(i,504)REP(j,504)dp[i][j]=INF;
	dp[0][0]=0;
	REP(i,n){
		REP(j,k){
			REPP(r,i,n){
				if(dp[r+1][j+1]>dp[i][j]+chg[i][r]){
					prv[r+1][j+1]=i;
					dp[r+1][j+1]=dp[i][j]+chg[i][r];
				}
			}
		}
	}
	ct=INF;
	REPP(i,1,k+1){if(ct>dp[n][i]){ct=dp[n][i];x=i;}}
	cout<<ct<<"\n";
	print(n,x);
	cout<<"\n";
	return 0;
}