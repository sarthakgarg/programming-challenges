#include<stdio.h>
#include"iostream"
#include<string.h>
#include<vector>
#include<stack>
#include<queue>
#include<map>
#include<set>
#include<algorithm>
#include<assert.h>
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
int n, a, b, k, init[N], x[N], prv[N], flg = 0;
int cnt(){
    int c = 0;
    int k = 0;
    REPP(i, 1, n + 1){
        if(x[i] == 0) c++;
        else c = 0;
        if(c == b) {
            k++;
            c = 0;
        }
    }
    return k;
}
int pred(int f){
    REPP(i, 1, n + 1) x[i] = init[i];
    int c = 0;
    int d = 0;
    REPP(i, 1, n + 1){
        if(x[i] == 0) c++;
        else c = 0;
        if(c == b && f > 0){
            x[i] = 1;
            f--;
            c = 0;
        }
        else if(c == b && f == 0) break;
    }

    if(cnt() >= a) return 0;
    else{
        REPP(i, 1, n + 1) prv[i] = x[i];
        flg = 1;
        return 1;
    }
    
}
int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    cin >> n >> a >> b >> k;
    string s;
    cin >> s;
    int i = 1;
    for(char y : s){
        if(y == '1') init[i] = 1;
        i++;
    }
    int lo = 0, hi = n + 1;
    while(lo < hi){
        int mid = lo + (hi - lo) / 2;
        if(pred(mid) == 0) lo = mid + 1;
        else hi = mid;
    }
    cout << lo << "\n";
    REPP(i, 1, n + 1){
        if(prv[i] == 1 && init[i] == 0) cout << i << " ";
    }
    cout << "\n";
    assert(flg == 1);
    return 0;
}