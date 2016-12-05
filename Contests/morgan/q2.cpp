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
#include <unordered_set>
#define N 1000000000002
#define M 100000
#define mod 1000000007
#define X first
#define Y second
#define INF 1000000007
#define REP(i, n) for(int i = 0; i < n; i++)
#define REPP(i, a, b) for(int i = a; i < b; i++)
#define foreach(gg, itit) for(auto itit = gg.begin(); itit != gg.end(); itit++)
using namespace std;
typedef long long ll;
unordered_set<ll> myset;
ll fact[M];
ll ans = 0, ct = 0, n;
int main(){
    cin >> n;
    for(ll i = 1; i * i <= n; i++){
        if(n % i == 0){
            fact[ct++] = i;
            if(i * i != n) fact[ct++] = n / i;
        }
    }
    REP(i, ct){
        REP(j, ct){
            if(fact[i] < (n / fact[j]) && n % (fact[i] * fact[j]) != 0){
                myset.insert(fact[i] * fact[j]);
            }
        }
    }
    cout << myset.size() << "\n";
}