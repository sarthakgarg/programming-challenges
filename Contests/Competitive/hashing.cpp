//this is code for hashing all the substrings of a string. Time complexity is O(n^2)
#include<stdio.h>
#include"iostream"
#include<stdlib.h>
#include<string.h>
#define B 957123577
#define M 1025434309
#define REP(i, n) for(int i=0;i<n;i++)
#define REPP(i, a, b) for(int i=a;i<b;i++)
using namespace std;
typedef long long ll;
char str[2000];
int hsh[2000][2000], n;
int imod(ll a) {
	int b = a % M;
	if (b < 0) b += M;
	return b;
}
int modexp(int power) {
	if (!power) return 1;
	ll x = modexp(power / 2);
	x = (x * x) % M;
	if (power % 2) x = (x * B) % M;
	return x;
}
void hashing(int len) {
	int hp = 0;
	int e = modexp(len - 1);
	REP(i, len) {hp = imod(1LL * hp * B); hp = imod(hp + str[i]);}
	hsh[0][len - 1] = hp;
	REP(i, n - len) {hp = imod(hp - 1LL * str[i] * e); hp = imod(1LL * hp * B); hp = imod(hp + str[i + len]); hsh[i + 1][i + len] = hp;}
	return;
}
int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	cin >> str;
	n = strlen(str);
	REPP(i, 1, n + 1) hashing(i);
	REP(i, n) {REP(j, n) cout << hsh[i][j] << " "; cout << "\n";} //for seeing the hashed values
	return 0;
}