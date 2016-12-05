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
#define N 1000005
#define M 1000005
#define mod 1000000007
#define X first
#define Y second
#define INF 100000000000007
#define REP(i, n) for(int i = 0; i < n; i++)
#define REPP(i, a, b) for(int i = a; i < b; i++)
#define foreach(gg, itit) for(auto itit = gg.begin(); itit != gg.end(); itit++)
using namespace std;
typedef long long ll;
int n, m, a[N], t[N], li, ri, ans[M];
typedef pair<int, int> ii;
typedef pair<ii, int> iii;
vector<iii> lis;
vector<ii> seq;
int read(int idx){
    int sum = 0;
    while (idx > 0){
        sum ^= t[idx];
        idx -= (idx & -idx);
    }
    return sum;
}
void update(int idx ,int val){
    while (idx <= N - 2){
        t[idx] ^= val;
        idx += (idx & -idx);
    }
}
int main(){
    int n;
    cin >> n;
    REP(i, n) {
        scanf("%d", &a[i + 1]);
        seq.push_back(ii(a[i + 1], i + 1));
    }
    a[0] = 0;
    n++;
    cin >> m;
    REP(i, m){
        scanf("%d%d", &li, &ri);
        lis.push_back(iii(ii(ri, li), i));
    }
    sort(lis.begin(), lis.end());
    sort(seq.begin(), seq.end());
    int st = 0;
    foreach(lis, it){
        int lft = (*it).X.Y;
        int rgt = (*it).X.X;
        int idx = (*it).Y;
        while(st < rgt){
            st++;
            auto it = lower_bound(seq.begin(), seq.end(), ii(a[st], st));
            if(it -> X == (it - 1) -> X) update((it - 1) -> Y, a[st]);
        }
        ans[idx] = read(rgt) ^ read(lft - 1);
    }
    REP(i, m) printf("%d\n", ans[i]);
    return 0;
}
