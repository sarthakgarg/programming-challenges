#include<stdio.h>
#include"iostream"
#include<stdlib.h>
#include<algorithm>
#include<math.h>
#include<vector>
#define X first
#define Y second
#define N 1003
using namespace std;
typedef long long ll;
ll x, y, n, m, k, t, p, fl;
typedef pair<int, int> ii;
vector<ii> vi;
int sq[N][N];
int main(){
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	cin >> n >> m;
	for(int i = 0; i < N; i++) for(int j = 0; j < N; j++) sq[i][j] = -1;
	int** a = (int**) calloc(n, sizeof(int *));
	for(int i = 0; i < n; i++) a[i] = (int*) calloc(m, sizeof(int));
	for(int i = 0; i < n; i++) for(int j = 0; j < m; j++) cin >> a[i][j];
	if(n < m){
		swap(n, m);
		int** b = (int**) calloc(n, sizeof(int *));
		for(int i = 0; i < n; i++) b[i] = (int*) calloc(m, sizeof(int));
		for(int i = 0; i < n; i++) for(int j = 0; j < m; j++) b[i][j] = a[j][i];
		a = b;
		fl = 1;
		// n > m
	}	
	int** e = (int**) calloc(n, sizeof(int *));
	for(int i = 0; i < n; i++) e[i] = (int*) calloc(m, sizeof(int));
	for(int i = 0; i < n; i++) for(int j = 0; j < m; j++) e[i][j] = 0;
	
	for(int i = 0; i < n; i++) for(int j = 0; j < m; j++) vi.push_back(ii(a[i][j], i * m + j));
	sort(vi.begin(), vi.end());
	
	int bl = (int)sqrt(n + 1) + 1;
	
	for(int i = 0; i < vi.size(); i++){
		int val = vi[i].X;
		int row = vi[i].Y / m;
		int col = vi[i].Y % m;
		int mx = 0, pos = 0, rval, lval;
		for(int j = 0; j < m; j++){
			if(mx < e[row][j] || mx == e[row][j] && a[row][j] > a[row][pos]){
				mx = e[row][j];
				pos = j;
			}
		}
		if(mx == 0) rval = 1;
		else {
			if(val == a[row][pos]) rval = e[row][pos];
			else rval = e[row][pos] + 1;
		}
		int bno = n / bl;
		int bpos = row / bl;
		mx = 0;
		for(int j = 0; j <= bno; j++){
			if(sq[j][col] == -1) continue;
			if(e[sq[j][col]][col] > mx || e[sq[j][col]][col] == mx && a[sq[j][col]][col] > a[pos][col]){
				mx = e[sq[j][col]][col];
				pos = sq[j][col];
			}
		}
		if(mx == 0) lval = 1;
		else {
			if(val == a[pos][col]) lval = e[pos][col];
			else lval = e[pos][col] + 1;
		} 
		e[row][col] = max(rval, lval);
		if(sq[bpos][col] == -1) sq[bpos][col] = row;
		else {
			if(e[sq[bpos][col]][col] == e[row][col] && a[row][col] > a[sq[bpos][col]][col]) sq[bpos][col] = row;
			else if(e[sq[bpos][col]][col] < e[row][col]) sq[bpos][col] = row;
		}
	}
	if(fl == 1){
		for(int i = 0; i < m; i++){
			for(int j = 0; j < n; j++){
				cout << e[j][i] << " ";
			}
			cout << "\n";
		}
	}
	else{
		for(int i = 0; i < n; i++){
			for(int j = 0; j < m; j++) cout << e[i][j] << " ";
			cout << "\n";
		}
	}
	return 0;
}