#include<stdio.h>
#include"iostream"
#include<string.h>
#include<vector>
#include<stack>
#include<queue>
#include<map>
#include<set>
#include<algorithm>
#define N 200005
#define mod 1000000007
#define X first
#define Y second 
#define INF 1000000000007
#define REP(i, n) for(int i = 0; i < n; i++)
#define REPP(i, a, b) for(int i = a; i < b; i++)
#define foreach(gg, itit) for(auto itit = gg.begin(); itit != gg.end(); itit++)
using namespace std;
typedef long long ll;
int n, m, a[1003][1003], rsum[1003][1003], csum[1003][1003];
int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    cin >> n >> m;
    REPP(i, 1, n + 1){
        int r = 0;
        REPP(j, 1, m + 1){
            cin >> a[i][j];
            r += a[i][j];
            rsum[i][j] = r;
        }
    }
    REPP(j, 1, m + 1){
        int c = 0;
        REPP(i, 1, n + 1){
            c += a[i][j];
            csum[i][j] = c;
        }
    }
    int ans = 0;
    REPP(i, 1, n + 1){
        REPP(j, 1, m + 1){
            if(a[i][j] == 0 && rsum[i][j] > 0) ans++;
            if(a[i][j] == 0 && csum[i][j] > 0) ans++;
            if(a[i][j] == 0 && rsum[i][m] - rsum[i][j] > 0) ans++;
            if(a[i][j] == 0 && csum[n][j] - csum[i][j] > 0) ans++;
        }
    }
    cout << ans << "\n";
    return 0;
}