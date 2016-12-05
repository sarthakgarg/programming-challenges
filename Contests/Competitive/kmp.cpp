//this is the code for Knuth-Morris-Pratt matching algorithm. Time complexity is O(n+m)
#include<stdio.h>
#include"iostream"
#include<stdlib.h>
#include<string.h>
#define REP(i,n) for(int i=0;i<n;i++)
#define REPP(i,a,b) for(int i=a;i<b;i++)
using namespace std;
char ch, str[100], pat[100];
int t[102], n, m, s;
void build() {
	int l, mx;
	t[0] = -1;
	REP(i, m) {
		mx = 0; l = t[i]; while (l != -1) {if (pat[l] == pat[i])mx = max(mx, l + 1); l = t[l];}
		t[i + 1] = mx;
	}
	return;
}
void match() {
	int l = 0, mx;
	REP(i, n) {
		if (l != m && str[i] == pat[l])l++;
		else {
			mx = 0; while (l != -1) {if (pat[l] == str[i])mx = max(mx, l + 1); l = t[l];}
			l = mx;
		}
		if (l == m) {cout << "Match found at " << i + 1 << "th position\n";}
	}
	return ;
}
int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	cin >> str >> pat; n = strlen(str); m = strlen(pat);
	build();
	match();
	return 0;
}