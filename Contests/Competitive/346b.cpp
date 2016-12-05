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
#define REP(i,a) for(int i=0;i<a;++i)
#define REPP(i,a,b) for(int i=a;i<b;++i)
#define FILL(a,x) memset(a,x,sizeof(a))
int s, l, n, m, dp[105][105][105][5]; // dp[0] contains the length and dp[1] contains the path direction
char str1[105], str2[105], lcs[105], virus[105];
int t[105];
int check(int l, char ch){
	int flag=1;
	while(l!=-1){
		if(ch==virus[l]) flag=0;
		l=t[l];
	}
	return flag;
}
int find(int p, int q, int k,char prev) {
	int a, b, mx, pos;
	if (p < 0 || q < 0) return 0;
	if (dp[p][q][k][0] != -1) return dp[p][q][k][0];
	a = find(p, q - 1, k,prev);b = find(p - 1, q, k,prev);
	if (a > b) {dp[p][q][k][1] = 0; dp[p][q][k][2] = 1;}
	else {a = b; dp[p][q][k][1] = 1; dp[p][q][k][2] = 0;}
	dp[p][q][k][3] = 0;
	if (str1[p] == str2[q] && k != 0 ) {
		if(str1[p]==virus[k-1]){
			b=find(p-1,q-1,k-1,str1[p])+1;
			if(b>a){
				a=b;
				dp[p][q][k][1] = 1; dp[p][q][k][2] = 1; dp[p][q][k][3] = 1; dp[p][q][k][4]=1;
			}
		}
	}
	else if (str1[p] == str2[q] && k == 0) {
		mx = 0;
		pos = 0;
		REPP(j,1,s) if(str1[p]==virus[j-1]&&check(j,prev)){b = find(p - 1, q - 1, j-1, str1[p]); if (b + 1 > mx) {mx = b + 1; pos = j-1;}}
		if(str1[p]!=virus[0]){b=find(p-1,q-1,0,str1[p]);if(b>mx){mx=b+1;pos=0;}}
		if(mx>a){
			dp[p][q][k][1] = 1; dp[p][q][k][2] = 1; dp[p][q][k][3] = pos; dp[p][q][k][4]=1;
			a=mx;
		}	
	}
	dp[p][q][k][0] = a;
	return a;
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
void print(int p, int q, int k) {
	if (p < 0 || q < 0) return;
	int kn;
	if (k == 0) kn = dp[p][q][k][3];
	else kn = k - dp[p][q][k][3];
	print(p - dp[p][q][k][1], q - dp[p][q][k][2], kn);
	if (dp[p][q][k][4] == 1) cout << str1[p];
}
int main() {
	int len = 0, com = 0;
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	cin >> str1 >> str2 >> virus;
	FILL(dp, -1);
	n = strlen(str1); m = strlen(str2); s = strlen(virus);
	buildtable();
	REP(i, s) {int l = find(n - 1, m - 1, i, '&'); if (l > len) {len = l; com = i;}}
	cout<<len<<"\n";
	print(n - 1, m - 1, com); 
	cout << "\n";
	return 0;
}