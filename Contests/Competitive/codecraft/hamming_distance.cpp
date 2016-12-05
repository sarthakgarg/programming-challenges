#include <iostream>
#include <vector>
#include <cmath>
#define INF 1000000007
#define N 300005
using namespace std;

const double eps = 1e-10;

typedef vector<int> VI;
typedef double T;
typedef vector<T> VT;
typedef vector<VT> VVT;

T GaussJordan(VVT &a, VVT &b) {
	const int n = a.size();
	const int m = b[0].size();
	VI irow(n), icol(n), ipiv(n);
	T det = 1;

	for (int i = 0; i < n; i++) {
		int pj = -1, pk = -1;
		for (int j = 0; j < n; j++) if (!ipiv[j])
		for (int k = 0; k < n; k++) if (!ipiv[k])
		if (pj == -1 || fabs(a[j][k]) > fabs(a[pj][pk])) { pj = j; pk = k; }
		if (fabs(a[pj][pk]) < eps) { cerr << "Matrix is singular." << endl; exit(0); }
		ipiv[pk]++;
		swap(a[pj], a[pk]);
		swap(b[pj], b[pk]);
		if (pj != pk) det *= -1;
		irow[i] = pj;
		icol[i] = pk;
		T c = 1.0 / a[pk][pk];
		det *= a[pk][pk];
		a[pk][pk] = 1.0;
		for (int p = 0; p < n; p++) a[pk][p] *= c;
		for (int p = 0; p < m; p++) b[pk][p] *= c;
		for (int p = 0; p < n; p++) if (p != pk) {
			c = a[p][pk];
			a[p][pk] = 0;
			for (int q = 0; q < n; q++) a[p][q] -= a[pk][q] * c;
			for (int q = 0; q < m; q++) b[p][q] -= b[pk][q] * c;		
		}
  	}

	for (int p = n-1; p >= 0; p--) if (irow[p] != icol[p]) {
		for (int k = 0; k < n; k++) swap(a[k][irow[p]], a[k][icol[p]]);
  	}
	return det;
}

int h[4][4], A[6][6], B[6][1];
char str[7][5] = {"aaab", "aaba", "abaa", "baaa", "aabb", "abba", "abab"} ;

double ab(double x){
	if(x < 0) return -x;
	else return x;
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	int cnt = 0;
	for(int i = 0; i <= 3; i++){
		for(int j = 0; j <= 3; j++){
			if(i < j){
				cin >> B[cnt][0];
				for(int k = 0; k < 6; k++){
					if(str[k][i] != str[k][j]) A[cnt][k] = 1;
				}
				cnt++;
			}
		}
	}
	const int n = 6;
	const int m = 1;
	int mx = INF, p;
	VT ans(6);
	for(int i = 0; i < N; i++){
		VVT a(n), b(n);
		for(int j = 0; j < n; j++) {
			a[j] = VT(A[j], A[j] + n);
			b[j] = VT(B[j], B[j] + m);
		}
		b[0][0] -= i;
		b[2][0] -= i;
		b[3][0] -= i;
		b[5][0] -= i;
		double det = GaussJordan(a, b);
		int sum = i, flag = 0;
		for(int j = 0; j < 6; j++){
			if(ab(((int)(b[j][0] + eps)) - b[j][0]) < 5*eps && b[j][0] + eps >= 0){
				sum += (int)(b[j][0] + eps);
			}
			else {
				flag = 1;
				break;
			}
		}
		if(flag == 0){	
			if(sum < mx){
				p = i;
				mx = sum;
				for(int j = 0; j < 6; j++) ans[j] = b[j][0];
			}
		}
	}
	if(mx == INF){
		cout << "-1\n";
		return 0;
	}
	cout << mx << "\n";
	ans.push_back(p);
	char st[4][N];
	int k = 0;
	for(int i = 0; i < 7; i++){
		for(int j = 0; j < ans[i]; j++){
			for(int l = 0; l < 4; l++){
				st[l][k] = str[i][l];
			}
			k++;
		}
	}
	for(int l = 0; l < 4; l++){
		st[l][k] = '\0';
		cout << st[l] << "\n";
	}
	return 0;
}