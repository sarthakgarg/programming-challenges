#include"iostream"
#include<queue>
#include<stdio.h>
#include<vector>
#include<stack>
#include<map>
#include<string.h>
#include<math.h>
#include<set>
#include<algorithm>
#define N 100000
#define M 150000
#define mod 1000000007
#define X first
#define Y second 
#define INF 1000000000007
#define REP(i, n) for(int i = 0; i < n; i++)
#define REPP(i, a, b) for(int i = a; i < b; i++)
#define foreach(gg, itit) for(auto itit = gg.begin(); itit != gg.end(); itit++)
using namespace std;
typedef long long ll;
ll fact, x, y, z, p, n;
int main(){
    cin >> n;
    fact = 2;
    for(ll i = 1; i <= n; i++){
        cout << (i + 1) * (i + 1) * i - fact << "\n";
        fact = i;
    }
    return 0;
}