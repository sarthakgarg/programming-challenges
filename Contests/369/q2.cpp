#include"iostream"
#include<queue>
#include<map>
#include<string.h>
#include<vector>
#include<stack>
#include<stdio.h>
#include<math.h>
#include<set>
#include<algorithm>
#define N 506
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
ll im, jm, sum = 0, n, ar[N][N];
int main(){
    cin >> n;
    REP(i, n){
        REP(j, n){
            cin >> ar[i][j];
            if(ar[i][j] == 0){
                im = i;
                jm = j;
            }
        }
    }
    if(n == 1){
        cout << "1\n";
        return 0;
    }
    if(im != 0) REP(j, n) sum += ar[0][j];
    else REP(j, n) sum += ar[1][j];
    ll temp = 0;
    REP(j, n) temp += ar[im][j];
    if(temp >= sum){
        cout << "-1\n";
        return 0;
    }
    ar[im][jm] = sum - temp;
    REP(i, n){
        ll temp = 0;
        REP(j, n) temp += ar[i][j];
        if(sum != temp){
            cout << "-1\n";
            return 0;
        }
    }
    REP(j, n){
        ll temp = 0;
        REP(i, n) temp += ar[i][j];
        if(sum != temp){
            cout << "-1\n";
            return 0;
        }
    }
    temp = 0;
    REP(k, n) temp += ar[k][k];
    if(sum != temp){
        cout << "-1\n";
        return 0;
    }
    temp = 0;
    REP(k, n) temp += ar[k][n - 1 - k];
    if(sum != temp){
        cout << "-1\n";
        return 0;
    }
    cout << ar[im][jm] << "\n";
    return 0;
}
