#include<stdio.h>
#include"iostream"
#include<algorithm>
#include<vector>

#define N 2504
#define X first
#define Y second

using namespace std;
typedef long long ll;
typedef pair<int, int> ii;

vector<ii> l;
int arr[N][N], n, flag, cnt, parent[N * N], sz[N * N];

int f(int i){
	if(parent[i] == i) return i;
	return parent[i] = f(parent[i]);
}

void u(int i, int j){	
	i = f(i);
	j = f(j);
	if(sz[i] <= sz[j]){
		parent[i] = j;
		sz[j] += sz[i];
		sz[i] = 0;
	}
	else{
		parent[j] = i;
		sz[i] += sz[j];
		sz[j] = 0;
	}
}

void upd(int i, int j){
	if(f(i) != f(j)){
		int a = sz[f(i)];
		int b = sz[f(j)];
		cnt = cnt + (a + b) * (a + b - 1) / 2 - a * (a - 1) / 2 - b * (b - 1) / 2;
		u(i, j);
	}
}

int main(){
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	cin >> n;
	for(int i = 0; i < n; i++){
		for(int j = 0; j < n; j++){
			cin >> arr[i][j];
			if(i == j && arr[i][i] != 0 || i > j && arr[i][j] != arr[j][i]) flag = 1;
			if(i < j) l.push_back(ii(arr[i][j], i * n + j));
		}
	}
	if(flag){
		cout << "NOT MAGIC\n";
		return 0;
	}
	sort(l.begin(), l.end());
	for(int i = 0; i < n * n; i++){
		parent[i] = i;
		sz[i] = 1;
	}
	int prv = -1;
	for(int i = 0; i < n * (n - 1) / 2; i++){
		if(l[i].X != prv){
			prv = l[i].X;
			if(i != cnt){
				flag = 1;
				break;
			}
		}
		upd(l[i].Y / n, l[i].Y % n);
	}
	if(flag) cout << "NOT MAGIC\n";
	else cout << "MAGIC\n";
	return 0;
}
