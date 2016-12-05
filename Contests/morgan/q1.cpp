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
#define N 1005
#define M 10000
#define mod 1000000007
#define X first
#define Y second
#define INF 1000000007
#define REP(i, n) for(int i = 0; i < n; i++)
#define REPP(i, a, b) for(int i = a; i < b; i++)
#define foreach(gg, itit) for(auto itit = gg.begin(); itit != gg.end(); itit++)
using namespace std;
typedef long long ll;
typedef pair<int, int> ii;
vector<ii> lis;
int n, d, x;
int main(){
    cin >> n >> d;
    REP(i, n){
        cin >> x;
        lis.push_back(ii(x, i));
    }
    sort(lis.begin(), lis.end());
    REP(i, d){
        cin >> x;
        ii mx = ii(INF, INF);
        foreach(lis, it){
            int s = (*it).X + x;
            int b = (*it).Y;
            auto its = lower_bound(it, lis.end(), ii(s, b + 1));
            if(its != lis.end() && (*its).X == s){
                int e = (*its).Y;
                if(ii(e - b, b) < mx){
                    mx = ii(e - b, b);
                }
            }
        }
        if(mx.X == INF) cout << "-1\n";
        else cout << mx.Y + 1 << " " << mx.Y + mx.X + 1 << "\n";
    }
    return 0;
}