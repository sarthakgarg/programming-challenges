//this is code for hashing all the substrings of a string. Time complexity is O(n^2)
#include<stdio.h>
#include"iostream"
#include<stdlib.h>
#include<string.h>
#include<unordered_set>
#define B 957123577
#define M 1025434309
#define REP(i, n) for(int i=0;i<n;i++)
#define REPP(i, a, b) for(int i=a;i<b;i++)
using namespace std;
typedef long long ll;
unordered_set<int> strs[2012];
char str[2010], beg[2010], en[2010];
int hsh[2010][2010], n, m, s;
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
int str_hash(char a[], int len) {
	int hp = 0;
	REP(i, len) {hp = imod(1LL * hp * B); hp = imod(hp + a[i]);}
	return hp;
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
	cin >> str >> beg >> en;
	int ha, hb, la[2010], lb[2010], pointa = 0, pointb = 0;
	n = strlen(str); m = strlen(beg); s = strlen(en);
	REPP(i, 1, n + 1) hashing(i);
	ha = str_hash(beg, m); hb = str_hash(en, s);
	REP(i, n)REPP(j, i, n) {
		if (hsh[i][j] == ha && j - i + 1 == m) {la[pointa] = j; pointa++;}
		if (hsh[i][j] == hb && j - i + 1 == s) {lb[pointb] = j; pointb++;}
	}
	REP(i, pointa)REP(j, pointb) {
		if (la[i] <= lb[j] && la[i] - m <= lb[j] - s) strs[lb[j] - la[i] + m].insert(hsh[la[i] - m + 1][lb[j]]);
	}
	int sum = 0;
	REPP(i, 0, 2001) sum += strs[i].size();
	cout << sum << "\n";
	return 0;
}