#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> ii;
#define REP(i,a) for(int i=0;i<a;++i)
#define REPP(i,a,b) for(int i=a;i<b;++i)
#define FILL(a,x) memset(a,x,sizeof(a))
int dp[10][10][2], dig[10], len,ans[10],sum[10],arr[10],x=0;
const int mod = 1e9+7;
char num[10];
int find(int n, int k, int status) {
	int a = 0;
	if (k == -1) return 0;
	if (n == len) {if (k == 0) return 1;else return 0;}
	if (dp[n][k][status] != -1) return dp[n][k][status];
	if (status == 0) REP(i, 10) {if (i != 4 && i != 7) a += find(n + 1, k, 0) ; else a += find(n + 1, k - 1, 0);}
	else REP(i, dig[n] + 1) {if (i != 4 && i != 7) a += find(n + 1, k, (i == dig[n]) ? 1 : 0) ; else a += find(n + 1, k - 1, (i == dig[n]) ? 1 : 0);}
	return dp[n][k][status] = a;
}
int modexp(int base,int power){
	if(power==0) return 1;
	int x=modexp(base,power/2);
	x=(1LL*x*x)%mod;
	if(power%2) x=(1LL*x*base)%mod;
	return x;
}
int combine(int n,int r){
	if(n<r) return 0;
	if(n==r||r==0) return 1;
	int x=(1LL*combine(n,r-1)*(n-r+1))%mod;
	x=(1LL*x*modexp(r,mod-2))%mod;
	return x;
}
void count(int arr[],int n,int s,int last){
	if(s>=10) return;
	if(n==6){
		int b=1;
		REP(i,10){b=(1LL*b*combine(ans[i],arr[i]))%mod;}
		b=(1LL*b*720)%mod;
		x+=(1LL*b*(sum[9]-sum[s]))%mod;
		x=x%mod;
		return;
	}
	REPP(i,0,last+1){arr[i]++;count(arr,n+1,s+i,i);arr[i]--;}
	return;
}
int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	FILL(dp, -1);
	cin >> num; len = strlen(num);
	REP(i, len)dig[i] = num[i] - '0';
	ans[0]=find(0,0,1)-1;sum[0]=ans[0];
	REPP(i,1,10){ans[i]=find(0, i, 1);sum[i]=sum[i-1]+ans[i];}
	count(arr,0,0,9);
	cout<<x<<"\n";
	return 0;
}