#include<stdio.h>
#include"iostream"
#include<string.h>
#include<vector>
#include<stack>
#include<queue>
#include<map>
#include<set>
#include<algorithm>
#include<unordered_map>
#define N 10
#define M 29
#define mod 1000000007
#define X first
#define Y second
#define INF 100000000000000007
#define REP(i, n) for(int i = 0; i < n; i++)
#define REPP(i, a, b) for(int i = a; i < b; i++)
#define foreach(gg, itit) for(auto itit = gg.begin(); itit != gg.end(); itit++)
using namespace std;
typedef long long ll;
vector<int> lis;
int n, x, q, y, t;
int main(){
    cin >> n;
    REP(i, n){
        cin >> x;
        lis.push_back(x);
    }
    sort(lis.begin(), lis.end());
    cin >> q;
    REP(i, q){
        cin >> y;
        auto it = upper_bound(lis.begin(), lis.end(), y);
        cout << (int)(it - lis.begin()) << "\n";
    }
    return 0;
}