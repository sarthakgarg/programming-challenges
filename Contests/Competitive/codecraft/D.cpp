#include<stdio.h>
#include"iostream"
#include<vector>
#include<map>
#define N 200004
#include<string.h>
#define REP(i,n) for(int i=0;i<n;i++)
#define REPP(i,a,b) for(int i=a;i<b;i++)
using namespace std;
typedef long long ll;
ll no, mo, xa[N], xb[N], cnt, st, en;
char ina[N], inb[N], cst, cen;
int t[N], n, m, s;
void build() {
	int l, mx;
	t[0] = -1;
	REP(i, m) {
		mx = 0; l = t[i]; while (l != -1) {if (inb[l] == inb[i] && xb[l] == xb[i])mx = max(mx, l + 1); l = t[l];}
		t[i + 1] = mx;
	}
	return;
}
void match() {
	int l = 0, mx;
	REP(i, n) {
		if (l != m && ina[i] == inb[l] && xa[i] == xb[l])l++;
		else {
			mx = 0; while (l != -1) {if (inb[l] == ina[i] && xb[l] == xa[i])mx = max(mx, l + 1); l = t[l];}
			l = mx;
		}
		if (l == m) {
			if(i > 0 && ina[i - 1] == cst && xa[i - 1] >= st && i < n - 1 && ina[i + 1] == cen && xa[i + 1] >= en)
				cnt++;
			if(cnt > 10000 && m > 10000) cout << "bingo";
		}
	}
	return ;
}
int main(){
	cin >> no >> mo;
	for(int i = 0; i < no; i++){
		scanf("%I64d-%c", &xa[i], &ina[i]);
	}
	for(int i = 0; i < mo; i++){
		scanf("%I64d-%c", &xb[i], &inb[i]);
	}
	ll kno = -1;
	char prv = 'A';
	for(int i = 0; i < no; i++){
		if(ina[i] == prv){
			xa[kno] += xa[i];
		}
		else{
			kno++;
			ina[kno] = ina[i];
			xa[kno] = xa[i];
			prv = ina[i];
		}
	}
	ll kmo = -1;
	prv = 'A';
	for(int i = 0; i < mo; i++){
		if(inb[i] == prv){
			xb[kmo] += xb[i];
		}
		else{
			kmo++;
			inb[kmo] = inb[i];
			xb[kmo] = xb[i];
			prv = inb[i];
		}
	}
	n = kno + 1;
	m = kmo + 1;
	if(m > 2){
		st = xb[0];
		en = xb[m - 1];
		cst = inb[0];
		cen = inb[m - 1];	
		for(int i = 1; i < m; i++){
			swap(xb[i], xb[i - 1]);
			swap(inb[i], inb[i - 1]);
		}
		m-=2;
		build();
		if(m > 10000) cout << "done";
		match();
	}
	
	else{
		if(m == 1){
			for(int i = 0; i < n; i++){
				if(ina[i] == inb[0] && xa[i] >= xb[0]) cnt += (xa[i] - xb[0] + 1);
			}
		}
		else{
			for(int i = 0; i < n - 1; i++){
				if(ina[i] == inb[0] && ina[i + 1] == inb[1] && xa[i] >= xb[0] && xa[i + 1] >= xb[1]) cnt++;
			}
		}
	}
	cout << cnt << "\n";
	return 0;
}