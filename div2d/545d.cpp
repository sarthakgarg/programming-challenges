#include<stdio.h>
#include"iostream"
#include<string.h>
#include<vector>
#include<stack>
#include<queue>
#include<map>
#include<set>
#include<algorithm>
#define N 100006
#define X first
#define Y second 
#define REP(i, n) for(int i = 0; i < n; i++)
#define REPP(i, a, b) for(int i = a; i < b; i++)
#define foreach(gg, itit) for(auto itit = gg.begin(); itit != gg.end(); itit++)
using namespace std;
typedef long long ll;
typedef pair<int, int> pi;
int n, a[N], ans;
ll sum;
int main(){
    cin >> n;
    REP(i, n) cin >> a[i];
    sort(a, a + n);
    REP(i, n){
        if(sum <= a[i]){
            ans++;
            sum += a[i];
        }
    }
    cout << ans << "\n";
    return 0;
}