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
ll n, c, ans, tim, prv = -1;
int main(){
    cin >> n >> c;
    REP(i, n){
        cin >> tim;
        if(prv != -1 && tim - prv > c) ans = 1;
        else ans++;
        prv = tim;
    }
    cout << ans << "\n";
}