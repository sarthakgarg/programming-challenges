#include<stdio.h>
#include"iostream"
#include<string.h>
#include<vector>
#include<stack>
#include<queue>
#include<map>
#include<set>
#include<algorithm>
#define N 100005
#define mod 1000000007
#define X first
#define Y second
#define INF 1000000007
#define REP(i, n) for(int i = 0; i < n; i++)
#define REPP(i, a, b) for(int i = a; i < b; i++)
#define foreach(gg, itit) for(auto itit = gg.begin(); itit != gg.end(); itit++)
using namespace std;
typedef long long ll;
ll n, k, ans, sum, c[N], s[N], x, y, ssum, sq, sub;
int main(){
    cin >> n >> k;
    REP(i, n) {
        cin >> c[i];
        sum += c[i];
    }
    REP(i, k){
        cin >> x;
        s[x - 1] = 1;
        ssum += c[x - 1];
        sq += c[x - 1] * c[x - 1];
        ans += c[x - 1] * (sum - c[x - 1]);
    }
    sub = (ssum * ssum - sq) / 2;
    ans -= sub;
    REP(i, n){
        if(s[i] == 0 && s[(i + 1) % n] == 0) ans += c[i] * c[(i + 1) % n];
    }
    cout << ans << "\n";
    return 0;
}