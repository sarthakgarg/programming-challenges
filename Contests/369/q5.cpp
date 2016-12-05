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
#define N 200005
#define M 150000
#define mod 1000003
#define X first
#define Y second 
#define INF 1000000000007
#define REP(i, n) for(int i = 0; i < n; i++)
#define REPP(i, a, b) for(int i = a; i < b; i++)
#define foreach(gg, itit) for(auto itit = gg.begin(); itit != gg.end(); itit++)
using namespace std;
typedef long long ll;
ll modexp(ll a, ll p){
    if(p == 0) return 1 % mod;
    ll x = modexp(a, p / 2);
    x = (x * x) % mod;
    if(p % 2) x = (x * a) % mod;
    return x;
}
ll n, k, B, A;
int main(){
    cin >> n >> k;
    ll chk = 1, flg = 0;
    REP(i, n){
        chk *= 2;
        if(chk >= k){
            flg = 1;
            break;
        }
    }
    if(flg == 0){
        cout << "1 1\n";
        return 0;
    }
    ll dp = ((n % (mod - 1)) * ((k - 1) % (mod - 1))) % (mod - 1), np = 0, ct = 2;
    while(k - 1 >= ct){
        np += ((k - 1) / ct);
        ct *= 2;
    }
    np = np % (mod - 1);
    B = modexp(2, (dp - np + mod - 1) % (mod - 1));
    if(k >= mod) A = 0;
    else{
        A = 1;
        REPP(j, 1, k) A = (A * ((modexp(2, n % (mod - 1)) - j % mod + mod) % mod)) % mod;
    }
    A = (A * modexp(2, (np * (mod - 2)) % (mod - 1))) % mod;
    A = (B - A + mod) % mod;
    cout << A << " " << B << "\n";
    return 0;
}