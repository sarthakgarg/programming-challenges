#include<stdio.h>
#include"iostream"
#include<string.h>
#include<vector>
#include<stack>
#include<queue>
#include<map>
#include<string.h>
#include<math.h>
#include<set>
#include<algorithm>
#define N 1000005
#define mod 1000000007
#define X first
#define Y second 
#define INF 1000000000007
#define REP(i, n) for(int i = 0; i < n; i++)
#define REPP(i, a, b) for(int i = a; i < b; i++)
#define foreach(gg, itit) for(auto itit = gg.begin(); itit != gg.end(); itit++)
using namespace std;
typedef long long ll;
ll zz, zo, oz, oo, x, y, z, one[2], zero[2], a[N];
ll fill(ll o, ll z, ll zo, ll oz){
    ll n = o + z;
    if(oz < 0 || zo < 0 || zo + oz != o * z) return 0;
    if(n == 0) return 1;
    if(o > 0 && fill(o - 1, z, zo - z, oz)){
        a[n - 1] = 1;
        return 1;
    }
    if(z > 0 && fill(o, z - 1, zo, oz - o)){
        a[n - 1] = 0;
        return 1;
    }
    return 0;
}
int main(){
    cin >> zz >> zo >> oz >> oo;
    one[0] = (1 + (ll)(sqrt(1.001 + 8 * oo)) / 2;
    one[1] = (1 - (ll)(sqrt(1.001 + 8 * oo)) / 2;
    zero[0] = (1 + (ll)(sqrt(1.001 + 8 * zz)) / 2;
    zero[1] = (1 - (ll)(sqrt(1.001 + 8 * zz)) / 2;   
    REP(i, 2){
        if(one[i] >= 0 && zero[i] >= 0 && oo == (one[i]) * (one[i] - 1) / 2 && zz == zero[i] * (zero[i] - 1) / 2 && fill(one[i], zero[i], zo, oz)){
            REPP(j, one[i] + zero[i]) cout << a[i];
            cout << "\n";
            return 0;
        }
    }
    cout << "Impossible\n";
    return 0;
}