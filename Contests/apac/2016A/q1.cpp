#include<stdio.h>
#include"iostream"
#include<string.h>
#include<vector>
#include<stack>
#include<queue>
#include<map>
#include<set>
#include<algorithm>
#define N 504
#define mod 1000000007
#define X first
#define Y second
#define INF 1000000000007
#define REP(i, n) for(int i = 0; i < n; i++)
#define REPP(i, a, b) for(int i = a; i < b; i++)
#define foreach(gg, itit) for(auto itit = gg.begin(); itit != gg.end(); itit++)
using namespace std;
typedef long long ll;
ll t, k, x, y;
ll swit(ll a){
    return (a == 1) ? 0 : 1;
}
ll find(ll a, ll b){
    if(2 * a  - 1 == b) return 0;
    else if(2 * a - 1 < b) return find(a, (b - 1)/ 2);
    else return swit(find(b - a + 1, (b - 1)/2)); 
}
int main(){
    cin >> t;
    REPP(i, 1, t + 1){
        cin >> k;
        x = 0;
        while(x < 2 * k - 1){
            x = 1 + 2 * x;
        }
         cout << "Case #" << i << ": " << find(k, x) << "\n";
    }
}