#include<stdio.h>
#include"iostream"
#include<string.h>
#include<vector>
#include<stack>
#include<queue>
#include<map>
#include<set>
#include<algorithm>
#define N 300005
#define mod 1000000007
#define X first
#define Y second 
#define INF 1000000007
#define REP(i, n) for(int i = 0; i < n; i++)
#define REPP(i, a, b) for(int i = a; i < b; i++)
#define foreach(gg, itit) for(auto itit = gg.begin(); itit != gg.end(); itit++)
using namespace std;
typedef long long ll;
int max(int a, int b){return (a > b) ? a : b;}
int n, mn = -INF, x, ct, prv = -INF;
int main(){
    cin >> n;
    REP(i, n){
        cin >> x;
        if(x > prv){
            ct++;
            mn = max(mn, ct);
        }
        else{
            ct = 1;
            mn = max(mn, ct);
        }
        prv = x;
    }
    cout << mn << "\n";
    return 0;
}