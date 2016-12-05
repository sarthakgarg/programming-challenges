#include <iostream>
#include <vector>
#include <cmath>
#define N 25
using namespace std;

const double EPS = 1e-10;

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
		if (fabs(a[pj][pk]) < EPS) { cerr << "Matrix is singular." << endl; exit(0); }
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
int n, m, h, u, adj[N][N], x, y, ne[N], tn;
double p[N], A[N * N][N * N], B[N * N][N];
int main() {
	
	cin >> n >> m >> h >> u;
	h--;
	u--;
	for(int i = 0; i < m; i++){
		cin >> x >> y;
		x--;
		y--;
		adj[x][y] = adj[y][x] = 1;
		ne[x]++;
		ne[y]++;
	}
	for(int i = 0; i < n; i++) cin >> p[i];
	
	for(int i = 0; i < n; i++){
		for(int j = 0; j < n; j++){
			if(i != j){
				for(int k = 0; k < n; k++){
					for(int l = 0; l < n; l++){
						double p1, p2;
						if(k == i) p1 = p[i];
						else if(adj[k][i] == 1) p1 = (1 - p[i]) / ne[i];
						else p1 = 0;
						if(l == j) p2 = p[j];
						else if(adj[l][j] == 1) p2 = (1 - p[j]) / ne[j];
						else p2 = 0;
						A[i * n + j][k * n + l] = p1 * p2;
					}
				}
				A[i * n + j][i * n + j] -= 1;
			}
			else A[i * n + j][i * n + j] = 1;
		}
	}
	for(int i = 0; i < n; i++) B[i * n + i][i] = 1;
	tn = n;
	n *= n;
	m = n;
		 
	VVT a(n), b(n);
	for (int i = 0; i < n; i++) {
		a[i] = VT(A[i], A[i] + n);
		b[i] = VT(B[i], B[i] + m);
  	}
	double det = GaussJordan(a, b);
	for(int i = 0; i < tn; i++) cout << b[h * tn + u][i] << " ";
	cout << "\n";
	return 0;
}