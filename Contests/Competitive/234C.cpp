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
//#include<unordered_map>
//#include<unordered_set>
#include<stack>
#include<queue>
#include<deque>
using namespace std;
int tp[100007], tn[100005];
void updaten(int idx, int val) {
	while (idx < 100005) {
		tn[idx] += val;
		idx += (idx & -idx);	
	}
	return;
}
int queryn(int idx) {
	int sum = 0;
	while (idx > 0) {
		sum += tn[idx];
		idx -= (idx & -idx);
	}
	return sum;
}
void updatep(int idx, int val) {
	while (idx < 100005) {
		tp[idx] += val;
		idx += (idx & -idx);
	}
	return;
}
int queryp(int idx) {
	int sum = 0;
	while (idx > 0) {
		sum += tp[idx];
		idx -= (idx & -idx);
	}
	return sum;
}		

int main() {
//	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int p, q, r, n, flag = 0;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> p;
		if (p == 0) flag++;
		else if (p < 0) updaten(i + 1, 1);
			else if (p > 0) updatep(i + 1, 1);
	}
	r = 10000000;
	for (int i = 0; i < n - 1; i++) {
		r = min(r, queryp(i + 1) + queryn(n) - queryn(i+1));
	}
	cout << flag + r << "\n";
	return 0;
}