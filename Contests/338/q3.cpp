#include<stdio.h>
#include"iostream"
#include<string.h>
#include<vector>
#define N 3001
#define X first
#define Y second
using namespace std;
typedef long long ll;
char s[N], t[N];
ll n, m, eq[N][N], req[N][N], mx, mn, ct, ans;
vector<pair<int, int> > lis;
int main(){
	cin >> s >> t;
	n = strlen(s);
	m = strlen(t);
	for(int i = n - 1; i >= 0; i--){
		for(int j = m - 1; j >= 0; j--){
			ll add = (i == n - 1 || j == m - 1) ? (0) : eq[i + 1][j + 1];
			if(s[i] == t[j]) eq[i][j] = add + 1;
			else eq[i][j] = 0;
		}
	}
/*	for(int i = 0; i < n; i++){
		for(int j = 0; j < m; j++){
			cout << eq[i][j] << " ";
		}
		cout << "\n";
	}*/
	for(int i = 0; i < n / 2; i++) swap(s[i], s[n - 1 - i]);

	for(int i = n - 1; i >= 0; i--){
		for(int j = m - 1; j >= 0; j--){
			ll add = (i == n - 1 || j == m - 1) ? (0) : req[i + 1][j + 1];
			if(s[i] == t[j]) req[i][j] = add + 1;
			else req[i][j] = 0;
		}
	}
/*	for(int i = 0; i < n; i++){
		for(int j = 0; j < m; j++){
			cout << req[i][j] << " ";
		}
		cout << "\n";
	}	*/
	for(int i = 0; i < m; ){
		mx = 0;
		int st, ed;
		for(int j = 0; j < n; j++){
			if(mx < eq[j][i]) {
				mx = eq[j][i];
				st = j + 1;
				ed = j + mx;
			}
		}
		for(int j = 0; j < n; j++){
			if(mx < req[j][i]){
				mx = req[j][i];
				st = n - j;
				ed = n - j - mx + 1;
			}
		}
		if(mx == 0){
			cout << "-1\n";
			return 0;
		}
		else{
			ct++;
			lis.push_back(pair<int, int> (st, ed));
			i += mx;
		}
	}
	cout << ct << "\n";
	for(auto it = lis.begin(); it != lis.end(); it++) cout << it->X << " " << it->Y << "\n";
	return 0;
}