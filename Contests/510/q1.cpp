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
#define REP(i, n) for(int i = 0; i < n; i++)
#define REPP(i, a, b) for(int i = a; i < b; i++)
#define foreach(gg, itit) for(auto itit = gg.begin(); itit != gg.end(); itit++)
#define X first
#define Y second
#define mod 1000000007
#define MAXN 1000005
#define MAXALPHA 27
using namespace std;
typedef pair<int, int> ii;
typedef long long ll;
typedef unsigned long long ull;
int main(){
	int n, m;
	cin >> n >> m;
	for(int i = 0; i < n; i++){
		if(i % 2 == 0){
			for(int j = 0; j < m; j++){
				cout << "#";
			}
		}
		else{
			if(i % 4 == 1){
				for(int j = 0; j < m - 1; j++) cout << ".";
				cout << "#";
			}
			else{
				cout << "#";
				for(int j = 1; j < m; j++) cout << ".";
			}
		}
		cout << "\n";
	}
	return 0;
}