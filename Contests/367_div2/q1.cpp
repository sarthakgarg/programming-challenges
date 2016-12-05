#include<stdio.h>
#include"iostream"
#include<string.h>
#include<vector>
#include<stack>
#include<queue>
#include<map>
#include<math.h>
#include<set>
#include<algorithm>
#include<unordered_map>
#define N 10
#define M 29
#define mod 1000000007
#define X first
#define Y second
#define INF 1000000007
#define REP(i, n) for(int i = 0; i < n; i++)
#define REPP(i, a, b) for(int i = a; i < b; i++)
#define foreach(gg, itit) for(auto itit = gg.begin(); itit != gg.end(); itit++)
using namespace std;
typedef long long ll;
double a, b, x, y, d, v, t = INF;
int n;
int main(){
    cin >> a >> b >> n;
    while(n--){
        cin >> x >> y >> v;
        t = min(t, sqrt((x - a) * (x - a) + (y - b) * (y - b)) / v);
    }
    printf("%.14lf\n", t);
    return 0;
}