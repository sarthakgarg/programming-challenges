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
//#include<algorithm.h>
#define REP(i, n) for(int i = 0; i < n; i++)
#define REPP(i, a, b) for(int i = a; i < b; i++)
#define foreach(gg, itit) for(auto itit = gg.begin(); itit != gg.end(); itit++)
#define X first
#define Y second
#define MAXN 1000005
#define MAXALPHA 27
using namespace std;
typedef pair<int, int> ii;
typedef long long ll;
int main(){
	int n;
	cin >> n;
	if(n % 2 != 0) cout << "0\n";
	else{
		n /= 2;
		if(n < 3) cout << "0\n";
		else {
			if(n % 2 == 1) cout << (n - 1)/2 << "\n";
			else cout << (n - 2)/2 << "\n";
		}
	}
	return 0;
}