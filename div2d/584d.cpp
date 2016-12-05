//coding basic sieve and prime checking functions. Using Goldbacs conjecture
#include<stdio.h>
#include"iostream"
#include<string.h>
#include<vector>
#include<stack>
#include<queue>
#include<map>
#include<set>
#include<algorithm>
#define N 1000
#define mod 1000000007
#define X first
#define Y second 
#define REP(i, n) for(int i = 0; i < n; i++)
#define REPP(i, a, b) for(int i = a; i < b; i++)
#define foreach(gg, itit) for(auto itit = gg.begin(); itit != gg.end(); itit++)
using namespace std;
typedef long long ll;
typedef pair<int, int> pi;
int check(int x){
    for(int i = 2; i * i <= x; i++){
        if(x % i == 0) return 0;
    }
    return 1;
}
int n, ct, ans[3], t, seive[N], primes[N], sz;
int main(){
    cin >> n;
    t = n;
    while(check(t) != 1) t--;
    n -= t;
    if(n == 0){ 
        cout << "1\n" << t << "\n";
        return 0;
    }
    for(int i = 2; i * i < N; i++) if(seive[i] == 0) for(int j = 2 * i ; j < N; j += i) seive[j] = 1;
    REPP(i, 2, N) if(seive[i] == 0) primes[sz++] = i;
    REP(i, sz) {
        if(primes[i] == n){
            cout << "2\n" << t << " " << primes[i] << "\n";
            return 0;
        }
    }
    REP(i, sz){
        REP(j, sz){
            if(primes[i] + primes[j] == n){
                cout << "3\n" << t << " " << primes[i] << " " << primes[j] << "\n";
                return 0;
            }
        }
    }
}