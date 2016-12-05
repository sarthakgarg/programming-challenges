#include <iostream>
#include <vector>
#include <cmath>
#define N 103
using namespace std;
typedef long long ll;
typedef vector<ll> VI;
typedef vector<ll> VT;
typedef vector<VT> VVT;
ll A[N][N], B[N][1];

ll GaussJordan(VVT &a, VVT &b) {
  const int n = a.size();
  const int m = b[0].size();
  VI irow(n), icol(n), ipiv(n);
  ll det = 1;

  for (int i = 0; i < n; i++) {
    int pj = -1, pk = -1;
    for (int j = 0; j < n; j++) if (!ipiv[j])
      for (int k = 0; k < n; k++) if (!ipiv[k])
	if (pj == -1 || llabs(a[j][k]) > llabs(a[pj][pk])) { pj = j; pk = k; }
    if (llabs(a[pj][pk]) <= 0) { return 0; }
    ipiv[pk]++;
    swap(a[pj], a[pk]);
    swap(b[pj], b[pk]);
    if (pj != pk) det *= -1;
    irow[i] = pj;
    icol[i] = pk;

    ll c = (a[pk][pk]) % 2;
    det = (det * a[pk][pk]) % 2;
    a[pk][pk] = 1;
    for (int p = 0; p < n; p++) a[pk][p] = (a[pk][p] * c) % 2;
    for (int p = 0; p < m; p++) b[pk][p] = (b[pk][p] * c) % 2;
    for (int p = 0; p < n; p++) if (p != pk) {
      c = a[p][pk];
      a[p][pk] = 0;
      for (int q = 0; q < n; q++) a[p][q] -= a[pk][q] * c, a[p][q] %= 2;
      for (int q = 0; q < m; q++) b[p][q] -= b[pk][q] * c, b[p][q] %= 2;
    }
  }

  for (int p = n-1; p >= 0; p--) if (irow[p] != icol[p]) {
    for (int k = 0; k < n; k++) swap(a[k][irow[p]], a[k][icol[p]]);
  }

  return det;
}

int main() {
  int t, n, m, x, y, w;
  cin >> t;
  while(t--){
    cin >> n >> m;
    for(int i = 0; i < n; i++) for(int j = 0; j < n; j++) A[i][j] = 0;
    for(int i = 0; i < m; i++){
      cin >> x >> y >> w;
      x--;
      y--;
      A[x][y] = w % 2;
    }
    m = 1;
    for(int i = 0; i < n; i++) B[i][0] = 1;
    VVT a(n), b(n);
    for (int i = 0; i < n; i++) {
      a[i] = VT(A[i], A[i] + n);
      b[i] = VT(B[i], B[i] + m);
    }

    ll det = GaussJordan(a, b);
    if(det < 0) det = -det;
    cout << ((int)det) % 2<< endl;
  }
}
