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
int min(int a, int b){return (a > b) ? b : a;}
ll d, k, a, b, t;
ll tim, tim2;
int main(){
    cin >> d >> k >> a >> b >> t;
    if(d % k == 0) tim = (d / k - 1) * (a * k + t) + a * k;
    else tim = (d / k) * (a * k + t) + (d % k) * a;
    tim = min(tim, (k >= d) ? (a * d) : (a * k + b * (d - k)));
    
    if(d % k == 0) tim2 = (d / k - 1) * (a * k + t) + b * k - t;
    else tim2 = (d / k) * (a * k + t) + (d % k) * b - t;    
    cout << min(tim, tim2) << "\n";
    return 0;
}