#include<stdio.h>
#include"iostream"
#include<vector>
#include<map>
#include<algorithm>
#define X first
#define Y second
#define N 200005
using namespace std;
typedef long long ll;
int arr[N], n, m, t[N], r, lt, rt, an[N];
typedef pair<int, int> ii;
vector<ii> emp;
int main(){
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	cin >> n >> m;
	for(int i = 0; i < n; i++){
		cin >> arr[i];
	}
	

	lt = 0;
	rt = n - 1;
	for(int i = 0; i < m; i++){
		cin >> t[i] >> r;
		r--;
		emp.push_back(ii(r, i));
	}
	t[m] = 1;
	emp.push_back(ii(0, m));
	int sz = emp.size();
	sort(emp.begin(), emp.end());
	int prv = -1;
	int tprv;
	int trn;
	int ct = n - 1;
	for(int k = sz - 1; k >= 0; k--){
		int rn = emp[k].X;
		int ind = emp[k].Y;
		if(prv == -1){
			for(int i = n - 1; i > rn; i--) {an[ct] = arr[i]; ct--;}
			sort(arr, arr + rn + 1);
			prv = ind;
			tprv = t[ind];
			trn = rn;
			rt = rn;
		}
		else{
			if(ind > prv){
				int sh = trn - rn;
				if(tprv == 1){
					while(sh){
						an[ct] = arr[rt];
						rt--;
						sh--;
						ct--;
					}
				}
				else{
					while(sh){
						an[ct] = arr[lt];
						lt++;
						ct--;
						sh--;
					}
				}
				prv = ind;
				tprv = t[ind];
				trn = rn;
			}
		}
	}
	an[ct] = arr[lt];
	for(int i = 0; i < n; i++) cout << an[i] <<"Case : \n";
	cout << "\n";
	return 0;
}
