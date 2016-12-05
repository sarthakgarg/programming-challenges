#include <stdio.h>
#include "iostream"
#include <stack>
#include <queue>
#include <vector>
#include <map>
#include <set>
#include <unordered_map>
#include <unordered_set>
#include<string.h>
#include<algorithm>
#define REP(i, n) for(int i = 0; i < n; i++)
#define REPP(i, a, b) for(int i = a; i < b; i++)
#define foreach(gg, itit) for(auto itit = gg.begin(); itit != gg.end(); itit++)
#define X first
#define Y second
#define mod 1000000007
#define MAXN 1000005
#define MAXALPHA 27
#define N 100005
using namespace std;
typedef pair<int, int> ii;
typedef long long ll;
typedef unsigned long long ull;
ll arr[N], ct, ans, n, m, sm[N], x, y, z;
vector<ll> sid;
int main(){
	cin >> n;
	for(int i = 0; i < n; i++){
		cin >> arr[i];
	}
	sort(arr, arr + n);
	for(int i = n - 1; i > 0; i--){
		if(arr[i] == arr[i - 1]){sid.push_back(arr[i]); i--;}
		else if(arr[i] == arr[i - 1] + 1){sid.push_back(arr[i] - 1); i--;}
	}
	n = sid.size();
	for(int i = 0; i < n - 1; i += 2){
		y += 1LL*sid[i]*sid[i + 1];
	}
	cout << y << "\n";
	return 0;
}