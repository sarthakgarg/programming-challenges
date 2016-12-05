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
#define N 105
#define M 150000
#define mod 10000007
#define X first
#define Y second 
#define INF 1000000000000000007
#define REP(i, n) for(int i = 0; i < n; i++)
#define REPP(i, a, b) for(int i = a; i < b; i++)
#define foreach(gg, itit) for(auto itit = gg.begin(); itit != gg.end(); itit++)
using namespace std;
typedef long long ll;
char str[12];
int prv, aft, flg, n;
int main(){
    cin >> n;
    REP(i, n){
        cin >> str >> prv >> aft;
        if(prv >= 2400 && aft > prv) flg = 1;
    }
    if(flg) cout << "YES\n";
    else cout << "NO\n";
    return 0;
}