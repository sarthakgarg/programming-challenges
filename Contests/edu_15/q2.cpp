#include<stdio.h>
#include"iostream"
#include<string.h>
#include<vector>
#include<stack>
#include<queue>
#include<map>
#include<set>
#include<algorithm>
#define N 100005
#define mod 1000000007
#define X first
#define Y second 
#define INF 2000000007
#define REP(i, n) for(int i = 0; i < n; i++)
#define REPP(i, a, b) for(int i = a; i < b; i++)
#define foreach(gg, itit) for(auto itit = gg.begin(); itit != gg.end(); itit++)
using namespace std;
typedef long long ll;
int max(int a, int b){return (a > b) ? a : b;}
int power[40], n, x, arr[N];
ll ct, pw = 1;
map<int, int> frq;
int main(){
    cin >> n;
    int t = 0;
    while(pw < INF){
        power[t++] = pw;
        pw *= 2;
    }
    REP(i, n){
        cin >> x;
        arr[i] = x;
        frq[x]++;
    }
    REP(i, n){
        REP(j, t){
            if(power[j] - arr[i] != arr[i]) ct += frq[power[j] - arr[i]];
            else ct += frq[power[j] - arr[i]] - 1;
        }
    }
    cout << ct / 2 << "\n";
    return 0;
}